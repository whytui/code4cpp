//
// Created by Administrator on 2021/7/17.
//
#include <iostream>

class X
{
public:
    int m_i;
    int *p_i;

    X(const X &tmp)
    {
        m_i = tmp.m_i;
        p_i = new int(*tmp.p_i);
        printf("copy build func exec!\n");
    }

    X() : X(0)
    {
        // 委托构造函数，会先执行 X(0)
        m_i = -1;
    }

    ~X()
    {
        delete p_i;
        printf("~X() exec!\n");
    }

    X(int value) : m_i(value)
    {
        p_i = new int(100);
        printf("build X(int) exec!\n");
    }
};

void copyDemo()
{
    X x1(1000);
    std::cout << "----------------------" << std::endl;
    X x2 = 1000;
    std::cout << "----------------------" << std::endl;
    X x3 = X(1000);
    std::cout << "----------------------" << std::endl;
    X x4 = (X) 1000;

    X x01;
    x01.m_i = 150;

    X x02(x01);
    std::cout << x02.m_i << std::endl;
}
