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

void char_arr_string()
{
    char c[] = "hello";
    string str = "hello";
    cout << c << endl;
    cout << str.c_str() << endl;

    // 由于字符串以 '\0' 结尾，所以实际最大长度会减一
    char maxLen[5] = "hell";
    char *pointStr = (char *) "hello world";

    cout << *(pointStr + 1) << endl;
    // *(pointStr + 1) = '2';
    cout << pointStr << endl;
    pointStr = maxLen;
    cout << *pointStr << endl;
}

/**
 * 字符串基本常用操作
 */
void string_base_opt()
{
    char str1[10] = "hello";
    char str2[10];
    // 将str1的值复制给str1
    strcpy(str2, str1);
    cout << str2 << endl;


    float pi = 3.14F;
    // 数值转字符串
    string str = to_string(pi);
    // 字符串转数值
    double pi_d = atof(str.c_str());
    cout << pi_d << endl;
    cout << atoi(str.c_str()) << endl;

    // 比较字符串内容是否相等
    if (!strcmp(str1, str2))
    {
        cout << "str1 == str2" << endl;
    } else
    {
        cout << "str1 != str2" << endl;
    }

    // 字符串格式化
    char forMate[1];
    int result = sprintf(forMate, "%s%.4f", str2, pi);
    cout << "result=" << result << endl;
    cout << forMate << endl;

    // GBK编码下遍历包括中文的字符
    char *c = (char *) "hello,你好";
    for (int i = 0; i < strlen(c); ++i)
    {
        if (c[i] > 0)
        {
            printf("%c \n", c[i]);
        } else
        {
            printf("%c%c \n", c[i], c[i + 1]);
            i++;
        }
    }
}