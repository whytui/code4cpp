/*
* 作者：刘时明
* 时间：2020/6/13-1:02
* 作用：
*/
#include "ch01.h"

void change_string(string *str);

/**
 * 字符基本使用
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