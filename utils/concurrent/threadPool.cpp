//
// Created by Administrator on 2021/7/17.
//

#include "threadPool.h"
#include "memory.h"
#include <unistd.h>
#include <thread>

//静态成员初始化
pthread_mutex_t CThreadPool::m_pthreadMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t CThreadPool::m_pthreadCond = PTHREAD_COND_INITIALIZER;
bool CThreadPool::m_shutdown = false;    //刚开始标记整个线程池的线程是不退出的

//构造函数
CThreadPool::CThreadPool()
{
    m_iRunningThreadNum = 0;  //正在运行的线程，开始给个0【注意这种写法：原子的对象给0也可以直接赋值，当整型变量来用】
    m_iLastEmgTime = 0;       //上次报告线程不够用了的时间；
    m_iRecvMsgQueueCount = 0; //收消息队列
}

//析构函数
CThreadPool::~CThreadPool()
{
    clearMsgRecvQueue();
}

//各种清理函数-------------------------
//清理接收消息队列，注意这个函数的写法。
void CThreadPool::clearMsgRecvQueue()
{
    char *sTmpMempoint;
    CMemory *p_memory = CMemory::GetInstance();

    //尾声阶段，需要互斥？该退的都退出了，该停止的都停止了，应该不需要退出了
    while (!m_MsgRecvQueue.empty())
    {
        sTmpMempoint = m_MsgRecvQueue.front();
        m_MsgRecvQueue.pop_front();
        p_memory->FreeMemory(sTmpMempoint);
    }
}

//创建线程池中的线程，要手工调用，不在构造函数里调用了
//返回值：所有线程都创建成功则返回true，出现错误则返回false
bool CThreadPool::Create(int threadNum)
{
    ThreadItem *pNew;
    int err;

    m_iThreadNum = threadNum; //保存要创建的线程数量

    for (int i = 0; i < m_iThreadNum; ++i)
    {
        m_threadVector.push_back(pNew = new ThreadItem(this));             //创建 一个新线程对象 并入到容器中
        err = pthread_create(&pNew->_Handle, NULL, ThreadFunc, pNew);      //创建线程，错误不返回到errno，一般返回错误码
        if (err != 0)
        {
            //创建线程有错
            perror("CThreadPool::Create()创建线程失败!");
            return false;
        } else
        {
            //创建线程成功
            //ngx_log_stderr(0,"CThreadPool::Create()创建线程%d成功,线程id=%d",pNew->_Handle);
        }
    } //end for

    //我们必须保证每个线程都启动并运行到pthread_cond_wait()，本函数才返回，只有这样，这几个线程才能进行后续的正常工作
    std::vector<ThreadItem *>::iterator iter;
    lblFor:
    for (iter = m_threadVector.begin(); iter != m_threadVector.end(); iter++)
    {
        if (!(*iter)->ifrunning) //这个条件保证所有线程完全启动起来，以保证整个线程池中的线程正常工作；
        {
            //这说明有没有启动完全的线程
            usleep(100 * 1000);  //单位是微妙,又因为1毫秒=1000微妙，所以 100 *1000 = 100毫秒
            goto lblFor;
        }
    }
    return true;
}

//线程入口函数，当用pthread_create()创建线程后，这个ThreadFunc()函数都会被立即执行；
void *CThreadPool::ThreadFunc(void *threadData)
{
    //这个是静态成员函数，是不存在this指针的；
    auto *pThread = static_cast<ThreadItem *>(threadData);
    CThreadPool *pThreadPoolObj = pThread->_pThis;

    CMemory *p_memory = CMemory::GetInstance();

    pthread_t tid = pthread_self(); //获取线程自身id，以方便调试打印信息等
    while (true)
    {
        //线程用pthread_mutex_lock()函数去锁定指定的mutex变量，若该mutex已经被另外一个线程锁定了，该调用将会阻塞线程直到mutex被解锁。
        if (pthread_mutex_lock(&m_pthreadMutex) != 0)
        {
            perror("CThreadPool::ThreadFunc()中pthread_mutex_lock()失败");
        }
        while ((pThreadPoolObj->m_MsgRecvQueue.empty()) && !m_shutdown)
        {
            if (!pThread->ifrunning)
            {
                pThread->ifrunning = true;
            }
            pthread_cond_wait(&m_pthreadCond, &m_pthreadMutex);
        }
        // 先判断线程退出这个条件
        if (m_shutdown)
        {
            pthread_mutex_unlock(&m_pthreadMutex); //解锁互斥量
            break;
        }

        // 走到这里，可以取得消息进行处理了【消息队列中必然有消息】,注意，目前还是互斥着呢
        char *jobBuf = pThreadPoolObj->m_MsgRecvQueue.front();     //返回第一个元素但不检查元素存在与否
        pThreadPoolObj->m_MsgRecvQueue.pop_front();                //移除第一个元素但不返回
        --pThreadPoolObj->m_iRecvMsgQueueCount;                    //收消息队列数字-1

        //可以解锁互斥量了

        if (pthread_mutex_unlock(&m_pthreadMutex) != 0)
        {
            perror("CThreadPool::ThreadFunc()中pthread_mutex_unlock()失败");
        }
        //能走到这里的，就是有消息可以处理，开始处理
        ++pThreadPoolObj->m_iRunningThreadNum;    //原子+1【记录正在干活的线程数量增加1】，这比互斥量要快很多

        // g_socket.threadRecvProcFunc(jobbuf); //处理消息队列中来的消息
        printf("%s tid=%d\n", jobBuf, tid);

        p_memory->FreeMemory(jobBuf);              //释放消息内存
        --pThreadPoolObj->m_iRunningThreadNum;     //原子-1【记录正在干活的线程数量减少1】
    }
    //能走出来表示整个程序要结束啊，怎么判断所有线程都结束？
    return (void *) 0;
}

