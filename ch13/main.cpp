/**
* 作者：刘时明
* 时间：2020/11/19 0019
*/
#include "main.h"

void print_thread_info()
{
    cout << "当前线程ID=" << this_thread::get_id() << endl;
}

int main()
{
    print_thread_info();
    // future_demo();

    // add_1_demo();

//    add_2_demo();

    thread_print();

    sleep(2);
    return 0;
}