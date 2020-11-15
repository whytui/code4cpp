/**
* 作者：刘时明
* 时间：2020/11/13 0013
*/
#include <iostream>
#include <memory>


/**
智能指针，对指针的一层包装，不需要使用delete去释放指针
 4种类型：
    1.auto_ptr 被unique_ptr取代；
    2.shared_ptr 共享式指针，多个指针指向同一个shared_ptr对象，最后一个对象被销毁时shared_ptr对象释放；
    3.weak_ptr 辅助shared_ptr；
    4.unique_ptr 独占式指针，同时刻只有一个指针指向unique_ptr对象；
 */
using namespace std;

template<typename T>
shared_ptr<int> makes(T value);

void shared_ptr_demo();

void myFunc1(shared_ptr<int> p);

shared_ptr<int> myFunc2(shared_ptr<int> p);

class A
{
public:
    A() = default;

    int get()
    {
        return 1;
    }
};

void autoFunc()
{
    int *p = new int;
    delete p;
    A *a1 = new A;
    A *a2 = new A();

    cout << a1->get() << endl;

    cout << a2->get() << endl;

    auto *str1 = new string(5, 'a');
    auto **str2 = new auto(str1);
    auto **str3 = new (string *)(str1);

    cout << **str2 << endl;
    cout << **str3 << endl;

    shared_ptr_demo();
}

void shared_ptr_demo()
{
    cout << "------------" << endl;
    shared_ptr<int> p1 = makes(100);
    shared_ptr<int> p2 = makes(100);
    shared_ptr<int> p3(p2);
    // use_count 返回同时指向该shared_ptr对象的指针数量
    cout << "p1 use_count=" << p1.use_count() << endl;
    cout << "p2 use_count=" << p2.use_count() << endl;
    cout << "p3 use_count=" << p3.use_count() << endl;

    // 返回 use_count()==1
    cout << p1.unique() << endl;
    cout << p2.unique() << endl;

    // 如果p1是唯一指向shared_ptr对象的指针，则释放该shared_ptr对象，并让p1指向new int(10)的内存
    // 如果p1不是唯一指向shared_ptr对象的指针，则不会释放该shared_ptr对象，但use_count会减一，并让p1指向new int(10)的内存
    p1.reset(new int(10));
    cout << p1.use_count() << endl;
    // reset()等价于reset(nullptr)
    p2.reset();
    if (p2 == nullptr)
    {
        cout << "p2被置空" << endl;
        cout << p3.use_count() << endl;
    }

    p1.swap(p3);
    cout << p1 << endl;
    cout << *p1 << endl;

    myFunc1(p1);
    cout << "p1 use_count=" << p1.use_count() << endl;


    auto p4 = myFunc2(p1);
    cout << "p1 use_count=" << p1.use_count() << endl;
    cout << "p4 use_count=" << p4.use_count() << endl;
    /**
     * shared_ptr的工作原理是引用计数
     * 计数增加的场景：
     *  1.智能指针赋值，shared_ptr<int> p3(p2)，p2和p3计数都会加一；
     *  2.把智能指针当作实参往函数传递，在函数内计数会加一，执行完毕会恢复；
     *  3.作为函数的返回值，在函数内计数会加一，如果有变量接收返回值，则保持，否则会恢复；
     * 计数减少的场景：
     *  1.
     */
}

void myFunc1(shared_ptr<int> p)
{
    cout << "myFunc1 use_count=" << p.use_count() << endl;
}

shared_ptr<int> myFunc2(shared_ptr<int> p)
{
    cout << "myFunc2 use_count=" << p.use_count() << endl;
    return p;
}

template<typename T>
shared_ptr<int> makes(T value)
{
    return std::make_shared<T>(value);
}