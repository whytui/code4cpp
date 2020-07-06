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
    printArgs(argc, argv);
    cout << "Hello, World!" << endl;
    cout << "Äã" << "Åä" << "Âð£¿" << endl;
    cout << 0xFF << endl;
    sort();
    return 0;
}
