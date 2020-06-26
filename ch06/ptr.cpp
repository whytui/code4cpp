#include <memory>
#include <iostream>

using namespace std;

void ptr_demo()
{
    shared_ptr<int> p1;
    cout << "p1=" << p1 << endl;
    if (p1 == nullptr)
    {
        cout << "p1 == nullptr" << endl;
        p1 = make_shared<int>(42);
    }
    cout << "p1=" << p1 << endl;
    if (p1)
    {
        cout << "没有初始值" << endl;
    }
}