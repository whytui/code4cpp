/*
* 作者：刘时明
* 时间：2020/5/31-21:28
* 作用：
*/
#include "ch09.h"

void ch09()
{
    auto *c=new DeriveCircle();
    c->setColor("白色");
    c->setFilled(true);
    c->setR(2.5);
    c->showInfo();
}