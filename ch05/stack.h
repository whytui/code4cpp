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

    ~Stack();

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
    cap = 10;
    data = new int[cap];
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] data;
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
    data[size++] = ele;
}

/**
 * 扩容方法
 */
template<typename T>
void Stack<T>::expandCapacity()
{
    T *old = data;
    data = new T[cap * 2];
    for (int i = 0; i < size; ++i)
    {
        data[i] = old[i];
    }
    delete[] old;
    this->cap *= 2;
}

template<typename T>
T Stack<T>::peek()
{
    return data[size - 1];
}

template<typename T>
T Stack<T>::pop()
{
    return data[--size];
}

template<typename T>
bool Stack<T>::is_empty()
{
    return get_size() == 0;
}


#endif //CODE4CPP_STACK_H
