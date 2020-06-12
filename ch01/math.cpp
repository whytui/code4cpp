/*
* 作者：刘时明
* 时间：2020/6/13-0:55
* 作用：
*/
#include "ch01.h"

/**
 * 基本数学函数
 */
void math_demo()
{
    printf("%lf\n", sqrt(PI));

    printf("%lf\n", sin(PI));
    printf("%lf\n", cos(PI));

    cout << "圆周率=" << M_PI << endl;

    cout << "向上取整=" << ceil(PI) << endl;
    cout << "向下取整=" << floor(PI) << endl;

    double ma = max(PI, M_E);
    double mi = min(PI, M_E);
    cout << "最大值=" << ma << endl;
    cout << "最小值=" << mi << endl;
}

