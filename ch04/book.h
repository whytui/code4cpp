/*
* 作者：刘时明
* 时间：2020/5/24-12:23
* 作用：
*/

#ifndef CODE4CPP_BOOK_H
#define CODE4CPP_BOOK_H

using namespace std;

#include <string>

class Book
{
private:
    int id;

    string name;

    double price;

public:
    static const int NUMBER_NO = 1;

    void setId(int id);

    int getId();

    void setName(string name);

    string getName();

    double getPrice() const;

    void setPrice(double price);

    Book();

    Book(int id, string name, double price);
};

typedef Book Circle;

/**
 * C++ class和struct的区别
 * 1.默认成员权限区别，前者public，后者private；
 * 2.默认继承方式，前者public，后者private；
 * 3.前者可以定义模板参数，后者不行；
 * 4.前者访问成员使用->，后者使用.；
 *
 * C++中struct是对C语言实现的扩展，本质上大体与class相同
 */
struct Hello
{
public:
    unsigned int id;

    string show();
};


#endif //CODE4CPP_BOOK_H
