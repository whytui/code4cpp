/*
* 作者：刘时明
* 时间：2020/6/13-0:51
* 作用：
*/
#include "ch01.h"

/**
 * 随机函数
 */
void random()
{
    /**
     * rand()返回一个随机整数
     * srand(int)函数修改随机数生成种子，种子默认为1
     */
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i)
    {
        printf("第%d次循环，随机值=%d\n", i + 1, rand());
    }
}