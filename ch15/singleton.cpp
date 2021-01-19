//
// Created by 刘时明 on 2020/11/27.
//

#include "singleton.h"

Singleton *Singleton::instance = nullptr;

std::mutex Singleton::lock = std::mutex{};

const Singleton *Singleton::getInstance()
{
    if (instance == nullptr)
    {
        lock.lock();
        if (instance == nullptr)
        {
            instance = new Singleton;
        }
        lock.unlock();
    }
    return instance;
}

void check_singleton()
{
    auto obj1 = Singleton::getInstance();
    auto obj2 = Singleton::getInstance();

    printf("%p \n", obj1);
    printf("%p \n", obj2);
}