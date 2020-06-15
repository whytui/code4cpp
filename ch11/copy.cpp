/*
* 作者：刘时明
* 时间：2020/6/14-22:18
* 作用：
*/
#include "ch11.h"

void copyArray();

void copyVector();

void copyDemo()
{
    copyVector();
}

/**
 * 拷贝数组
 */
void copyArray()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {0, 0, 0, 0, 0};
    // 第一个不复制
    copy(arr1 + 1, arr1 + 5, arr2 + 1);
    for (int i : arr2)
    {
        cout << i << endl;
    }
}

/**
 * 拷贝vector
 */
void copyVector()
{
    auto *v1 = new vector<int>();
    v1->push_back(1);
    v1->push_back(2);
    v1->push_back(3);
    auto *v2 = new vector<int>();
    // v2初始化后大小为0，需要设定大小
    v2->resize(5);
    // 把v1的所有元素复制到v2，从v2的第三个元素开始接收
    copy(v1->data(), v1->data() + 3, v2->begin() + 2);
    for (int i : *v2)
    {
        cout << i << endl;
    }
    delete v1;
    delete v2;
}