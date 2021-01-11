/*
* 作者：刘时明
* 时间：2020/5/31-0:14
* 作用：
*/
#include "ch08.h"

template<class T>
void hello(T value);

int main()
{
    hello("123");

    hello(123);

    hello(3.14F);

    hello('1');

    spaces_demo();
    return 0;
}

/**
 * 获取模板参数运行时类型
 * @tparam T
 * @param value
 */
template<class T>
void hello(T value)
{
    if (is_pointer<T>::value)
    {
        cout << "指针类型" << endl;
    } else
    {
        cout << "非指针类型" << endl;
    }

    cout << typeid(T).name() << ":" << value << endl;
}