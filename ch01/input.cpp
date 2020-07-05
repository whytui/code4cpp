/*
* 作者：刘时明
* 时间：2020/6/13-0:28
* 作用：读取键盘输入
*/
#include "ch01.h"

void readStdInput1()
{
    /**
     * C++中，cin表示标准控制台输入
     * >> 为流提取符号
     */
    double radius = 0;
    cout << "输入半径：";
    cin >> radius;
    double area = radius * radius * PI;
    cout << "圆的面积=" << area << endl;
    cout << "double类型长度为：" << sizeof(area) << "byte" << endl;
}

void readStdInput2()
{
    /**
     * C++中，double number1(0)等价于double number=0
     */
    double number1(0), number2(0), number3(0);
    cout << "输入三个数值：";
    cin >> number1 >> number2 >> number3;
    cout << "平均值=" << (number1 + number2 + number3) / 3;
}

void readStdInput3()
{
    char c[1];
    scanf("%s", &c);
    cout << "你输入的是：" << c << endl;
}

void readLine()
{
    // 读取一行，回车符为结束
    string str;
    cout << "输入一行" << endl;
    getline(cin, str, '\n');
    cout << "再输入一行" << endl;
    char buff[5];
    // 如果输入的字符串大于长度，则多余的会被舍弃
    cin.getline(buff, 5);
    cout << "输入如下：" << endl;
    cout << "你输入的是=" << str << endl;
    cout << "你输入的是=" << buff << endl;
}