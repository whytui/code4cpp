/*
* 作者：刘时明
* 时间：2020/5/31-12:56
* 作用：
*/
#include <windows.h>
#include "key_board.h"

void start(const string &name)
{
    HWND hwnd = ::FindWindow(nullptr, name.c_str());
    ::PostMessage(hwnd, WM_KEYDOWN, VK_F5, 1);
    Sleep(50);
    ::PostMessage(hwnd, WM_KEYUP, VK_F5, 1);
}
