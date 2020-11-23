//
// Created by 刘时明 on 2020/11/22.
//

#include "main.h"

// 基本互斥锁
mutex m1{};

// 可重入互斥锁
recursive_mutex m2{};

// 带超时的互斥锁
timed_mutex m3{};

// 带超时的可重入互斥锁
recursive_timed_mutex m4{};

void test_mutex()
{
    // 使用不支持重入的mutex会导致线程一直等待
    // 教材中说会导致异常，应该是环境问题
    m2.lock();
    m2.lock();

    chrono::milliseconds timeout(100);
    // 是否获取到了锁，最多等待100毫秒
    if (m3.try_lock_for(timeout))
    {
        m3.unlock();
    } else
    {
        // 休眠
        this_thread::sleep_for(timeout);
    }

    // 下面的写法和m3.try_lock_for(timeout)是等价的
    if(m3.try_lock_until(chrono::steady_clock::now()+timeout))
    {
        m3.unlock();
    }
}