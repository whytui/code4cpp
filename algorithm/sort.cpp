/*
* 作者：刘时明
* 时间：2020/6/14-23:10
* 作用：
*/
#include "sort.h"

void bubbleSort(int *arr, int size);

void selectSort(int *arr, int size);

void sort()
{
    int arr[] = {5, 8, 7, 6, 5, 4, 3, 3, 1, 0};
    selectSort(arr, sizeof(arr) / sizeof(int));

    for (int i:arr)
    {
        cout << i << endl;
    }
}

/**
 * 冒泡排序
 * @param arr
 * @param size
 */
void bubbleSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
    }
}

/**
 * 选择排序
 * @param arr
 * @param size
 */
void selectSort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}