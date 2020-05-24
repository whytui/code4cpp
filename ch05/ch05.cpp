/*
* 作者：刘时明
* 时间：2020/5/24-17:13
* 作用：
*/
#include "ch05.h"
#include "stack.h"
#include <iostream>

using namespace std;

string Student::ID = "431224";
int Student::CODE = 1998;

void ch05()
{
    auto *student = new Student("刘时明", Men);
    student->show();

    auto *stack = new Stack();
    for (int i = 0; i < 5; ++i)
    {
        stack->push(i * 10);
    }
    cout << stack->peek() << endl;
    cout << stack->get_size() << endl;

    while (!stack->is_empty())
    {
        cout << "弹出一个=" << stack->pop() << endl;
    }
}