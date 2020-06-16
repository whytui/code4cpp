/*
* 作者：刘时明
* 时间：2020/6/14-23:28
* 作用：ArrayList 基于数组的线性表
*/
#ifndef CODE4CPP_ARRAY_LIST_H
#define CODE4CPP_ARRAY_LIST_H

#include <bits/stdc++.h>
#include "list.h"
#include "error.h"

template<typename T>
class ArrayList : public List<T>
{
private:
    T *data;
    int c_size{};
    int cap{};

    void expandCapacity(int newCap);

    void checkIndex(int index);

public:
    ArrayList()
    {
        this->cap = 10;
        this->data = new T[this->cap];
    };

    explicit ArrayList(int cap)
    {
        this->cap = cap;
        this->data = new T[this->cap];
    }

    ~ArrayList()
    {
        delete[] this->data;
    }

    int size() const override;

    bool empty() const override;

    T &get(int index) override;

    int indexOf(T &element) override;

    int lastIndexOf(T &element) override;

    void add(T &element) override
    {
        this->add(this->c_size, element);
    }

    void add(int index, T &element) override
    {
        if (index < 0 || index > this->c_size)
        {
            throw illegalParameterValue((char *) "索引越界");
        }
        if (this->c_size >= this->cap)
        {
            this->expandCapacity(this->c_size * 2);
        }
        copy_backward(this->data + index,
                      this->data + this->c_size,
                      this->data + this->c_size + 1);
        this->data[index] = element;
        this->c_size++;
    }

    void remove(int index) override
    {
        this->checkIndex(index);
        copy(this->data + index + 1,
             this->data + this->c_size,
             this->data + index);
        this->data[--this->c_size].~T();
    }

    void clear() override;

    void operator+(ArrayList<T> &list)
    {
        for (int i = 0; i < list.c_size; ++i)
        {
            this->add(list.get(i));
        }
    }
};

template<typename T>
int ArrayList<T>::size() const
{
    return this->c_size;
}

template<typename T>
void ArrayList<T>::expandCapacity(int newCap)
{
    if (newCap < this->c_size)
    {
        throw illegalParameterValue((char *) "扩容大小不可以小于当前大小");
    }
    T *temp = new T[newCap];
    copy(this->data, this->data + this->c_size, temp);
    delete[] this->data;
    this->data = temp;
}

template<typename T>
bool ArrayList<T>::empty() const
{
    return this->c_size == 0;
}

template<typename T>
T &ArrayList<T>::get(int index)
{
    this->checkIndex(index);
    return *(this->data + index);
}

template<typename T>
int ArrayList<T>::indexOf(T &element)
{
    int index = (int) (find(this->data, this->data + this->c_size, element) - this->data);
    return index == this->c_size ? -1 : index;
}

template<typename T>
int ArrayList<T>::lastIndexOf(T &element)
{
    for (int i = this->c_size - 1; i >= 0; --i)
    {
        if (element == this->get(i))
        {
            return i;
        }
    }
    return -1;
}

template<typename T>
void ArrayList<T>::checkIndex(int index)
{
    if (index < 0 || index >= this->c_size)
    {
        throw illegalParameterValue((char *) "索引越界");
    }
}

template<typename T>
void ArrayList<T>::clear()
{
    T *temp = new T[this->cap];
    for (int i = 0; i < this->c_size; ++i)
    {
        this->data[i].~T();
    }
    delete[] this->data;
    this->data = temp;
    this->c_size = 0;
}

#endif //CODE4CPP_ARRAY_LIST_H
