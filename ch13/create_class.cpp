/**
* 作者：刘时明
* 时间：2020/11/19 0019
*/
#include "main.h"

class ThreadDemo1
{
public:
    void operator()()
    {
        cout << "operator()开始" << endl;

        cout << "operator()结束" << endl;
    }
};

class ThreadDemo2
{
public:
    ThreadDemo2(int &i) : m_i(i)
    {}

    ~ThreadDemo2()
    {
        cout << "ThreadDemo2释放" << endl;
    }

    void operator()()
    {
        cout << "m_i1=" << m_i << endl;
        cout << "m_i2=" << m_i << endl;
        cout << "m_i3=" << m_i << endl;
        cout << "m_i4=" << m_i << endl;
        cout << "m_i5=" << m_i << endl;
    }

    int &m_i;
};

void create_by_class()
{
    ThreadDemo1 demo1{};
    thread t1(demo1);
    t1.join();

    cout << "------------" << endl;

    int i = 6;
    ThreadDemo2 demo2(i);
    thread t2(demo2);
    // 使用detach需要注意线程对象的引用和指针
    t2.detach();
    cout << "end!!!" << endl;
}