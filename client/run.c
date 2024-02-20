#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#include "send_msg.h"
#include "recv_msg.h"
#include "globalVariable.h"

void run(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;

    pthread_t snd_thread, rcv_thread;
    void *thread_return;

    if (argc != 4)
    {
        printf("Usage: %s <IP> <PORT> <name>\n", argv[0]);
        exit(1);
    }
    sprintf(name, "[%s]", argv[3]);
    
    // 소켓 생성
    if ((sock = socket(PF_INET, SOCK_STREAM, 0)) == -1) { // 소켓 생성 후 오류 처리
        perror("socket() error");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // 서버에 연결
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect() error"); //소켓 연결 오류 처리
        close(sock); //소켓 닫기
        exit(1);
    }

    printf("사용중인 소캣 : %d\n", sock);
    
    // 송신 스레드 생성
    if (pthread_create(&snd_thread, NULL, send_msg, (void *)&sock) != 0) { //스레드 생성 오류 처리
        perror("pthread_create() error");
        close(sock); //소켓 닫기
        exit(1);
    }
    // 수신 스레드 생성
    if (pthread_create(&rcv_thread, NULL, recv_msg, (void *)&sock) != 0) { //스레드 생성 오류 처리
        perror("pthread_create() error");
        close(sock); //소켓 닫기
        exit(1);
    }

    // 스레드 종료 대기
    if (pthread_join(snd_thread, &thread_return) != 0) { //스레드 종료 대기 오류 처리
        perror("pthread_join() error");
        close(sock); //소켓 닫기
        exit(1);
    }
    if (pthread_join(rcv_thread, &thread_return) != 0) { //스레드 종료 대기 오류 처리
        perror("pthread_join() error");
        close(sock); //소켓 닫기
        exit(1);
    }

    close(sock);
}
