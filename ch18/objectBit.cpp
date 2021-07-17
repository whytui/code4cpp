//
// Created by Administrator on 2021/7/17.
//

#include <iostream>

class emptyClass
{
};

// C++中，空结构也会占用一个字节
struct emptyStruct
{
};

// 一个或者多个纯虚函数会占用4个字节（64位编译器则8字节）
class virtualObj
{
    virtual void say() = 0;
};


class virtualObj2
{
    virtual void say1() = 0;

    virtual void say2() = 0;

    virtual void say3() = 0;
};

void objectBit()
{
    std::cout << "empty class bit:" << sizeof(emptyClass) << std::endl;
    std::cout << "empty struct bit:" << sizeof(emptyStruct) << std::endl;
    std::cout << "virtual object bit:" << sizeof(virtualObj) << std::endl;
    std::cout << "virtual object bit:" << sizeof(virtualObj2) << std::endl;
}
