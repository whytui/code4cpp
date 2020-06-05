#include <windows.h>

#pragma comment(linker, "/subsystem:windows /entry:mainCRTStartup")

void findA()
{
    int x=::MessageBox(NULL, TEXT("你确定执行吗？"), TEXT("操作提示"), 1);
    if (x==1)
    {
        // 确认关机
        system("shutdown /s /t 20");
    }

    while (true)
    {
        HWND win = FindWindowA("TXGuiFoundation", "QQ");
        POINT pt;
        pt.x = pt.y = 0;
        // 获取位置
        GetCursorPos(&pt);
        SetWindowPos(win, NULL, pt.x + 100, pt.y + 100,0, 0, 1);
        Sleep(10);
    }
}

