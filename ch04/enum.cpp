#include "ch04.h"

enum Color
{
    RED = 5,
    BLACK
};

string get_color(Color c);

void enum_demo()
{
    Color c{RED};
    cout << get_color(c) << endl;
    cout << get_color(BLACK) << endl;
    cout << "enum Color size =" << sizeof(Color) << endl;
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
        return "其他颜色";
    }
}