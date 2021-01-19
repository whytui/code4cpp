//
// Created by 刘时明 on 2021/1/19.
//
#include "ch02.h"
#include <dirent.h>

void dir_demo()
{
    DIR *dir = opendir("/Users/liushiming/Desktop/维修原型20201229/");
    dirent *ent;
    while ((ent = readdir(dir)) != nullptr)
    {
        if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
        {
            continue;
        }
        /**
         * 0 未知类型
         * 1 管道
         * 2 字符设备文件
         * 4 目录
         * 6 块设备文件
         * 8 普通文件
         * 10 连接文件
         * 12 套接字类型
         */
        printf("文件名=%s，文件类型=%d \n", ent->d_name, ent->d_type);
    }
    closedir(dir);
}