/*
* 作者：刘时明
* 时间：2020/6/2-0:18
* 作用：
*/
#include <stdio.h>
#include <windows.h>
#include "ch11.h"

void ch11()
{
//    char *c = NULL;
//    scanf("%s", c);
    printf("开始 \n");
    HWND win = FindWindowA("TXGuiFoundation", "QQ");
    while (1)
    {
        POINT pt;
        pt.x = pt.y = 0;
        // 获取位置
        GetCursorPos(&pt);
        SetWindowPos(win, NULL, pt.x + 100, pt.y + 100,0, 0, 1);
        Sleep(50);
    }
}