//停止所有线程【等待结束线程池中所有线程，该函数返回后，应该是所有线程池中线程都结束了】
void CThreadPool::StopAll()
{
    //(1)已经调用过，就不要重复调用了
    if (m_shutdown)
    {
        return;
    }
    m_shutdown = true;

    // (2)唤醒等待该条件【卡在pthread_cond_wait()的】的所有线程，一定要在改变条件状态以后再给线程发信号
    if (pthread_cond_broadcast(&m_pthreadCond) != 0)
    {
        //这肯定是有问题，要打印紧急日志
        perror("CThreadPool::StopAll()中pthread_cond_broadcast()失败");
        return;
    }

    //(3)等等线程，让线程真返回
    std::vector<ThreadItem *>::iterator iter;
    for (iter = m_threadVector.begin(); iter != m_threadVector.end(); iter++)
    {
        pthread_join((*iter)->_Handle, nullptr); //等待一个线程终止
    }

    //流程走到这里，那么所有的线程池中的线程肯定都返回了；
    pthread_mutex_destroy(&m_pthreadMutex);
    pthread_cond_destroy(&m_pthreadCond);

    //(4)释放一下new出来的ThreadItem【线程池中的线程】
    for (iter = m_threadVector.begin(); iter != m_threadVector.end(); iter++)
    {
        if (*iter)
        {
            delete *iter;
        }
    }
    m_threadVector.clear();
    printf("CThreadPool::StopAll()成功返回，线程池中线程全部正常结束!");
}

//--------------------------------------------------------------------------------------
//收到一个完整消息后，入消息队列，并触发线程池中线程来处理该消息
void CThreadPool::inMsgRecvQueueAndSignal(char *buf)
{
    if (pthread_mutex_lock(&m_pthreadMutex) != 0)  // 互斥
    {
        perror("CThreadPool::inMsgRecvQueueAndSignal()pthread_mutex_lock()失败");
    }
    m_MsgRecvQueue.push_back(buf);             //入消息队列
    ++m_iRecvMsgQueueCount;                  //收消息队列数字+1，个人认为用变量更方便一点，比 m_MsgRecvQueue.size()高效
    if (pthread_mutex_unlock(&m_pthreadMutex) != 0) // 取消互斥
    {
        perror("CThreadPool::inMsgRecvQueueAndSignal()pthread_mutex_unlock()失败");
    }
    // 可以激发一个线程来干活了
    Call();
}

// 来任务了，调一个线程池中的线程下来干活
void CThreadPool::Call()
{
    if (pthread_cond_signal(&m_pthreadCond) != 0)
    {
        perror("CThreadPool::Call()中pthread_cond_signal()失败");
    }
    if (m_iThreadNum == m_iRunningThreadNum) //线程池中线程总量，跟当前正在干活的线程数量一样，说明所有线程都忙碌起来，线程不够用了
    {
        time_t currTime = time(nullptr);
        if (currTime - m_iLastEmgTime > 10) //最少间隔10秒钟才报一次线程池中线程不够用的问题；
        {
            //两次报告之间的间隔必须超过10秒，不然如果一直出现当前工作线程全忙，但频繁报告日志也够烦的
            m_iLastEmgTime = currTime;  //更新时间
            //写日志，通知这种紧急情况给用户，用户要考虑增加线程池中线程数量了
            printf("CThreadPool::Call()中发现线程池中当前空闲线程数量为0，要考虑扩容线程池了!");
        }
    }
}
