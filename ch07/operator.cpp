/*
* 作者：刘时明
* 时间：2020/6/13-22:57
* 作用：
*/
#include "ch07.h"
#include "rational.h"

/**
 * string类型 <、>、+、[]等运算符都是通过operator关键字完成
 */
void string_operator()
{
    string s1("上啊");
    string s2("hello");
    cout << "first=" << s2[0] << endl;
    cout << "first=" << s2.operator[](0) << endl;
    s1.operator+=(s2);
    cout << s1 << endl;
}

void rational()
{
    auto *r1 = new Rational(1, 2);
    auto *r2 = new Rational(1, 2);
    auto r3 = *r1 + *r2;
    cout << r3.toString() << endl;
    cout << (r1 < &r3) << endl;

    cout << r3[0] << "," << r3[1] << endl;

    // 通过友元函数改变私有属性
    change(r3, 7, 8);
    cout << r3[0] << "," << r3[1] << endl;

    // 完成自动类型转换
    int intVal = r3;
    cout << "intVal=" << intVal << endl;

    auto r4 = r3;
    cout << "eq? " << r4.equals(r3) << endl;
    printf("%p , %p \n", r3, r4);
}
