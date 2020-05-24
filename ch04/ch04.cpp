/*
* 作者：刘时明
* 时间：2020/5/24-12:23
* 作用：
*/

#include "ch04.h"

void ch04()
{
    string str("application");

    Book *book = new Book();
    book->setId(10);
    cout << book->getId() << endl;

    auto *circle = new Circle(1, "Java编程思想", 3.14);
    cout << circle->getId() << endl;
    cout << circle->getName() << endl;

    Hello h = {14};
    h.id += 1;
    cout << "show=" << h.show() << endl;
}
