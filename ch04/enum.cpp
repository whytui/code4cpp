/*
* 作者：刘时明
* 时间：2020/7/5 0005-10:04
* 作用：
*/
#include "ch04.h"

enum Color
{
    RED, BLACK
};

string get_color(Color c);


void enum_demo()
{
    Color c{RED};

    cout << get_color(c) << endl;
    cout << get_color(BLACK) << endl;
}

inline string get_color(Color c)
{
    if (c == RED)
    {
        return "红色";
    } else if (c == BLACK)
    {
        return "黑色";
    } else
    {
        return "不能识别";
    }
}