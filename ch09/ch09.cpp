/*
* 作者：刘时明
* 时间：2020/5/31-21:28
* 作用：
*/
#include "ch09.h"

void cast1(GeometricObj &obj);

GeometricObj& cast2(DeriveCircle &circle);

void ch09()
{
    auto *c=new DeriveCircle();
    c->setColor("白色");
    c->setFilled(true);
    c->setR(2.5);
    c->showInfo();

    // 带有纯虚函数的类是抽象类，不可以被实例化

    // auto *g=new GeometricObj();
    cast1(*c);

    c->setR(100);
    cast2(*c).showInfo();
}

/**
 * 类型转换
 * dynamic_cast只用于多态类型的指针或者引用上使用，也就是必须包括纯虚函数
 * static_cast在运行时检查类型转换是否成功，作用在编译时
 * @param obj
 */
void cast1(GeometricObj &obj)
{
    cout << "cast" << endl;
    obj.showInfo();
    auto cast=dynamic_cast<DeriveCircle&>(obj);
    cout << "r="<< cast.getR() << endl;
}

GeometricObj& cast2(DeriveCircle &circle)
{
    return circle;
}