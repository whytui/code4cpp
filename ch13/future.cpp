/**
* 作者：刘时明
* 时间：2020/11/19 0019
*/
#include "main.h"
#include <future>

string get_ret(const string& name)
{
    sleep(1);
    return "hello:"+name;
}

void future_demo()
{
    cout << "----------" << endl;
    // 获取线程返回值
    future<string> result = async(get_ret,string("lsm"));
    cout << "in" << endl;
    // result.wait();
    cout << "result=" << result.get() << endl;
    cout << "----------" << endl;
}

