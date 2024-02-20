#include <stdio.h>
#include <sys/socket.h>

#include "globalVariable.h"

void *recv_msg(void *arg)
{
    int sock = *((int *)arg);
    char name_msg[NAME_SIZE + BUF_SIZE];
    int str_len;

    while (1)
    {
        str_len = recv(sock, &name_msg[0], NAME_SIZE + BUF_SIZE - 1, 0);

        if (str_len == -1)
            return (void *)-1;
        name_msg[str_len] = 0;
        fputs(name_msg, stdout);
    }
    return NULL;
}