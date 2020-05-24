/*
* 作者：刘时明
* 时间：2020/5/24-17:16
* 作用：
*/
#include "object.h"
#include <iostream>

using namespace std;

void Student::show()
{
    cout << "ID=" << ID << endl;
    cout << "CODE=" << CODE << endl;
    cout << "姓名=" << name << endl;
    cout << "性别=" << (gender == Men ? "男" : gender == WoMen ? "女" : nullptr) << endl;
}

Student::Student(string name, Gender gender)
{
    this->gender = gender;
    this->name = move(name);
}

const string &Student::getName() const
{
    return name;
}

void Student::setName(const string &name)
{
    Student::name = name;
}
