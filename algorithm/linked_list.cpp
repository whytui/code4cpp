/*
* 作者：刘时明
* 时间：2020/6/16-23:26
* 作用：
*/
#include "list.h"
#include <iostream>

template<class T>
class LinkedNode
{
private:
    LinkedNode<T> *prev;
    LinkedNode<T> *next;
    T *data;

    LinkedNode()
    {
        LinkedNode(nullptr, nullptr, nullptr);
    }

    LinkedNode(T &element)
    {
        LinkedNode(nullptr, nullptr, element);
    }

    LinkedNode(LinkedNode<T> *prev, LinkedNode<T> *next, T &element)
    {
        this->prev = prev;
        this->next = next;
        this->data = &element;
    }

    template<class T>
    friend
    class LinkedList;
};

template<class T>
class LinkedList : public List<T>
{
private:
    LinkedNode<T> *head;
    LinkedNode<T> *tail;
    int c_size;

public:
    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
        this->c_size = 0;
    }

    void addLast(T *element)
    {

    }

    void addFirst(T &element)
    {
        if (this->head == nullptr)
        {
            this->head = new LinkedNode<T>(nullptr, this->tail, element);
        } else
        {
//            Node<E> newNode = new Node<>(null, null, data);
//            Node<E> temp = head;
//            temp.prev = newNode;
//            newNode.next = temp;
//            head = newNode;

            auto *newNode = new LinkedNode<T>(element);
            auto temp = head;
            temp->prev = newNode;
            newNode->next = temp;
            head = newNode;
        }
        this->c_size++;
    }

    bool empty() const override
    {
        return size() == 0;
    }

    int size() const override
    {
        return c_size;
    }

    T &get(int index) override
    {
        T *temp = nullptr;
        return *temp;
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
        auto temp = this->head->next;
        while (temp != this->tail)
        {
            temp = temp->next;
        }
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->c_size = 0;
    }

    void disPlay()
    {
        auto temp = this->head;
        while (temp != nullptr)
        {
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
    }
};

void linkedDemo()
{
    auto *list = new LinkedList<int>();
    for (int i = 0; i < 10; ++i)
    {
        list->addFirst(i);
    }
    list->disPlay();
}