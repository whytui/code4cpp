/*
* 作者：刘时明
* 时间：2020/5/24-19:38
* 作用：
*/
#include <iostream>
#include "ch06.h"

using namespace std;

void freeDemo();

/**
 * C++函数支持默认参数，而且必须在末尾位置，且可以定义多个
 * @param args
 */
int default_args(int lastArgs, int args1 = 1, int args2 = 1)
{
    return lastArgs + args1 + args2;
}

void ch06()
{
//    cout << default_args(10) << endl;
//    cout << default_args(10, 5) << endl;
//    cout << default_args(10, 10, 10) << endl;
    point();
    int arr[] = {1, 2, 3};
    arr_point(arr);

    int *a = reverse(arr, 3);
    cout << a << endl;
    delete[] a;
    func_point();

    int i1=1;
    int i2=10;
    // cout << add(&i1,&i2) << endl;

    cout << add(i1,i2) << endl;

    freeDemo();
}

void point()
{
    int p = 10;
    string str = "hello!!!";
    cout << sizeof(p) << endl;
    // bool指针只占1个字节，short指针只占2个字节
    cout << "bool指针=" << sizeof(bool) << endl;
    cout << "short指针=" << sizeof(short) << endl;
    cout << "int指针=" << sizeof(int) << endl;
    cout << "long指针=" << sizeof(long) << endl;
    cout << sizeof(&p) << endl;
    cout << sizeof(str) << endl;
    cout << sizeof(&str) << endl;

    // 常量指针指向一个不表的内容地址，该地址实际的值是可以改变的
    const int *cp;
    cp = &p;
    cout << "cp=" << *cp << endl;
    p = 20;
    cout << "cp=" << *cp << endl;
}

void arr_point(int *p)
{
    /**
     * C++指针运算只支持关系和加减运算
     * 指针加减运算实质是地址偏移，偏移大小为运算=数值*类型占用字节数
     */
    cout << "第三个元素=" << *(p + 2) << endl;
    /**
     * C++中数组名实际就是指向第一个元素的常量指针，因此，C++不支持数组重新赋值，new声明的除外
     */
    int list[] = {1, 2, 3, 4, 5};
    if (list == &list[0])
    {
        cout << "地址相等," << list << "," << &list[0] << endl;
    }
}

/**
 * 数组元素反转，并返回新数组
 * @param arr
 * @param size
 * @return
 */
int *reverse(const int *arr, int size)
{
    // 如果不使用new，则栈上分配，在函数结束时被回收
    int *new_arr = new int[size];
    for (int i = 0, j = size - 1; i < size; ++i, j--)
    {
        new_arr[i] = arr[j];
    }
    return new_arr;
}

/**
 * 函数入口是一个指针
 * @param a
 * @param b
 * @return
 */
int (*fp)(int a, int b);

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a > b ? b : a;
}

/**
 * 函数指针，一种特殊的指针，它指向函数的入口
 * 指针函数，返回值是指针类型，例如*reverse函数
 */
void func_point()
{
    // 函数指针f指向求最大值的函数max
    fp = max;
    cout << "max=" << (*fp)(1, 2) << endl;
    // 函数指针f指向求最小值的函数min
    fp = min;
    cout << "min=" << (*fp)(1, 2) << endl;
}


/**
 * 下面2个函数参数类型不一致，但效果是一样的
 * int * 代表参数是指针对象
 * int & 代表参数是值对象，但实际传递的也是指针
 */


int add(int *a,int *b)
{
    // *a++ 与 *a+=1 结果不一致，
    // 需要使用(*a)++
    (*a)++;
    *b+=2;
    return *a+*b;
}

int add(int &a,int &b)
{
    a++;
    b+=2;
    return a+b;
}