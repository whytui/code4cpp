/*
* 作者：刘时明
* 时间：2020/5/24-18:24
* 作用：
*/
#include "stack.h"

Stack::Stack()
{
    size = 0;
    index = 0;
}

int Stack::get_size() const
{
    return size;
}

void Stack::push(int ele)
{
    int cap = sizeof(data) / sizeof(data[0]);
    if (size >= cap)
    {
        expandCapacity(cap);
    }
    data[index++] = ele;
    size++;
}

/**
 * 扩容方法
 */
void Stack::expandCapacity(const int cap)
{
    //#include <cstring>
//    int temp[cap * 2];
//    memcpy(temp, data, sizeof(data));
//
//    this->data = temp;
}

int Stack::peek()
{
    return data[index - 1];
}

int Stack::pop()
{
    if (size == 0)
    {
        // 抛出异常
        return -1;
    } else
    {
        size--;
        return data[--index];
    }
}

bool Stack::is_empty()
{
    return get_size() == 0;
}




