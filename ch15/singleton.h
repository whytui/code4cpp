//
// Created by 刘时明 on 2020/11/27.
//
#pragma once

/**
 * 单例模式
 */

#include <cstdio>
#include <mutex>

class Singleton
{
private:
    Singleton() = default;

    ~Singleton() = default;

    static Singleton* instance;

    static std::mutex lock;

public:
    static const Singleton* getInstance();
};