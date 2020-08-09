/**
* 作者：刘时明
* 时间：2020/8/9 0009-1:42
*/
#include "ch12.h"
#include <pthread.h>
#include <cstdio>
#include <unistd.h>

void *thFunc(void *arg)
{
    pid_t pid = getpid();
    cout << "in thFunc,pid=" << pid << endl;
    return (void *) nullptr;
}

void ch12()
{
    pthread_t t;
    int ret;
    ret = pthread_create(&t, nullptr, thFunc, nullptr);
    if (ret)
    {
        printf("pthread_create failed:%d\n", ret);
        return;
    }
    sleep(1);
    printf("in main:thread is created , ret=%d\n", ret);
}