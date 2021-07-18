#include <lang.h>
#include <io.h>
#include <concurrent.h>
#include "main.h"

using namespace std;

void printArgs(int argc, char *argv[], bool skipFirst = true)
{
    for (int i = skipFirst; i < argc; ++i)
    {
        cout << argv[i] << endl;
    }
}

char* testFunc()
{
    printf("hello world!\n");
}

int main(int argc, char *argv[])
{
    printArgs(argc, argv);
    cout << "Hello, World!" << endl;
    cout << "你" << "配" << "吗？" << endl;
    cout << 0xFF << endl;

    auto *date = utils::MyDate::now();
    cout << date->unix_time() << endl;

    auto *file = new utils::MyFile("../resource/hello.java");

    cout << file->length() << endl;

    cout << file->name() << endl;

    ThreadPool threadPool;
    for (int i = 0; i < 100; ++i)
    {
        threadPool.add_task(testFunc);
    }
    sleep(10);
    return 0;
}
