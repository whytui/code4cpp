#include <vector>
#include "ch03.h"

void dynamic_array()
{
    // 初始化10个，值为10
    auto v1 = vector<int>(10, 10);
    // 初始化10个，值为默认值
    auto v2 = new vector<int>(10);
    // 指定初始值
    auto v3 = vector<int>{1, 2, 3, 4, 5};

    for (int i = 0; i < 10; ++i)
    {
        cout << v1.at(i) << endl;
    }

    v2->push_back(100);
    cout << v2->capacity() << endl;
    cout << v2->size() << endl;

    // v3.insert(v3.cend() - 2, 10);
    cout << v3.capacity() << endl;
    cout << v3.size() << endl;
    delete v2;
}