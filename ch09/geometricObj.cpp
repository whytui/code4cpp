/*
* 作者：刘时明
* 时间：2020/5/31-21:44
* 作用：
*/
#include "geometricObj.h"

void GeometricObj::setColor(const string &color)
{
    GeometricObj::color = color;
}

bool GeometricObj::isFilled() const
{
    return filled;
}

void GeometricObj::setFilled(bool filled)
{
    GeometricObj::filled = filled;
}

const string &GeometricObj::getColor() const
{
    return color;
}
