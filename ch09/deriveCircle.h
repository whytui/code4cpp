/*
* 作者：刘时明
* 时间：2020/5/31-21:45
* 作用：
*/
#ifndef CODE4CPP_DERIVECIRCLE_H
#define CODE4CPP_DERIVECIRCLE_H

#include "iostream"
#include "geometricObj.h"

using namespace std;

#define PI 3.1415926

class DeriveCircle: public GeometricObj
{
private:
    double r;

public:
    const double &area() const override;

    void showInfo() const override;

    double getR() const;

    void setR(double r);
};
#endif //CODE4CPP_DERIVECIRCLE_H
