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
    string src = R"(C:\Users\Administrator\Desktop\Dust)";
    string dist = R"(C:\Users\Administrator\Desktop\Dust2)";
    copy(dist,src);
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