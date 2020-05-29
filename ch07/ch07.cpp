/*
* 作者：刘时明
* 时间：2020/5/29-0:14
* 作用：
*/

#include <fstream>
#include <vector>
#include <dirent.h>
#include <cstring>
#include "ch07.h"

void ch07()
{
    string path = "hello.txt";
    // write_file(&path);
    vector<string> *v = read_file(&path);

    for (auto &i : *v)
    {
        cout << i << endl;
    }
    string dist = R"(C:\Users\Administrator\Desktop\starts\sst\bat\www\fuck\com)";
    string src = R"(C:\Users\Administrator\Desktop\timg_1.png)";
    // copy_file(&dist, &src);
    // make_dirs(&dist);
    // copy(&dist, &src);
    v->clear();
    getFiles(R"(C:\Users\Administrator\Desktop)", v);
    for (auto &i : *v)
    {
        cout << i << endl;
    }
}

/**
 * 文本流
 * @param filePath
 */
void write_file(const string *filePath)
{
    // 以写入、追加的方式打开文件，文件不存在会创建
    ofstream output(*filePath, ios::out | ios::app);

    output << "hello" << endl;

    output << "go to here!" << endl;

    output.close();
}

/**
 * 文本流
 * @param filePath
 */
vector<string> *read_file(const string *filePath)
{
    auto *v = new vector<string>();
    ifstream input(*filePath);
    if (input.fail())
    {
        cout << "文件不存在!!!" << endl;
        return v;
    }
    string str;
    while (getline(input, str, '\n'))
    {
        v->push_back(str);
    }
    input.close();
    return v;
}

/**
 * 使用二进制流完成文件拷贝
 * @param dist
 * @param src
 */
void copy_file(const string *dist, const string *src)
{
    fstream input(*src, ios::in | ios::binary);
    fstream output(*dist, ios::out | ios::binary);
    int size = 1024;
    while (true)
    {
        char arr[size];
        input.read(arr, size);
        cout << "写入一次," << size << endl;
        int len = input.gcount();
        if (len == 0)
        {
            break;
        }
        output.write(arr, len);
    }
    input.close();
}

void copy(const string *dist, const string *src)
{
    cout << mkdir(dist->c_str()) << endl;
    // 判断是否为目录
//    DIR *dir = opendir(reinterpret_cast<const char *>(src));
//    if (dir == NULL)
//    {
//        // 不是目录
//        copy_file(dist, src);
//    } else
//    {
//        //创建目录
//        mkdir(dist->c_str());
//        struct dirent *dp;
//        while ((dp = readdir(dir)) != NULL)
//        {
//            if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0)
//            {
//                continue;
//            }
//        }
//    }
//    fstream input(*src, ios::in | ios::binary);
}

/**
 * 支持多级目录创建
 * @param dirs
 */
void make_dirs(const string *dirs)
{
    int index;
    string temp = *dirs;

    cout << temp << endl;
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

void getFiles(string path, vector<string> *files)
{
    //文件句柄
    long hFile = 0;
    //文件信息
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            //如果是目录,迭代之
            //如果不是,加入列表
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            } else
            {
                files->push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
            cout << _findnext(hFile, &fileinfo) << endl;
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}