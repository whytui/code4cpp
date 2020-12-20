//
// Created by 刘时明 on 2020/12/20.
//

#include <unistd.h>
#include <thread>
#include <cstdio>

typedef struct point_demo
{
    int *p;
} demo;

void join_demo1()
{
    printf("join_demo1 in! \n");
    // sleep(5);
}

void detach_demo(point_demo *demo)
{
    printf("demo=%p \n", demo);
    printf("%d \n", *(demo->p));
}

void join_demo()
{
    printf("join_demo in! \n");

    std::thread t1(join_demo1);

    printf("线程ok! \n");
    t1.join();
    printf("join完成! \n");


    auto *demo=new point_demo;
    demo->p = new int(10);
    printf("demo=%p \n", demo);
    std::thread t2(detach_demo, demo);
    t2.detach();
}