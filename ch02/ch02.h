/*
* 作者：刘时明
* 时间：2020/5/23-23:47
* 作用：
*/

#ifndef CODE4CPP_CH02_H
#define CODE4CPP_CH02_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <utility>

using namespace std;

void read(const string &filePath);

void write(const string &filePath, const string &content);

void maze(const string &path);

void binary_read();

void binary_write();

string GenerateUUID();

#endif //CODE4CPP_CH02_H
