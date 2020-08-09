/*
* 作者：刘时明
* 时间：2020/7/5 0005-23:20
* 作用：
*/
#include "ch08.h"

namespace my_spaces
{
    int number;

    class Animal
    {
    public:
        string name;
    };
}

void spaces_demo()
{
    my_spaces::number = 100;

    my_spaces::Animal dog{};
    dog.name = "狗";

    cout << my_spaces::number << endl;
    cout << dog.name << endl;
}