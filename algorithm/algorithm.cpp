/*
* 作者：刘时明
* 时间：2020/6/15-22:47
* 作用：
*/
#include "algorithm.h"

void arrayListDemo();

void ChainDemo();

void BinaryTreeDemo();

void algorithm()
{
    BinaryTreeDemo();
}

void arrayListDemo()
{
    auto *list = new ArrayList<int>(20);

    ArrayList<int> tempList(5);
    tempList.empty();
    int first=1;

    cout << list->size() << endl;

    for (int i = 0; i < 100; ++i)
    {
        list->add(i);
        tempList.add(i);
    }
    int f = 10000;
    list->add(2, f);
    list->remove(2);

    tempList + *list;
    for (int i = 0; i < tempList.size(); ++i)
    {
        cout << tempList.get(i) << endl;
    }
    int find = 50;
    cout << list->lastIndexOf(find) << endl;
    try
    {
        tempList.clear();
        tempList.add(1,first);
        list->remove(1000);
    } catch (illegalParameterValue v)
    {
        v.outputMessage();
    }
}