/*
* 作者：刘时明
* 时间：2020/6/13-19:57
* 作用：
*/
#include "ch02.h"

bool set_way(int maps[10][10], int i, int j);

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