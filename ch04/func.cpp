#include <cstdio>

/**
* 作者：刘时明
* 时间：2020/11/8 0008-14:51
*/

struct FuncDemoStruct
{
    int val;
};

class FuncDemoClass
{
public:
    int val;
};

void change_func(struct FuncDemoStruct func)
{
    /**
     * 值传递，形参的struct可以忽略
     */
    func.val = 12;
}

void change_func(class FuncDemoClass *func)
{
    /**
     * 值传递，形参的class可以忽略
     */
    func->val = 12;
}

void func()
{
    FuncDemoStruct demo1{};
    demo1.val = 100;
    change_func(demo1);
    printf("%d \n", demo1.val);

    FuncDemoClass demo2{};
    demo2.val = 100;
    change_func(&demo2);
    printf("%d \n", demo2.val);
}