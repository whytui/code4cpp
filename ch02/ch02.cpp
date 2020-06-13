/*
* 作者：刘时明
* 时间：2020/5/23-23:47
* 作用：
*/
#include "ch02.h"

void read(const string &filePath);

void write(const string &filePath, const string &content);

void maze(const string &path);

void ch02()
{
    read("../resource/hello.java");
    // maze("../resource/maze.txt");
}