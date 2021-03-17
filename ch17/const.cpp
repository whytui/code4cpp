//
// Created by 刘时明 on 2021/3/17.
//
#include "main.h"

void const_point_demo()
{
    int a = 10;
    int b = 11;
    // 常量指针，指针指向的值不能被改变，但可以修改指针地址
    const int *p1 = &a;
    // *p1 = 100; 编译错误
    printf("%p \n", p1);
    p1 = &b;
    printf("%p \n", p1);

    // 指针常量，指针变量不允许修改，必须定义初始值（可以为空），但可以修改指针指向的值
    int *const p2 = &a;
    // p2 = &b; 编译错误
    *p2 = 100;

    // 常指针常量，都不能修改
    const int* const p3 = &a;
    // p3 = &b; 编译错误
    // *p3 = 1000; 编译错误
    printf("%p \n", p3);
}