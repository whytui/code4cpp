/**
* 作者：刘时明
* 时间：2020/11/19 0019
*/
#include "main.h"
#include <future>

int get_ret()
{
    cout << "return_hello" << endl;
    return 10;
}

void future_demo()
{
    cout << "----------" << endl;
    // 获取线程返回值
    future<int> result = async(get_ret);
    cout << "in" << endl;
    // result.wait();
    cout << "result=" << result.get() << endl;
    cout << "----------" << endl;
}

