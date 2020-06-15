/*
* 作者：刘时明
* 时间：2020/6/15-22:47
* 作用：
*/
#include "algorithm.h"

void algorithm()
{
    auto *list = new ArrayList<int>();

    cout << list->size() << endl;

    for (int i = 0; i < 100; ++i)
    {
        list->add(i);
    }

    for (int i = 0; i < list->size(); ++i)
    {
        cout << list->get(i) << endl;
    }

    int find = 50;
    cout << list->indexOf(find) << endl;

    try
    {
        list->remove(1000);
    } catch (illegalParameterValue v)
    {
        v.outputMessage();
    }
}