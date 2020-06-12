/*
* 作者：刘时明
* 时间：2020/5/23-23:47
* 作用：
*/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include "ch02.h"

using namespace std;

void ch02()
{
    read_file("../resource/hello.java");

    write_file("../resource/hello.txt", "hello");
}








/**
 * 读文件
 */
void read_file(const string &filePath)
{
    ifstream input;
    input.open(filePath);
    string content;
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return;
    }
    // 全量读取
    stringstream buffer;
    buffer << input.rdbuf();
    cout << buffer.str();

    // 按行读取
    while (getline(input, content))
    {
        cout << content << endl;
    }

    // 按空格读取
    while (input >> content)
    {
        // input.eof() 返回false则为读取完毕
        cout << content << endl;
    }
    input.close();
}

void write_file(const string &filePath, const string &content)
{
    ofstream output;
    // 以写入、追加的方式打开文件，文件不存在会创建
    output.open(filePath, ios::out | ios::app);
    output << content;
    output.close();
}