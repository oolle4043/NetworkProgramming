#include <stdio.h>
#include <stdlib.h>

void error_hanling(char *msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}