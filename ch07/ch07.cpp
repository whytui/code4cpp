/*
* 作者：刘时明
* 时间：2020/5/29-0:14
* 作用：
*/

#include <fstream>
#include <vector>
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
    string dist = R"(C:\Users\Administrator\Desktop\timg_2.png)";
    string src = R"(C:\Users\Administrator\Desktop\timg_1.png)";
    copy_file(&dist, &src);
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
    int size = 10;
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