/*
* 作者：刘时明
* 时间：2020/6/13-0:32
* 作用：
*/
#include "ch01.h"

/**
 * 获取时间戳
 */
void dateDemo()
{
    /**
     * time(0)返回当前时间戳
     */
    time_t t=time(nullptr);
    cout << "当前时间戳=" << t << endl;

    // 日期格式化
    static char str_time[100];
    struct tm *local_time = localtime(&t);
    strftime(str_time, sizeof(str_time), "%Y-%m-%d %H:%M:%S", local_time);
    printf ("Time: %s \n", str_time);

    // 转时间戳
    struct tm tm=*localtime(&t);
    strftime(str_time, 1000,"%Y-%m-%d %H:%M:%S", &tm);
    time_t ft=mktime(&tm);
    cout << "时间戳=" << ft << endl;
}