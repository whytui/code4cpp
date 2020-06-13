/*
* 作者：刘时明
* 时间：2020/6/13-19:59
* 作用：
*/
#include "ch02.h"

void fileWrite(const string &filePath, const string &content);

void skipWrite(const string &filePath, const string &content);

void write(const string &filePath, const string &content)
{
    fileWrite(filePath, content);

    skipWrite(filePath, content);
}

void fileWrite(const string &filePath, const string &content)
{
    ofstream output;
    // 以写入、追加的方式打开文件，文件不存在会创建
    output.open(filePath, ios::out | ios::app);
    output << content;
    output.close();
}

void skipWrite(const string &filePath, const string &content)
{
    ofstream output;
    // 以写入、追加的方式打开文件，文件不存在会创建
    output.open(filePath, ios::out | ios::app);
    output.seekp(10, ios::beg);
    cout << "当前位置=" << output.tellp() << endl;
    output << content;
    output.close();
}