/*
* 作者：刘时明
* 时间：2020/5/24-7:02
* 作用：
*/
#include "ch03.h"

void ch03()
{
    point_and_arr();

    dynamic_array();
}

void avg_demo()
{
    int size = 5;
    int numbers[size];
    for (int i = 0; i < size; ++i)
    {
        cout << "输入第" << i + 1 << "/" << size << "个元素的值" << endl;
        cin >> numbers[i];
    }
    cout << "平均值=" << getAvg(numbers, size) << endl;
    cout << "最大值=" << getMax(numbers, size) << endl;
    cout << "sizeof=" << sizeof(numbers) << endl;

    change_arr(numbers);

    cout << numbers[0] << endl;
}

double getAvg(const int numbers[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += numbers[i];
    }
    return sum / (double) size;
}

int getMax(const int numbers[], int size)
{
    int max = INT32_MIN;
    for (int i = 0; i < size; ++i)
    {
        if (max < numbers[i])max = numbers[i];
    }
    return max;
}

void change_arr(int numbers[])
{
    // 此处sizeof返回4，即数组类型int的字节数，并引发编译警报
    // warning: 'sizeof' on array function parameter 'numbers' will return size of 'int*'
    // cout << "change_arr,sizeof=" << sizeof(numbers) << endl;
    // 由于数组是指针类型，所以修改会生效
    numbers[0] = -1;
}

/**
 * 初始化一副扑克
 */
void poker()
{
    string types[] = {"黑桃", "红桃", "梅花", "方块"};
    string ranks[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    string targets[52];

    for (int i = 0; i < sizeof(types) / sizeof(types[0]); ++i)
    {
        for (int j = 0; j < sizeof(ranks) / sizeof(ranks[0]); ++j)
        {
            targets[i * (sizeof(ranks) / sizeof(ranks[0])) + j] = types[i] + ranks[j];
        }
    }
    for (auto &target : targets)
    {
        cout << target << endl;
    }
}


/**
 * 多维数组
 */
void multidimensional_array()
{
    // 数组本质就是一个指针，多维数组就是多维指针
    int len1 = 10, len2 = 10, len3 = 10;
    int ***p;
    p = new int **[len3];
    for (int i = 0; i < len3; ++i)
    {
        p[i] = new int *[len2];
        for (int j = 0; j < len2; ++j)
        {
            p[i][j] = new int[len1];
            for (int k = 0; k < len1; ++k)
            {
                p[i][j][k] = i * len1 * len2 + j * len3 + k;
            }
        }
    }

    // 打印内容并释放指针内存
    for (int i = 0; i < len3; ++i)
    {
        for (int j = 0; j < len2; ++j)
        {
            for (int k = 0; k < len3; ++k)
            {
                cout << p[i][j][k] << ",";
            }
            delete[] p[i][j];
        }
        delete[] p[i];
    }
    delete[] p;
    cout << endl;
    // 此时依然可以访问到内容
    // 原因：你只是放弃了对这片内存的所有权。获得所有权的人对这片内存做什么（或者说什么都不做）都不关你的事
    cout << "释放后=" << p[0] << endl;
    cout << "释放后=" << p[0][0] << endl;
    cout << "释放后=" << p[0][0][0] << endl;
}