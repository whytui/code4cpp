/*
* 作者：刘时明
* 时间：2020/5/24-7:02
* 作用：
*/
#include <iostream>
#include <fstream>
#include "ch03.h"

using namespace std;

void ch03()
{
    poker();
    maze("../resource/maze.txt");
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
 * 走迷宫
 * @param path
 */
void maze(const string &path)
{
    ifstream input;
    input.open(path);
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return;
    }
    int maps[10][10];
    string str;
    int index = 0;
    while (getline(input, str, '\n'))
    {
        for (int i = 0; i < str.length(); ++i)
        {
            maps[index][i] = str.at(i) - 48;
        }
        index++;
    }
    set_way(maps, 1, 1);

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << maps[i][j];
        }
        cout << endl;
    }
}

/**
 * 走迷宫的实现方法
 * @param maps
 * @param i
 * @param j
 * @return
 */
bool set_way(int maps[10][10], int i, int j)
{
    // 0代表未走过的路，1代表墙体，2代表走过的路，3代表通路
    // 如果终点已经走过就退出
    if (maps[9][9] == 2)
    {
        return true;
    } else
    {
        if (maps[i][j] == 0)
        {
            maps[i][j] = 2;
            if (set_way(maps, i + 1, j))
            {
                return true;
            } else if (set_way(maps, i, j + 1))
            {
                return true;
            } else if (set_way(maps, i - 1, j))
            {
                return true;
            } else if (set_way(maps, i, j - 1))
            {
                return true;
            } else
            {
                maps[i][j] = 3;
                return false;
            }
        } else
        {
            return false;
        }
    }
}