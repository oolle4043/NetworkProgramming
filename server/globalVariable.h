#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include <pthread.h>

#define BUF_SIZE 100
#define MAX_CLNT 256

extern pthread_mutex_t mutx;
extern int clnt_cnt;
extern int clnt_socks[MAX_CLNT];

#endif
