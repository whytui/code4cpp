/*
* 作者：刘时明
* 时间：2020/6/1-23:09
* 作用：
*/
#include "ch10.h"

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
}