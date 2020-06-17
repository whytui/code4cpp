/*
* 作者：刘时明
* 时间：2020/6/17-22:55
* 作用：
*/
#include "algorithm.h"

template<typename K, typename V>
class BinTreeNode
{
private:
    BinTreeNode<K, V> *left;
    BinTreeNode<K, V> *right;
    BinTreeNode<K, V> *parent;
    K key;
    V value;

public:
    BinTreeNode()
    {
        BinTreeNode(nullptr, nullptr, nullptr, nullptr, nullptr);
    }

    BinTreeNode(BinTreeNode<K, V> *left, BinTreeNode<K, V> *right, BinTreeNode<K, V> *parent, K key, V value) : left(
            left), right(right), parent(parent), key(key), value(value)
    {
    }
};

template<typename K, typename V>
class BinaryTree
{
private:
    BinTreeNode<K, V> root;
    int c_size;

public:
    BinaryTree()
    {
        root = nullptr;
        c_size = 0;
    }

    int size() const
    {
        return c_size;
    }

    bool isEmpty() const
    {
        return c_size == 0;
    }
};