/**
* 作者：刘时明
* 时间：2020/11/8 0008-13:16
*/
#include <ctime>
#include "date.h"

utils::MyDate *utils::MyDate::now()
{
    return new MyDate(time(nullptr));
}

utils::MyDate::MyDate(long time)
{
    this->t = time;
}

long utils::MyDate::unix_time() const
{
    return this->t;
}


