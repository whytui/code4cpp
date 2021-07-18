//
// Created by Administrator on 2021/7/17.
//

#ifndef CODE4CPP_THREADPOOL_H
#define CODE4CPP_THREADPOOL_H

#include <vector>
#include <deque>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>

//!
//! convenience macro to log with file and line information
//!
#ifdef __SOLA_LOGGING_ENABLED
#define __SOLA_LOG(level, msg) sola::level(msg, __FILE__, __LINE__);
#else
#define __SOLA_LOG(level, msg)
#endif /* __SOLA_LOGGING_ENABLED */

class ThreadPool
{
public:
    typedef std::function<void()> task_t;

    ThreadPool(int init_size);

    ThreadPool() : ThreadPool(3)
    {}

    ~ThreadPool();

    void stop();

    void add_task(const task_t &);  //thread safe;

private:
    ThreadPool(const ThreadPool &);//禁止复制拷贝.
    const ThreadPool &operator=(const ThreadPool &);

    bool is_started()
    { return m_is_started; }

    void start();

    void thread_loop();

    task_t take();

    typedef std::vector<std::thread *> threads_t;
    typedef std::deque<task_t> tasks_t;

    int m_init_threads_size;

    threads_t m_threads;
    tasks_t m_tasks;

    std::mutex m_mutex;
    std::condition_variable m_cond;
    bool m_is_started;
};

#endif //CODE4CPP_THREADPOOL_H
