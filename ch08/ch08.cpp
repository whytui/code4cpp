/*
* 作者：刘时明
* 时间：2020/5/31-0:14
* 作用：
*/
#include "ch08.h"

template<class T>
void hello(T value);

void ch08()
{
    hello("123");

    hello(123);

    hello(3.14F);

    hello('1');
}

/**
 * 获取模板参数运行时类型
 * @tparam T
 * @param value
 */
template<class T>
void hello(T value)
{
    cout << typeid(T).name() << ":" << value << endl;
}