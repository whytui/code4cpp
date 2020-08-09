#include <windows.h>
#include <string>
#include "win.h"
#include "key_board.h"

#define CLASSNAME "窗口"
//  #pragma comment (lib, "User32.lib")

LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam);

ATOM MyRegisterClass(HINSTANCE hInstance);

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);

int show_frame(HINSTANCE hInstance);

void exec_notepad();

/**
 * WinMain 是windows窗口应用的主函数
 * @param hInstance 应用程序实例句柄
 * @param hPrevInstance 同一个文件创建的上一个实例的句柄，win16的遗留，win32弃用
 * @param lpCmdLine 主函数命令行参数
 * @param nCmdShow 进程显示方式，最大化、最小化、隐藏等
 * @return
 */
int WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow
)
{
    exec_notepad();
    // show_frame(hInstance);
    return 0;
}

/**
 * 显示窗口
 * @param hInstance
 * @return
 */
int show_frame(HINSTANCE hInstance)
{
    MSG msg;
    BOOL bRet;
    // 注册窗口类
    MyRegisterClass(hInstance);

    // 创建窗口并显示窗口
    if (!InitInstance(hInstance, SW_SHOWNORMAL))
    {
        return FALSE;
    }

    // 消息循环
    // 获取属于自己的消息并进行分发
    while ((bRet = GetMessage(&msg, nullptr, 0, 0)) != 0)
    {
        if (bRet == -1)
        {
            // handle the error and possibly exit
            break;
        } else
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return msg.wParam;
}

/**
 * 消息调用记事本
 */
void exec_notepad()
{
    auto *d = new CMsgTestDlg();
    d->OnExec();
    // d->OnClose();
    d->OnEditWnd();
    // d->OnGetWnd();
    start("消息测试");
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEX WndCls;
    // 填充结构体为0
    ZeroMemory(&WndCls, sizeof(WNDCLASSEX));
    // cbSize是结构体大小
    WndCls.cbSize = sizeof(WNDCLASSEX);
    // lpfnWndProc是窗口过程地址
    WndCls.lpfnWndProc = WindowProc;
    // hInstance是实例句柄
    WndCls.hInstance = hInstance;
    // lpszClassName是窗口类类名
    WndCls.lpszClassName = CLASSNAME;
    // style是窗口类风格
    WndCls.style = CS_HREDRAW | CS_VREDRAW;
    // hbrBackground是窗口类背景色
    WndCls.hbrBackground = (HBRUSH) COLOR_WINDOWFRAME + 1;
    // hCursor是鼠标句柄
    WndCls.hCursor = LoadCursor(NULL, IDC_ARROW);
    // hIcon是图标句柄
    WndCls.hIcon = LoadIcon(NULL, IDI_QUESTION);
    // 其他
    WndCls.cbClsExtra = 0;
    WndCls.cbWndExtra = 0;
    return RegisterClassEx(&WndCls);
}

LRESULT CALLBACK WindowProc(
        HWND hwnd,
        UINT uMsg,
        WPARAM wParam,
        LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hDC;
    RECT rt;
    const CHAR *pszDrawText = "Hello Windows Program.";
    // char *pszDrawText = "Hello Windows Program.";
    switch (uMsg)
    {
        case WM_PAINT:
        {
            hDC = BeginPaint(hwnd, &ps);
            GetClientRect(hwnd, &rt);
            DrawTextA(hDC,
                      pszDrawText, strlen(pszDrawText), &rt,
                      DT_CENTER | DT_VCENTER | DT_SINGLELINE);
            EndPaint(hwnd, &ps);
            break;
        }
        case WM_CLOSE:
        {
            if (IDYES == MessageBox(hwnd,
                                    "是否退出程序", "MyFirstWin", MB_YESNO))
            {
                DestroyWindow(hwnd);
                PostQuitMessage(0);
            }
            break;
        }
        default:
        {
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        }
    }
    return 0;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    HWND hWnd = NULL;

    // 创建窗口
    hWnd = CreateWindowEx(WS_EX_CLIENTEDGE,
                          CLASSNAME,
                          "MyFirstWindow",
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          NULL, NULL, hInstance, NULL);

    if (NULL == hWnd)
    {
        return FALSE;
    }
    // 显示窗口
    ShowWindow(hWnd, nCmdShow);
    // 更新窗口
    UpdateWindow(hWnd);
    return TRUE;
}

void CMsgTestDlg::OnClose()
{
    HWND hwnd = ::FindWindow("Notepad", nullptr);
    if (hwnd == nullptr)
    {
        // 调用API函数 MessageBox
        MessageBox(nullptr,
                   TEXT("没有找到记事本"),
                   TEXT("提示"),
                   MB_OK);
    } else
    {
        WPARAM null_point = 0;
        ::SendMessage(hwnd, WM_CLOSE, null_point, null_point);
    }
}

void CMsgTestDlg::OnExec()
{
    WinExec("notepad.exe", SW_SHOW);
}

void CMsgTestDlg::OnEditWnd()
{
    HWND hWnd = FindWindow(nullptr, "无标题 - 记事本");
    if (hWnd == nullptr)
    {
        MessageBox(nullptr, TEXT("没有找到记事本"), TEXT("提示"), MB_OK);
        return;
    }
    std::string pCaptionText = "消息测试";
    ::SendMessage(hWnd, WM_SETTEXT, (WPARAM) 0, (LPARAM) pCaptionText.c_str());
}

void CMsgTestDlg::OnGetWnd()
{
    HWND hWnd = ::FindWindow("Notepad", nullptr);
    if (hWnd == nullptr)
    {
        MessageBox(nullptr, TEXT("没有找到记事本"), TEXT("提示"), MB_OK);
        return;
    }
    char pCaptionText[MAXBYTE] = {0};
    ::SendMessage(hWnd, WM_GETTEXT, (WPARAM) MAXBYTE, (LPARAM) pCaptionText);
    MessageBox(nullptr, TEXT(pCaptionText), TEXT("提示"), MB_OK);
}