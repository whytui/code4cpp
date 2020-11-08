/**
* 作者：刘时明
* 时间：2020/11/8 0008-13:16
*/
#include <ctime>
#include "date.h"

MyDate *MyDate::now()
{
    return new MyDate(time(nullptr));
}

MyDate::MyDate(long time)
{
    this->t = time;
}

long MyDate::unix_time() const
{
    return this->t;
}


