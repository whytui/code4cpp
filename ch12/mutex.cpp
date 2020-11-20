/**
* 作者：刘时明
* 时间：2020/8/17 0017-23:10
*/
#include <mutex>
#include <thread>
#include "main.h"

//定义一个全局变量，当作计数器用于累加
volatile int counter(0);
// 用于保护counter的互斥锁
mutex mtx;

void thr_func()
{
    for (int i = 0; i < 10000; ++i)
    {
        if (mtx.try_lock())
        {
            counter++; //计数器累加
            mtx.unlock(); //互斥锁解锁
        } else std::cout << "try_lock false\n";
    }
}

void thread_add()
{
    thread threads[10];
    for (auto &i : threads)
    {
        i = thread(thr_func); //启动10个线程
    }
    for (auto &th : threads) th.join(); //等待10个线程结束
    std::cout << "count to " << counter << " successfully \n";
}