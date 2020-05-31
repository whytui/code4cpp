/*
* 作者：刘时明
* 时间：2020/5/31-21:45
* 作用：
*/
#include "deriveCircle.h"

const double &DeriveCircle::area() const
{
    double area=r * r * PI;
    double *result=&area;
    return *result;
}

double DeriveCircle::getR() const
{
    return r;
}

void DeriveCircle::setR(double r)
{
    DeriveCircle::r = r;
}

void DeriveCircle::showInfo() const
{
    cout << "圆" << endl;
    cout << "color=" << this->getColor() << endl;
    cout << "filled=" << this->isFilled() << endl;
    cout << "面积=" << this-> area() << endl;
}
