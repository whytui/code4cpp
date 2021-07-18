#include <cstdio>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int (*name)(int, int);

int optionResult(int a, int b, int(*func)(int, int))
{
    return (*func)(a, b);
}

/**
 * 函数指针
 */
void func_point2()
{
    name = add;

    printf("%d \n", (*name)(10, 5));
    // 实现一个动态函数调用，类似于Java的匿名内部类
    printf("%d \n", optionResult(1, 2, add));
    printf("%d \n", optionResult(1, 2, sub));
}