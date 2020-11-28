/**
* 作者：刘时明
* 时间：2020/8/9 0009-1:42
*/
#include "main.h"

int main(int argc, char **argv)
{
    cout << "hello" << endl;

    cout << get_timestamp() << endl;

    // ping("157.148.45.37");
    time_server(argc, argv);
    return 0;
}