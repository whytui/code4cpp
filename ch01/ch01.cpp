/*
* 作者：刘时明
* 时间：2020/5/23-0:08
* 作用：
*/
#include "ch01.h"

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

class Line
{
public:
    int getLength();

    Line(int len);             // 简单的构造函数
    Line(const Line &obj);      // 拷贝构造函数
    ~Line();                     // 析构函数

private:
    int *ptr;
};

// 成员函数定义，包括构造函数
Line::Line(int len)
{
    cout << "调用构造函数" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}

Line::~Line()
{
    cout << "释放内存" << endl;
    delete ptr;
}

int Line::getLength()
{
    return *ptr;
}

void display(Line obj)
{
    cout << "line 大小 : " << obj.getLength() << endl;
}

int main()
{
    // bit_demo();
    // Line line(10);

    // display(line);

    const_demo();
    return 0;
}