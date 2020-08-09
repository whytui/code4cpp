/*
* 作者：刘时明
* 时间：2020/6/14-23:10
* 作用：
*/
#include "sort.h"

void bubbleSort(int *arr, int size);

void selectSort(int *arr, int size);

void quickSort(int *arr, int size);

inline int cmp(int a, int b)
{
    // 倒序
    return b - a;
}

void sort()
{
    int arr[] = {5, 8, 7, 6, 5, 4, 3, 3, 1, 0};
    my_util::SortUtil::selectSort(arr, sizeof(arr) / sizeof(int), cmp);
    // quickSort(arr, sizeof(arr) / sizeof(int));
    for (int &i:arr)
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

int partition(int *arr, int i, int j)
{
    int pos = arr[i];
    while (i < j)
    {
        while (i < j && arr[j] >= pos)
            j--;
        if (i < j)
            arr[i++] = arr[j];
        while (i < j && arr[i] < pos)
            i++;
        if (i < j)
            arr[j--] = arr[i];
    }
    arr[i] = pos;
    return i;
}

void quickSort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pos = partition(arr, start, end);
        quickSort(arr, start, pos - 1);
        quickSort(arr, pos + 1, end);
    }
}

/**
 * 快速排序
 * @param arr
 * @param size
 */
void quickSort(int *arr, int size)
{
    quickSort(arr, 0, size - 1);
}