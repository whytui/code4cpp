/*
* 作者：刘时明
* 时间：2020/6/14-23:10
* 作用：
*/

#ifndef CODE4CPP_SORT_H
#define CODE4CPP_SORT_H

#include <iostream>

using namespace std;

void sort();

namespace my_util
{
    class SortUtil
    {
    public:
        template<class T>
        static void selectSort(T *arr, int size, int(*cmp)(T, T))
        {
            for (int i = 0; i < size; i++)
            {
                int min = i;
                for (int j = i + 1; j < size; j++)
                {
                    if ((*cmp)(arr[j], arr[min]) < 0)
                    {
                        min = j;
                    }
                }
                swap(arr[min], arr[i]);
            }
        }
    };
}

#endif //CODE4CPP_SORT_H
