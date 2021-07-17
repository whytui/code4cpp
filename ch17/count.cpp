//
// Created by lsm on 2021/3/21.
//
#include <iostream>

using namespace std;

struct A
{
    char a;
    long long b[0];
    short c;
};

struct B
{
    char a;
    int b[10000];
    short c;
};

int getK(int array[], int size)
{
    int k = 0;
    bool flag = true;
    for (int i = 0; i < size - 1; ++i)
    {
        if (array[i] > array[i + 1])
        {
            k = i + 1;
            flag = false;
        }
    }
    return flag ? 0 : k;
}

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    int arr1[] = {1, 2, 3, 4, 5}; // 0
    int arr2[] = {4, 5, 1, 2, 3}; // 5
    int arr3[] = {5, 1, 2, 3, 4}; // 1

    cout << getK(arr1, 5) << endl;
    cout << getK(arr2, 5) << endl;
    cout << getK(arr3, 5) << endl;
    return 0;
}