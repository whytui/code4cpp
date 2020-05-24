/*
* 作者：刘时明
* 时间：2020/5/24-20:27
* 作用：
*/
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "thread.h"

using namespace std;

// http://blog.chinaunix.net/uid-26275986-id-3886498.html
/**
 * windows创建线程 CreateThread()
 * 参数1：安全属性结构，主要控制该线程句柄是否可为进程的子进程继承使用，默认使用NULL时表示不能继承；若想继承线程句柄，则需要设置该结构体，将结构体的bInheritHandle成员初始化为TRUE；
 * 参数2：线程初始栈的大小，若使用0则表示采用默认大小初始化；
 * 参数3：线程开始的位置，即线程要执行的函数代码；
 * 参数4：接收线程过程函数的参数，不需要时可以设置为NULL；
 * 参数5：创建线程时的标志，CREATE_SUSPENDED表示线程创建后挂起暂不执行，必须调用ResumeThread才可以执行，0表示线程创建之后立即执行；
 * 参数6：保存线程的ID；
 * @return
 */
int thread()
{
    int j = 0;
    HANDLE hThread_1 = CreateThread(NULL, 0, theadFunc, NULL, 0, NULL);
    CloseHandle(hThread_1);
    while (j++ < 1000)
    {
        printf("MainThread run once count=%d\n", j);
    }
    system("pause");
    return 0;
}

/**
 * 类似于Java的run方法
 * @param lpParameter
 * @return
 */
DWORD WINAPI theadFunc(LPVOID lpParameter)
{
    int i = 0;
    while (i++ < 1000)
    {
        printf("DeputyThread run once count=%d\n", i);
    }
    return 0;
}
