#include <iostream>
#include "main.h"

using namespace std;

void printArgs(int argc, char *argv[], bool skipFirst = true)
{
    for (int i = skipFirst; i < argc; ++i)
    {
        cout << argv[i] << endl;
    }
}

int main(int argc, char *argv[])
{
    char *c1 = (char *) "hello";
    char *c2 = (char *) "hello";

    if (c1 == c2)
    {
        cout << "ok" << endl;
    } else
    {
        cout << "no" << endl;
    }


    printArgs(argc, argv);
    cout << "Hello, World!" << endl;
    cout << "你" << "配" << "吗？" << endl;
    cout << 0xFF << endl;
    // ch12();
    return 0;
}
