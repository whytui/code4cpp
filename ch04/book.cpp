/*
* 作者：刘时明
* 时间：2020/5/24-12:23
* 作用：
*/

#include "book.h"

Book::Book()
{

}

Book::Book(int id, string name, double price)
{
    this->id = id;
    this->name = name;
    this->price = price;
}

void Book::setId(int id)
{
    this->id = id;
}

int Book::getId()
{
    return this->id;
}

void Book::setName(string name)
{
    this->name = name;
}

string Book::getName()
{
    return this->name;
}

double Book::getPrice() const
{
    return price;
}

void Book::setPrice(double price)
{
    Book::price = price;
}

string Hello::show()
{
    return "hello!";
}
