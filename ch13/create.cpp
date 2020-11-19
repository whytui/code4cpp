/**
* 作者：刘时明
* 时间：2020/11/19 0019
*/
#include "main.h"

void print_hello()
{
    cout << "hello" << endl;
}

void create_thread()
{
    thread t(print_hello);
    if (t.joinable())
    {
        cout << "joinable" << endl;
    } else
    {
        cout << "not joinable" << endl;
    }
    t.join();
    if (t.joinable())
    {
        cout << "joinable" << endl;
    } else
    {
        cout << "not joinable" << endl;
    }
}

void create_by_lambda()
{
    auto obj = []
    {
        cout << "lambda thread begin!" << endl;
        cout << "lambda thread end!" << endl;
    };

    thread t(obj);
    t.join();
}