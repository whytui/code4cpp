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
    cout << "in thFunc" << endl;
    return (void *) nullptr;
}

void ch12()
{
    int a=1;
    a++;

    cout << a << endl;


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