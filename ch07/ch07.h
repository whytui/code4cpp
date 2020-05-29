/*
* 作者：刘时明
* 时间：2020/5/29-0:14
* 作用：
*/
#ifndef CODE4CPP_CH07_H
#define CODE4CPP_CH07_H

#include <iostream>

using namespace std;

void ch07();

void write_file(const string *filePath);

vector<string> *read_file(const string *filePath);

void copy_file(const string *dist,const string *src);

void copy(const string *dist, const string *src);

void make_dirs(const string *dirs);

void getFiles(string path, vector<string> *files);

#endif //CODE4CPP_CH07_H