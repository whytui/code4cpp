/**
* 作者：刘时明
* 时间：2020/11/19 0019
*/
#include "main.h"

void print_work(const int &i, char *buf)
{
    cout << i << endl;
    cout << buf << endl;
}

void print_work_ok(int i, const string &buf)
{
    cout << i << endl;
    cout << buf.c_str() << endl;
}

void thread_print()
{
    int v = 1;
    int &vy = v;

    char buf[] = "this is a test!";

    // thread_print结束，vy、buf均被回收
    thread t1(print_work, vy, buf);
    t1.detach();

    thread t2(print_work_ok, v, string(buf));
    t2.detach();
}