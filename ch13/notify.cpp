//
// Created by 刘时明 on 2020/11/22.
//
#include "main.h"

// C++实现生产者消费者
int num = 0;

std::mutex cond_lock{};
std::condition_variable cond{};

void shengchan()
{
    while (true)
    {
        unique_lock cond_unique(cond_lock);
        if (num == 0)
        {
            sleep(1);
            num++;
            printf("生产完毕！\n");
            cond.notify_all();
        } else
        {
            cond.wait(cond_unique);
        }
    }
}

void xiaofei()
{
    while (true)
    {
        unique_lock cond_unique(cond_lock);
        if (num > 0)
        {
            sleep(1);
            num--;
            printf("消费完毕！\n");
            cond.notify_all();
        } else
        {
            cond.wait(cond_unique);
        }
    }
}

void notify_demo()
{
    thread t1(xiaofei);
    thread t2(shengchan);

    t1.join();
    t2.join();
}