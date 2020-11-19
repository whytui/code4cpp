/**
* 作者：刘时明
* 时间：2020/11/19 0019
*/
#include <mutex>
#include "main.h"

int value = 0;

mutex mutex_lock{};

void add_1()
{
    for (int i = 0; i < 1000000; ++i)
    {
        value++;
    }
}

void add_2()
{
    for (int i = 0; i < 1000000; ++i)
    {
        mutex_lock.lock();
        value++;
        mutex_lock.unlock();
    }
}

void add_1_demo()
{
    thread t1(add_1);
    thread t2(add_1);
    t1.join();
    t2.join();
    cout << value << endl;
}

void add_2_demo()
{
    thread t1(add_2);
    thread t2(add_2);
    t1.join();
    t2.join();
    cout << value << endl;
}