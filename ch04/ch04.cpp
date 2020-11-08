#include "ch04.h"

int main()
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

    union_demo();

    enum_demo();

    func();
    return 0;
}
