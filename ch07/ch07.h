/*
* 作者：刘时明
* 时间：2020/5/29-0:14
* 作用：
*/

#ifndef CODE4CPP_CH07_H
#define CODE4CPP_CH07_H

using namespace std;
#include <iostream>
#include "../utils/utils.h"

void ch07();

void write_file(const string *filePath);

vector<string> *read_file(const string *filePath);

void skip_stream();

void obj_stream();

struct ObjDemo{
private:
    // 4
    int age;
    // 4
    string idNo;
    // 4
    string name;

public:
    ObjDemo();
    ObjDemo(int age,string name);

    string getInfo() const;
};

ObjDemo::ObjDemo()
{}

ObjDemo::ObjDemo(int age, string name)
{
    this->name=name;
    this->age=age;
    this->idNo = to_string(rand());
}

string ObjDemo::getInfo() const
{
    string str;
    str.append(name).append(",").append(idNo).append(",").append(to_string(age));
    return str;
}

#endif