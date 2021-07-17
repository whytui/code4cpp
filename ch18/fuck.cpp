//
// Created by Administrator on 2021/7/17.
//
#include <iostream>

class Fuck
{
private:
    int a = 1;

    int b = 1;

    int *c;

    virtual void fuckFun()
    {
        say();
    }

    void say()
    {
        printf("call say!\n");
    }
};

void fuckDemo()
{
    typedef long long Point;

    printf("%d\n", sizeof(Point));

    Fuck f;

    // f对象首地址即为虚函数指针
    Point *pvPtr = (Point *) &f;

    // 通过虚函数指针去拿虚函数表指针
    Point *vPtr = (Point *) *pvPtr;

    typedef void(*func)();
    // 直接拿第一个虚函数
    func callF = (func) vPtr[0];

    callF();
}