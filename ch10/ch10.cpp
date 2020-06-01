/*
* 作者：刘时明
* 时间：2020/6/1-23:09
* 作用：
*/
#include <iostream>
#include <time.h>
#include "ch10.h"

using namespace std;

int fun(int n);

void ch10()
{
    int num;
    cout << "输入一个数字" << endl;
    cin>> num;
    int a;
    try
    {
        if(num==0)
        {
            throw 0;
        }
        a = 1 / num;
    } catch (int ex)
    {
        cout << "ex=" << ex<<endl;
    }
    cout << "a=" << a <<endl;
    time_t startTime=time(0);
    cout << fun(50) << endl;
    time_t endTime=time(0);
    cout << "time=" << (endTime - startTime) << endl;
}

int fun(int n)
{
    if(n==1)
    {
        return 1;
    } else if(n==2)
    {
        return 1;
    } else {
        return fun(n-1)+fun(n-2);
    }
}