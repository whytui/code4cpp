/**
* 作者：刘时明
* 时间：2020/11/8 0008-17:33
*/
#ifndef CODE4CPP_FILE_H
#define CODE4CPP_FILE_H

#include "common.h"
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

namespace utils
{
#define MAX_BYTE_LENGTH 1024

    class MyFile
    {
    private:
        mutable bool exist_flag;
        Long len;
        string file_path;

    private:
        void initStat();

    public:
        MyFile(string file_path);

        ~MyFile();

        // 文件长度
        Long length() const;

        // 文件路径
        string path() const;

        // 文件名称
        string name() const;

        // 文件是否存在
        bool exist() const;

        // 一行行读取
        void read_line(void(*func)(string));

        // 读取文件所有字节数据
        char *read_all_bytes();
    };
}
#endif //CODE4CPP_FILE_H
