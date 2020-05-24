/*
* 作者：刘时明
* 时间：2020/5/23-23:47
* 作用：
*/
#include <cmath>
#include <cstdio>
#include <iostream>
#include <ctime>
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
 * 基本数学函数
 */
void math_demo()
{
    double PI = M_PI;
    printf("%lf\n", sqrt(PI));

    printf("%lf\n", sin(PI));
    printf("%lf\n", cos(PI));

    cout << "向上取整=" << ceil(PI) << endl;
    cout << "向下取整=" << floor(PI) << endl;

    double ma = max(PI, M_E);
    double mi = min(PI, M_E);
    cout << "最大值=" << ma << endl;
    cout << "最小值=" << mi << endl;
}

/**
 * 字符
 */
void char_demo()
{
    int a = 'a';
    int z = 'z';
    int A = 'A';
    int Z = 'Z';
    cout << a << endl;
    cout << z << endl;
    cout << A << endl;
    cout << Z << endl;
    // 不设置种子的话每次生成重复的值
    srand(time(nullptr));
    // 生成随机字符
    for (int i = 0; i < 10; ++i)
    {
        int temp = rand();
        if (temp % 2)
        {
            cout.put((char) (temp % 26 + a));
        } else
        {
            cout.put((char) (temp % 26 + A));
        }
    }
    cout << endl;
}

/**
 * 字符串
 */
void string_demo()
{
    cout << "输入你的名字：" << endl;
    // 使用char数组达到Sting的效果
    char *charArr[10];
    scanf("%s", &charArr);
    printf("你好！%s\n", charArr);

    string name;
    // 读取字符串输入
    // scanf("%s",name.c_str());
    // cin >> name; 以空白符为结束
    // getline(cin,name,'\n'); 以换行为结束

    string str = "hello world!";

    str.append(" by lsm");
    // str.clear();
    change_string(&*&*(&str));

    cout << str << endl;
    cout << "str长度=" << str.length() << endl;
    cout << "str容量=" << str.capacity() << endl;

    printf("%s\n", str.c_str());

    cout << &str << endl;
}

/**
 * 指针传递达到修改的目的，传入string&类型也可以达到相同作用
 * @param str
 */
void change_string(string *str)
{
    (*str).append(" end");
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