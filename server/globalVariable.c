#include "globalVariable.h"

pthread_mutex_t mutx;   // 스레드 간에 공유된 자원에 대한 접근을 조정하기 위한 변수
int clnt_cnt;
int clnt_socks[MAX_CLNT];
