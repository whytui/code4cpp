/*
* 作者：刘时明
* 时间：2020/6/13-19:58
* 作用：
*/
#include "ch02.h"

void readLine(const string &filePath);

void readChar(const string &filePath);

void readBuf(const string &filePath);

void repeatRead(const string &filePath);

void readSkip(const string &filePath);

void readByte(const string &filePath);

void objectStream();

/**
 * 读文件
 */
void read(const string &filePath)
{
    // readLine(filePath);
    // readChar(filePath);
    // readBuf(filePath);
    // repeatRead(filePath);
    //readSkip(filePath);
    readByte(filePath);
    objectStream();
}

/**
 * 按行读取
 *
 * @param filePath
 */
void readLine(const string &filePath)
{
    cout << endl << "逐行读取" << endl;
    ifstream input;
    input.open(filePath);
    string content;
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return;
    }
    // 默认按空格读取，指定getline按行读取
    while (getline(input, content))
    {
        cout << content << endl;
    }
    input.close();
}

/**
 * 按字符读取
 * @param filePath
 */
void readChar(const string &filePath)
{
    cout << endl << "逐个字符读取" << endl;
    ifstream input;
    input.open(filePath);
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return;
    }
    // 不跳过空格和换行
    input >> noskipws;
    char ch;
    while (input >> ch)
    {
        printf("%c", ch);
    }
    input.close();
}

/**
 * 全量读取
 * @param filePath
 */
void readBuf(const string &filePath)
{
    cout << endl << "全量读取" << endl;
    ifstream input;
    input.open(filePath);
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return;
    }
    // 全量读取
    stringstream buffer;
    buffer << input.rdbuf();
    cout << buffer.str() << endl;
    input.close();
}

/**
 * 重复读
 * @param filePath
 */
void repeatRead(const string &filePath)
{
    cout << endl << "第一次读" << endl;
    ifstream input;
    input.open(filePath);
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return;
    }
    stringstream buffer1;
    buffer1 << input.rdbuf();
    cout << buffer1.str() << endl;
    input.clear();
    input.seekg(0);

    cout << endl << "第二次读" << endl;
    stringstream buffer2;
    buffer2 << input.rdbuf();
    cout << buffer2.str() << endl;
    input.close();
}

/**
 * 随机访问流
 * @param filePath
 */
void readSkip(const string &filePath)
{
    ifstream input;
    input.open(filePath);
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return;
    }
    // 跳到Hello所在的位置，即开始位置后移13
    input.seekg(13, ios::beg);
    cout << "当前位置=" << input.tellg() << endl;
    string content;
    // 输出10遍重复的‘Hello’
    for (int i = 0; i < 10; ++i)
    {
        input >> content;
        cout << content << endl;
        // 读完之后获取当前位置
        int currIndex = input.tellg();
        // 跳回去重复读
        input.seekg(-(currIndex - 13), ios::beg);
    }
    input.close();
}

/**
 * 二进制流读取
 * @param filePath
 */
void readByte(const string &filePath)
{
    ifstream input;
    input.open(filePath, ios::binary);
    if (!input.is_open())
    {
        printf("读取不到指定文件!!!\n");
        return;
    }
    int size = 8;
    while (true)
    {
        char arr[size];
        input.read(arr, size);
        // 如果读取到的长度为0，则证明读取完毕了
        if (input.gcount() == 0)
        {
            break;
        }
        cout << "读取一次，内容=" << arr << endl;
    }
    input.close();
}

class ObjDemo
{
public:
    int age;
    string name;

    ObjDemo(int age, string name);

    string getInfo() const;
};

ObjDemo::ObjDemo(int age, string name)
{
    this->age = age;
    this->name = name;
}

string ObjDemo::getInfo() const
{
    string str;
    str.append(name).append(",").append(to_string(age));
    return str;
}

/**
 * 对象流
 */
void objectStream()
{
    cout << "ObjDemo size=" << sizeof(ObjDemo) << endl;
    ObjDemo demo1(23, "lsm");
    ObjDemo demo2(23, "lw");

    fstream binaryIo("../resource/data", ios::out | ios::binary);
    binaryIo.write(reinterpret_cast<char *>(&demo1), sizeof(ObjDemo));
    binaryIo.write(reinterpret_cast<char *>(&demo2), sizeof(ObjDemo));
    binaryIo.close();

    ObjDemo newDemo1(0, "");
    binaryIo.open("../resource/data", ios::in | ios::binary);
    binaryIo.read(reinterpret_cast<char *>(&newDemo1), sizeof(ObjDemo));
    cout << newDemo1.getInfo() << endl;

    ObjDemo newDemo2(0, "");
    binaryIo.read(reinterpret_cast<char *>(&newDemo2), sizeof(ObjDemo));
    cout << newDemo2.getInfo() << endl;
}