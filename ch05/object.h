/*
* 作者：刘时明
* 时间：2020/5/24-17:16
* 作用：
*/
#ifndef CODE4CPP_OBJECT_H
#define CODE4CPP_OBJECT_H

#include <string>

using namespace std;

class Object
{

};

enum Gender
{
    Men, WoMen
};

class Student
{
public:
    // 不同于Java，静态成员在类定义中不可以初始化
    // 类定义的实质是数据类型的定义，数据类型是没有存储空间的
    static string ID;
    static int CODE;

private:
    string name;
    Gender gender;

public:
    Student(string name, Gender gender);

    void show();

    const string &getName() const;

    void setName(const string &name);
};

#endif //CODE4CPP_OBJECT_H
