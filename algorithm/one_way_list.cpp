/*
* 作者：刘时明
* 时间：2020/6/17-21:52
* 作用：单向链表
*/
#include "algorithm.h"

template<typename T>
struct ChainNode
{
private:
    T data;
    ChainNode<T> *next;

    template<typename E>
    friend
    class ChainList;

public:
    ChainNode()
    {
        ChainNode(nullptr, nullptr);
    }

    ChainNode(T data)
    {
        ChainNode(data, nullptr);
    }

    ChainNode(T data, ChainNode<T> *next)
    {
        this->data = data;
        this->next = next;
    }
};

template<typename T>
class ChainList
{
private:
    int c_size;
    ChainNode<T> *head;

    void checkIndex(int index) const
    {
        if (index < 0 || index >= this->c_size)
        {
            throw illegalParameterValue((char *) "索引越界");
        }
    }

    void checkAddIndex(int index) const
    {
        if (index < 0 || index > this->c_size)
        {
            throw illegalParameterValue((char *) "索引越界");
        }
    }

public:
    ChainList()
    {
        c_size = 0;
        head = nullptr;
    }

    ~ChainList()
    {
        cout << "析构函数调用" << endl;
        while (head != nullptr)
        {
            ChainNode<T> *nextNode = head->next;
            delete head;
            head = nextNode;
        }
    }

    bool empty() const
    { return c_size == 0; };

    int size() const
    {
        return c_size;
    }

    T &get(int index) const
    {
        checkIndex(index);
        ChainNode<T> *currNode = head;
        for (int i = 0; i < index; ++i)
        {
            currNode = currNode->next;
        }
        return currNode->data;
    }

    int indexOf(const T &data) const
    {
        ChainNode<T> *currNode = head;
        for (int i = 0; i < c_size; ++i)
        {
            if (currNode->data == data)
            {
                return i;
            } else
            {
                currNode = currNode->next;
            }
        }
        return -1;
    }

    void remove(int index)
    {
        checkIndex(index);
        ChainNode<T> *deleteNode;
        if (index == 0)
        {
            deleteNode = head;
            head = head->next;
        } else
        {
            ChainNode<T> *temp = head;
            for (int i = 0; i < index - 1; ++i)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
        c_size--;
        delete deleteNode;
    }

    void add(const T &data)
    {
        add(c_size, data);
    }

    void add(int index, const T &data)
    {
        checkAddIndex(index);
        if (c_size == 0)
        {
            head = new ChainNode<T>(data, nullptr);
        } else
        {
            ChainNode<T> *temp = head;
            for (int i = 0; i < index - 1; ++i)
            {
                temp = temp->next;
            }
            temp->next = new ChainNode<T>(data, temp->next);
        }
        c_size++;
    }

    void clear()
    {
        while (head != nullptr)
        {
            ChainNode<T> *nextNode = head->next;
            delete head;
            head = nextNode;
        }
        c_size = 0;
    }
};

void ChainDemo()
{
    auto *list = new ChainList<int>();
    for (int i = 0; i < 100; ++i)
    {
        list->add(i);
    }
    list->add(2, 10000);
    list->add(0, -1);
    for (int j = 0; j < list->size(); ++j)
    {
        cout << list->get(j) << endl;
    }
    delete list;
}