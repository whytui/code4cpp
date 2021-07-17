//
// Created by Administrator on 2021/7/17.
//

#ifndef CODE4CPP_MEMORY_H
#define CODE4CPP_MEMORY_H

#include <cstddef>

//内存相关类
class CMemory
{
private:
    CMemory()
    {}

public:
    ~CMemory()
    {};

private:
    static CMemory *m_instance;

public:
    static CMemory *GetInstance() //单例
    {
        if (m_instance == nullptr)
        {
            //锁
            if (m_instance == nullptr)
            {
                m_instance = new CMemory(); //第一次调用不应该放在线程中，应该放在主进程中，以免和其他线程调用冲突从而导致同时执行两次new CMemory()
                static CGarhuishou cl;
            }
            //放锁
        }
        return m_instance;
    }

    class CGarhuishou
    {
    public:
        ~CGarhuishou()
        {
            if (CMemory::m_instance)
            {
                delete CMemory::m_instance;
                CMemory::m_instance = nullptr;
            }
        }
    };


public:
    void *AllocMemory(int memCount, bool ifMemset);

    void FreeMemory(void *point);
};

#endif //CODE4CPP_MEMORY_H
