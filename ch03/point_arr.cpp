#include "ch03.h"


/**
* 不初始化的话，数组值是不可预测的，如下：
* int arr[];
* new int[len];
*/

void point_and_arr()
{
    int *p;
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *arr2 = new int[10]{};

    // 数组转指针是OK的
    p = arr1;
    p[0] = 10;

    for (int i = 0; i < 10; ++i)
    {
        cout << "p ->" << *(p + i) << endl;

        cout << "arr1 ->" << arr1[i] << endl;
        cout << "arr2 ->" << arr2[i] << endl;
    }

    cout << "-------" << endl;

    int (*arr3)[10];
    arr3 = (int (*)[10]) p;

    // 从输出看，arr3和p的值是不同的
    for (int i = 0; i < 10; ++i)
    {
        cout << "p item ->" << *(p + i) << endl;
        cout << "arr3 item ->" << *arr3[i] << endl;
    }
}