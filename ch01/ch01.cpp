/*
* 作者：刘时明
* 时间：2020/5/23-0:08
* 作用：
*/
#include "ch01.h"

void readStdInput1();

void readStdInput2();

void readStdInput3();

void readLine();

void dateDemo();

void random();

void math_demo();

void char_demo();

void string_demo();

/**
 * 普通内联函数
 */
inline void inline_func1()
{
    cout << "这是一个内联函数" << endl;
}

/**
 * 普通内联函数
 */
inline int inline_func2(int number)
{
    cout << "这是一个内联函数" << endl;
    return number % 2;
}

/**
 * 结构体内联函数
 */
struct InLineDemo
{
private:
    int number;

public:
    inline void inline_func()
    {
        cout << this->number++ << endl;
        cout << "这是一个内联函数" << endl;
    }
};

void ch01()
{
    // readStdInput3();
    // char_arr_string();

//    inline_func1();
//    cout << inline_func2(1) << endl;
//    InLineDemo demo{};
//    demo.inline_func();
//
//    char_arr_string();
//
//    readLine();

    string_base_opt();
}