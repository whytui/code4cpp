/*
* 作者：刘时明
* 时间：2020/6/14-23:28
* 作用：
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
    int c_size;
    int cap;

    void expandCapacity(int newCap);

    void checkIndex(int index);

public:
    int size() const override;

    bool empty() const override;

    T &get(int index) override;

    int indexOf(T &element) const override;

    int lastIndexOf(T &element) const override;

    void add(T &element) override;

    void add(int index, T &element) override;

    void remove(int index) override;
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
int ArrayList<T>::indexOf(T &element) const
{
    int index = (int) (find(this->data, this->data + this->c_size, element) - this->data);
    return index == this->c_size ? -1 : index;
}

template<typename T>
int ArrayList<T>::lastIndexOf(T &element) const
{
    return 0;
}

template<typename T>
void ArrayList<T>::add(T &element)
{
    this->add(this->c_size, element);
}

template<typename T>
void ArrayList<T>::add(int index, T &element)
{
    if (index < 0 || index > this->c_size)
    {
        throw illegalParameterValue((char *) "索引越界");
    }
    if (this->c_size >= this->cap)
    {
        this->expandCapacity(this->c_size * 2);
    }
    this->data[index] = element;
    this->c_size++;
}

template<typename T>
void ArrayList<T>::remove(int index)
{
    this->checkIndex(index);

}

template<typename T>
void ArrayList<T>::checkIndex(int index)
{
    if (index < 0 || index >= this->c_size)
    {
        throw illegalParameterValue((char *) "索引越界");
    }
}

#endif //CODE4CPP_ARRAY_LIST_H
