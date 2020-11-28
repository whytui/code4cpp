//
// Created by 刘时明 on 2020/11/27.
//
#include "observer.h"
#include <cstdio>

class User1 : public Observer
{
public:
    User1()
    {
        this->value = 1;
    }

    ~User1() override
    {
        printf("User1 释放 \n");
    }

    void update(void *obj) override
    {
        printf("User1 Observer,obj=%s,value=%d \n", obj, this->value);
    }
};

class User2 : public Observer
{
public:
    User2()
    {
        this->value = 2;
    }

    ~User2() override
    {
        printf("User2 释放 \n");
    }

    void update(void *obj) override
    {
        printf("User2 Observer,obj=%s,value=%d \n", obj, this->value);
    }
};


void observer_demo()
{
    auto *u1 = new User1;
    auto *u2 = new User2;

    auto *observerAble = new ObserverAble();
    // 注册观察者
    observerAble->attach(u1);
    observerAble->attach(u2);

    observerAble->notify((void *) "哈哈");
    observerAble->notify((void *) "呵呵");

    delete observerAble;
}