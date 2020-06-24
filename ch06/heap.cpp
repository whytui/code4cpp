#include <iostream>

using namespace std;

/**
 * 内存对齐
 */
void memory_alignment()
{
    typedef class HeapDemo01
    {
        int a;
        long b;
        short c;
        char d;

    public:
        int hello(int a)
        {
            return 2*a;
        }
    } demo01;

    typedef class HeapDemo02
    {
        int a;
        short b;
        long c;
        char d;
    } demo02;
    cout << "char byte=" << sizeof(char) << endl;
    cout << "short byte=" << sizeof(short) << endl;
    cout << "int byte=" << sizeof(int) << endl;
    cout << "long byte=" << sizeof(long) << endl;
    cout << "demo01 byte=" << sizeof(demo01) << endl;
    cout << "demo02 byte=" << sizeof(demo02) << endl;
    cout << "demo01* byte=" << sizeof(demo01*) << endl;
    cout << "demo02* byte=" << sizeof(demo02*) << endl;
}