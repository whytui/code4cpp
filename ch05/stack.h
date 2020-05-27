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
template<typename T>
class Stack
{
private:
    T *data;
    int size;
    int index;
    int cap;

    void expandCapacity();

public:
    Stack();

public:
    int get_size() const;

    void push(T ele);

    T peek();

    T pop();

    bool is_empty();
};

template<typename T>
Stack<T>::Stack()
{
    size = 0;
    index = 0;
    cap = 10;
    data = new int[cap];
}

template<typename T>
int Stack<T>::get_size() const
{
    return size;
}

template<typename T>
void Stack<T>::push(T ele)
{
    if (size >= cap - 1)
    {
        expandCapacity();
    }
    data[index++] = ele;
    size++;
}

/**
 * 扩容方法
 */
template<typename T>
void Stack<T>::expandCapacity()
{
    int *temp = new int[cap * 2];
    for (int i = 0; i < size; ++i)
    {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    this->cap *= 2;
}

template<typename T>
T Stack<T>::peek()
{
    return data[index - 1];
}

template<typename T>
T Stack<T>::pop()
{
    if (size == 0)
    {
        // 抛出异常
        return NULL;
    } else
    {
        size--;
        return data[--index];
    }
}

template<typename T>
bool Stack<T>::is_empty()
{
    return get_size() == 0;
}


#endif //CODE4CPP_STACK_H
