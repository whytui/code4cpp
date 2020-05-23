#include "win.h"

#pragma comment (lib, "User32.lib")

int WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow
)
{
    // 调用API函数 MessageBox
    MessageBox(NULL,
               TEXT("开始学习Windows编程"),
               TEXT("消息对话框"),
               MB_OK);
    return 0;
}