/**
* 作者：刘时明
* 时间：2020/11/19 0019
*/
#include "main.h"

void print_thread_info()
{
    cout << "当前线程ID=" << this_thread::get_id() << endl;
}

struct demo
{
    int id;
};

demo* get_i()
{
    int id=100;
    printf("%p\n",&id);
    demo *d=new demo;
    d->id=id;
    printf("%p\n",&d->id);
    return d;
}

int main()
{
    auto *d=get_i();
    printf("%p\n",&d->id);


    print_thread_info();

    // future_demo();

    // add_1_demo();

    add_2_demo();

    //notify_demo();

    promise_demo();
    return 0;
}