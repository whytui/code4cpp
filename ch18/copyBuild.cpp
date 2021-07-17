//
// Created by Administrator on 2021/7/17.
//
#include <iostream>

class CopyBuild1
{
public:
    std::string name;

    int data;

    int *p;

    explicit CopyBuild1() = default;

    // 此种写法等同于默认
    CopyBuild1(const CopyBuild1 &) = default;
};

class CopyBuild2
{
public:
    std::string name;

    int data;

    int *p;

    explicit CopyBuild2() = default;

    CopyBuild2(const CopyBuild2 &build)
    {
        printf("src prt => %p\n", &build);
        // 拷贝后的属性值是随机的，需要手动赋值
        this->name = build.name;
        this->data = build.data;
        this->p = new int(*build.p);
    }

    ~CopyBuild2()
    {
        delete this->p;
    }
};

void copyBuildDemo()
{
    int p = 100;
    CopyBuild1 build1{};
    build1.data = 100;
    build1.p = &p;
    build1.name = "lsm";

    // 调用拷贝构造函数，会拷贝所有的属性，包括指针
    CopyBuild1 build2 = build1;
    std::cout << build2.data << std::endl;
    std::cout << build2.name << std::endl;
    printf("%p - %p\n", build1.p, build2.p);

    std::cout << "----------------------" << std::endl;

    CopyBuild2 build3{};
    printf("src prt => %p\n", &build3);
    build3.data = 100;
    build3.p = new int(100);
    build3.name = "lsm";

    CopyBuild2 build4 = build3;
    std::cout << build4.data << std::endl;
    std::cout << build4.name << std::endl;
    printf("%p - %p\n", build3.p, build4.p);
}