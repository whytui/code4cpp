/*
* 作者：刘时明
* 时间：2020/5/31-21:44
* 作用：
*/
#ifndef CODE4CPP_GEOMETRICOBJ_H
#define CODE4CPP_GEOMETRICOBJ_H

#include <string>

using namespace std;

class GeometricObj
{
private:
    string color;
    bool filled;

public:
    // 定义一个纯虚函数
    virtual const double &area() const =0;

    virtual void showInfo() const =0;

    const string &getColor() const;

    void setColor(const string &color);

    bool isFilled() const;

    void setFilled(bool filled);
};


#endif
