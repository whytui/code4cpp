//
// Created by 刘时明 on 2020/11/27.
//
#pragma once

/**
 * 单例模式
 */

#include <cstdio>

class Singleton
{
private:
    Singleton() = default;

    ~Singleton() = default;

    static Singleton* instance;

public:
    static const Singleton* getInstance();
};