/*
* 作者：刘时明
* 时间：2020/5/23-0:08
* 作用：
*/
#include "ch01.h"

void ch01()
{
    scanInput();
}

/**
 * 读取键盘输入
 */
void scanInput()
{
    /**
     * C++中，cin表示标准控制台输入
     * >> 为流提取符号
     */
    double radius = 0;
    cout << "输入半径：";
    cin >> radius;
    // scanf("%lf", &radius);
    double area = radius * radius * PI;
    cout << "圆的面积=" << area << endl;
    cout << "double类型长度为：" << sizeof(area) << "byte" << endl;
}

/**
 * 读取多个输入
 */
void scanMultiple()
{
    /**
     * C++中，double number1(0)等价于double number=0
     */
    double number1(0), number2(0), number3(0);
    cout << "输入三个数值：";
    cin >> number1 >> number2 >> number3;
    cout << "平均值=" << (number1 + number2 + number3) / 3;
}

/**
 * 获取时间戳
 */
void dateDemo()
{
    /**
     * time(0)返回当前时间戳
     */
    cout << "当前时间戳=" << time(nullptr) << endl;
}

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

/**
 * if条件
 */
void if_demo()
{
    int a = 10;
    while (a)
    {
        a--;
    }
    printf("%d \n", a);
}