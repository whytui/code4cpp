/**
* 作者：刘时明
* 时间：2020/11/23 0023
*/
#include <cstdio>
#include <unistd.h>
#include <csignal>

void fork_demo()
{
    printf("进程ID=%d \n", getpid());

    pid_t pid;

    printf("父进程启动! \n");

    // 使用fork创建子进程
    pid = fork();

    if (pid < 0)
    {
        printf("创建子进程失败! \n");
    } else if (pid == 0)
    {
        printf("子进程开始执行 \n");

        setsid();
        for (int i = 0; i < 10; i++)
        {
            sleep(1);
            printf("子进程休息1秒 \n");
        }
    } else
    {
        for (int i = 0; i < 10; i++)
        {
            sleep(1);
            printf("父进程休息1秒 \n");
        }
    }
    printf("程序退出! \n");
}