/**
* 作者：刘时明
* 时间：2020/11/19 0019
*/
#include "main.h"

int value = 0;

mutex mutex_lock{};

atomic<int> int_value=0;

/**
 * 无锁
 */
void add_1()
{
    for (int i = 0; i < 1000000; ++i)
    {
        value++;
    }
}

/**
 * 互斥锁
 */
void add_2()
{
    for (int i = 0; i < 1000000; ++i)
    {
        // 可以用unique_lock取代lock/unlock
        unique_lock cond_unique(mutex_lock);
        //mutex_lock.lock();
        value++;
        //mutex_lock.unlock();
    }
}

/**
 * atomic
 */
void add_3()
{
    for (int i = 0; i < 1000000; ++i)
    {
        // int_value++;
        // 如果每次增量为2，则需要使用fetch_add
        // int_value=int_value+2 不是原子的
        int_value.fetch_add(2);
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

void add_3_demo()
{
    thread t1(add_3);
    thread t2(add_3);
    t1.join();
    t2.join();
    cout << int_value << endl;
}