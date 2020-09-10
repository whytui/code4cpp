/**
* 作者：刘时明
* 时间：2020/9/5 0005-12:00
*/
#include <iostream>

using namespace std;

string *get_prt();

void life_test()
{
    int a = 1, b = a;

    printf("%p %p \n", &a, &b);

    for (int i = 0; i < 100; ++i)
    {
        string *result = get_prt();
        cout << "->" << *result << endl;
    }

}

string *get_prt()
{
    auto *str = new string("hello");
    return str;
}