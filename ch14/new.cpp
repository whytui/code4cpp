/**
* 作者：刘时明
* 时间：2020/11/26 0026
*/
#include <iostream>

using namespace std;

class NewDemo1
{
public:
    int value{};

    NewDemo1()
    {
        cout << "NewDemo1!!!" << endl;
    }
};

void new_demo()
{
    auto *n1 = new NewDemo1();
    auto *n2 = new NewDemo1;

    cout << n1->value << endl;
    cout << n2->value << endl;

    // p1值是随机的
    int *p1=new int;
    int *p2=new int();
    int *p3=new int(100);

    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
}