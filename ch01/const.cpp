//
// Created by 刘时明 on 2020/11/28.
//
#include <cstdio>

int func_ptr()
{
    printf("call func_ptr \n");
    return 0;
}

void const_demo()
{
    const int a = 10;
    // const类型通过&获取会返回const指针
    // int* p=&a; 错误
    // const int* p = &a; 正确
    int *p = const_cast<int *>(&a);
    *p = 100;
    // debug看到a的值已经改变了，但是打印却还是原来的值，包括赋值
    printf("%d \n", a);

    typedef void (*FuncP1)();

    typedef int (*FuncP2)();

    FuncP1 f1;

    // 此处不传指针类型也正常执行
    f1 = reinterpret_cast<FuncP1>(&func_ptr);
    f1();

    auto f2=reinterpret_cast<FuncP2>(func_ptr);
    f2();
}
