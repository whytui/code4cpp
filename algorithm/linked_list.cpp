/*
* 作者：刘时明
* 时间：2020/6/16-23:26
* 作用：
*/
#include "list.h"

template<typename T>
class LinkedNode
{
private:
    LinkedNode<T> *prev;
    LinkedNode<T> *next;
    T *data;

    template<typename E>
    friend
    class LinkedList;
};

template<typename T>
class LinkedList : public List<T>
{
private:
    LinkedNode<T> *head;
    LinkedNode<T> *tail;

public:
    void addLast(T *element)
    {

    }

    void addFirst(T *element)
    {

    }

    bool empty() const override
    {
        return false;
    }

    int size() const override
    {
        return 0;
    }

    T &get(int index) override
    {
        return 0;
    }

    int indexOf(T &element) override
    {
        return 0;
    }

    int lastIndexOf(T &element) override
    {
        return 0;
    }

    void add(T &element) override
    {

    }

    void add(int index, T &element) override
    {

    }

    void remove(int index) override
    {

    }

    void clear() override
    {

    }
};