#include <iostream>

using namespace std;

struct FreeDemo
{
public:
    FreeDemo()
    {
        cout << "FreeDemo 构造函数" << endl;
    }

    ~FreeDemo()
    {
        cout << "FreeDemo 析构函数" << endl;
    }

    void test()
    {
        cout << "test" << endl;
    }
};



void freeDemo()
{
    cout << "*********" << endl;
    // malloc 返回值就是void*类型
    // 发现传负数会编译报错，但执行正常，
    // linux man文档关于malloc(0)的解释
    // malloc() allocates size bytes and returns a pointer to the allocated memory.
    // The memory is not cleared. If size is 0, then malloc() returns either NULL,
    // or a unique pointer value that can later be successfully passed to free()
    FreeDemo *f1 =(FreeDemo*)malloc(0);
    if(f1 == NULL)
    {
        cout << "空值" << endl;
    }
    // FreeDemo *f1 =(FreeDemo*)malloc(sizeof(FreeDemo*));
    f1->test();
    free(f1);

    FreeDemo *f2=new FreeDemo();
    f2->test();
    delete(f2);
    // 此时访问f1、f2结果正常，delete、free只是通知操作系统此内存可以被回收
    f1->test();
    f2->test();
}