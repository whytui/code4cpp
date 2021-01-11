//
// Created by 刘时明 on 2020/12/24.
//
#include <iostream>

using namespace std;

class MyString
{
public:
    char *str;

    int *age;

    MyString() = default;

    MyString(const MyString &s)
    {
        str = s.str;
        age = s.age;
    }
};

void print(MyString str)
{
    printf("%p \n", &str.str);
    cout << str.str << endl;
    cout << *str.age << endl;

    decltype(str) remake;
    cout << std::is_same<decltype(remake), int>::value << endl;
}

int main()
{
    MyString s{};
    s.str = (char *) "hello";
    printf("%p \n", &s.str);
    s.age = new int(100);
    print(s);
    return 0;
}
