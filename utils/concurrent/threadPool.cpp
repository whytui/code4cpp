//
// Created by Administrator on 2021/7/17.
//
#include <cassert>
#include <iostream>
#include <sstream>
#include "threadPool.h"

static std::string get_tid()
{
    std::stringstream tmp;
    tmp << std::this_thread::get_id();
    return tmp.str();
}

ThreadPool::ThreadPool(int init_size)
        : m_init_threads_size(init_size),
          m_mutex(),
          m_cond(),
          m_is_started(false)
{
    start();
}

ThreadPool::~ThreadPool()
{
    if (m_is_started)
    {
        stop();
    }
}

void ThreadPool::start()
{
    assert(m_threads.empty());
    m_is_started = true;
    m_threads.reserve(m_init_threads_size);
    for (int i = 0; i < m_init_threads_size; ++i)
    {
        m_threads.push_back(new std::thread([this]
                                            { thread_loop(); }));
    }

}

void ThreadPool::stop()
{
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_is_started = false;
        m_cond.notify_all();
    }
    for (auto &m_thread : m_threads)
    {
        m_thread->join();
        delete m_thread;
    }
    m_threads.clear();
}


void ThreadPool::thread_loop()
{
    while (m_is_started)
    {
        task_t task = take();
        if (task)
        {
            task();
        }
    }
}

void ThreadPool::add_task(const task_t &task)
{
    std::unique_lock<std::mutex> lock(m_mutex);
    /*while(m_tasks.isFull())
      {//when m_tasks have maxsize
        cond2.notify_one();
      }
    */
    m_tasks.push_back(task);
    m_cond.notify_one();
}

ThreadPool::task_t ThreadPool::take()
{
    std::unique_lock<std::mutex> lock(m_mutex);
    while (m_tasks.empty() && m_is_started)
    {
        m_cond.wait(lock);
    }

    task_t task;
    tasks_t::size_type size = m_tasks.size();
    if (!m_tasks.empty() && m_is_started)
    {
        task = m_tasks.front();
        m_tasks.pop_front();
        assert(size - 1 == m_tasks.size());
    }
    return task;
}
