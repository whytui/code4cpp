/**
* 作者：刘时明
* 时间：2020/11/19 0019
*/
#ifndef CODE4CPP_MAIN_H
#define CODE4CPP_MAIN_H

#include <cstdio>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;

void create_thread();

void create_by_class();

void create_by_lambda();

void thread_print();

void future_demo();

void add_1_demo();

void add_2_demo();

void add_3_demo();

void test_mutex();

void notify_demo();

void promise_demo();

#endif //CODE4CPP_MAIN_H