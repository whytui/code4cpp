/*
* 作者：刘时明
* 时间：2020/7/5 0005-9:50
* 作用：
*/
#include <cstdio>

/**
 * union中声明的所有元素会占用同一块内存空间
 */
union Model
{
    char c;
    int i;
    float f;
};

void union_demo()
{
    Model model{};
    model.f = 100;
    // 修改c的值，会连带修改i和f
    model.c = 20;
    printf("%f \n", model.f);
    printf("%d \n", model.i);
}