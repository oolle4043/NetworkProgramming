#include <pthread.h>
#include <unistd.h>

#include "globalVariable.h"

void send_msg(char *msg, int len)
{
    pthread_mutex_lock(&mutx);

    for (int i = 0; i < clnt_cnt; i++)
        write(clnt_socks[i], msg, len);

    pthread_mutex_unlock(&mutx);
}