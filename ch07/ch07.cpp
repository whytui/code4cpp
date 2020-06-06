/*
* 作者：刘时明
* 时间：2020/5/29-0:14
* 作用：
*/

#include <fstream>
#include <vector>
#include "ch07.h"

void back_read();

void ch07()
{
    back_read();
}

void back_read()
{
    fstream input("../resource/锦瑟.txt", ios::in);
    if (input.fail())
    {
        cout << "文件不存在!!!" << endl;
        return;
    }
    char c;
    while (!input.eof())
    {
        input.get(c);
        // input.seekg(-1);
        cout << c << endl;
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
 * 对象流
 */
void obj_stream()
{
    cout << "ObjDemo size=" << sizeof(ObjDemo) << endl;
    ObjDemo demo1(23, "lsm");
    ObjDemo demo2(23, "lw");

    fstream binaryIo("../resource/data", ios::out | ios::binary);
    binaryIo.write(reinterpret_cast<char *>(&demo1), sizeof(ObjDemo));
    binaryIo.write(reinterpret_cast<char *>(&demo2), sizeof(ObjDemo));
    binaryIo.close();

    ObjDemo newDemo1;
    binaryIo.open("../resource/data", ios::in | ios::binary);
    binaryIo.read(reinterpret_cast<char *>(&newDemo1), sizeof(ObjDemo));
    cout << newDemo1.getInfo() << endl;

    ObjDemo newDemo2;
    binaryIo.read(reinterpret_cast<char *>(&newDemo2), sizeof(ObjDemo));
    cout << newDemo2.getInfo() << endl;
}

/**
 * 随机流
 */
void skip_stream()
{
    fstream input("../resource/锦瑟.txt", ios::in);
    if (input.fail())
    {
        cout << "文件不存在!!!" << endl;
        return;
    }
    char c;
    int index = 0;
    bool flag = false;
    while (!input.eof())
    {
        input >> c;
        // 找到 - 的位置
        if (c == '-')
        {
            flag = true;
            break;
        }
        index++;
    }
    if (!flag)
    {
        cout << "找不到标记" << endl;
    }
    fstream output("../resource/锦瑟.txt", ios::out | ios::in | ios::binary);
    output.seekp(index + 4, ios::beg);
    // 取代占位符
    output << "李商隐";
}