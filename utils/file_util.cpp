using namespace std;

#include <dirent.h>
#include <cstring>
#include <fstream>
#include "file_util.h"

/**
 * 获取目录下的文件列表
 * @param root
 * @param files
 */
void file_list(const string &path, vector<string> *files)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path.c_str())) != nullptr)
    {
        while ((ent = readdir(dir)) != nullptr)
        {
            if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
            {
                continue;
            }
            files->emplace_back(ent->d_name);
        }
        closedir(dir);
    }
}

/**
 * 获取目录下的文件列表
 * @param root
 * @return
 */
vector<string> *file_list(const string &path)
{
    auto *list=new vector<string>;
    file_list(path, list);
    return list;
}

/**
 * 创建目录,支持多级目录创建
 * @param dirs
 */
void make_dirs(const string &dirs)
{
    int index;
    string temp = dirs;
    string appendStr;
    while ((index = temp.find('\\')) != -1)
    {
        string sub = temp.substr(0, index);
        if (appendStr.length() != 0)
        {
            appendStr.append("\\");
        }
        appendStr.append(sub);
        if (_access(appendStr.c_str(), 0) == -1)
        {
            mkdir(appendStr.c_str());
        }
        temp = temp.substr(index + 1, temp.length());
    }
    // 追加最后一级
    appendStr.append("\\").append(temp.substr(index + 1, temp.length()));
    if (_access(appendStr.c_str(), 0) == -1)
    {
        mkdir(appendStr.c_str());
    }
}

/**
 * 拷贝文件
 * @param dist
 * @param src
 */
void copy(const string &dist,const string &src)
{
    if(is_dir(src))
    {
        make_dirs(dist);
        auto v= file_list(src);
        for(auto &i:*v)
        {
            string dist_temp=dist;
            string src_temp=src;
            dist_temp.append("\\").append(i);
            src_temp.append("\\").append(i);
            if(is_dir(src_temp))
            {
                // 是目录
                copy(dist_temp, src_temp);
            } else
            {
                // 文件
                copy_file(dist_temp, src_temp);
            }
        }
        delete v;
    } else
    {
        copy_file(dist, src);
    }
}

/**
 * 使用二进制流完成文件拷贝
 * @param dist
 * @param src
 */
void copy_file(const string &dist, const string &src)
{
    fstream input(src, ios::in | ios::binary);
    fstream output(dist, ios::out | ios::binary);
    int size = 1024;
    while (true)
    {
        char arr[size];
        input.read(arr, size);
        int len = input.gcount();
        if (len == 0)
        {
            break;
        }
        output.write(arr, len);
    }
    input.close();
}

bool is_dir(const string &path)
{
    DIR *dir=opendir(path.c_str());
    bool result= dir!= nullptr;
    closedir(dir);
    return result;
}