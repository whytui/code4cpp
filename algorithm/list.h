/*
* 作者：刘时明
* 时间：2020/6/14-23:31
* 作用：
*/

#ifndef CODE4CPP_LIST_H
#define CODE4CPP_LIST_H

template<typename T>
class List
{
public:
    virtual ~List() = default;

    virtual bool empty() const = 0;

    virtual int size() const = 0;

    virtual T &get(int index) = 0;

    virtual int indexOf(T &element) = 0;

    virtual int lastIndexOf(T &element) = 0;

    virtual void add(T &element) = 0;

    virtual void add(int index, T &element) = 0;

    virtual void remove(int index) = 0;

    virtual void clear() = 0;
};

#endif //CODE4CPP_LIST_H
