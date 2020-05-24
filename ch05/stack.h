/*
* 作者：刘时明
* 时间：2020/5/24-18:24
* 作用：
*/

#ifndef CODE4CPP_STACK_H
#define CODE4CPP_STACK_H

/**
 * 实现一个基于数组的FILO数据结构
 */
class Stack
{
private:
    int data[10];
    int size;
    int index;

    void expandCapacity(int cap);

public:
    Stack();

public:
    int get_size() const;

    void push(int ele);

    int peek();

    int pop();

    bool is_empty();
};


#endif //CODE4CPP_STACK_H
