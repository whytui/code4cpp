//
// Created by 刘时明 on 2020/12/24.
//
#include <fcntl.h>
#include <cstdio>

int main()
{
    int fd = open("/Users/liushiming/CLionProjects/code4cpp/ch16/main.cpp", O_RDWR);
    printf("%d \n", fd);
    return 0;
}