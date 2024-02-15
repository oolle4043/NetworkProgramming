#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H

#include <pthread.h>

#define BUF_SIZE 100
#define NAME_SIZE 20

extern char name[NAME_SIZE];
extern char msg[BUF_SIZE];

#endif