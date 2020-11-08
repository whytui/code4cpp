/**
* 作者：刘时明
* 时间：2020/11/8 0008-17:33
*/
#include <cstring>
#include "file.h"

Long utils::MyFile::length() const
{
    return this->len;
}

utils::MyFile::MyFile(string file_path)
{
    this->file_path = move(file_path);
    // 初始化文件信息
    this->initStat();
}

string utils::MyFile::path() const
{
    return this->file_path;
}

utils::MyFile::~MyFile()
{

}

bool utils::MyFile::exist() const
{
    return this->exist_flag;
}

void utils::MyFile::initStat()
{
    // 文件是否存在
    if (access(this->file_path.c_str(), F_OK) != -1)
    {
        this->exist_flag = true;
        ifstream in(this->file_path.c_str());
        in.seekg(0, std::ios::end);
        this->len = in.tellg();
        in.close();
    } else
    {
        this->exist_flag = false;
        this->len = 0;
    }
}

void utils::MyFile::read_line(void (*func)(string))
{
    if (!this->exist())
    {
        throw "file not exist!!!";
    }
    ifstream in(this->file_path.c_str());
    if (!in.is_open())
    {
        throw "open file fail!!!";
    }
    string content;
    while (getline(in, content))
    {
        func(content);
    }
    in.close();
}

char *utils::MyFile::read_all_bytes()
{
    if (!this->exist())
    {
        throw "file not exist!!!";
    }
    char *buff = new char[this->length()];
    ifstream in(this->path().c_str(), ios::binary);
    if (!in.is_open())
    {
        throw "open file fail!!!";
    }
    char *temp = new char[MAX_BYTE_LENGTH];
    int start = 0;
    while (true)
    {
        in.read(temp, MAX_BYTE_LENGTH);
        if (in.gcount() == 0)
        {
            break;
        }
        memcpy(buff + (start * MAX_BYTE_LENGTH), temp, MAX_BYTE_LENGTH);
        start++;
    }
    in.close();
    delete[] temp;
    return buff;
}

string utils::MyFile::name() const
{
    int pos = this->file_path.find_last_of('/');
    if (pos > 0)
    {
        return this->file_path.substr(pos + 1);
    }
    return this->file_path;
}
