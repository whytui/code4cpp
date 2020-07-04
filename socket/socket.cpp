/*
* 作者：刘时明
* 时间：2020/5/24-20:52
* 作用：
*/
#include <windows.h>
#include <WinSock2.h>
#include <cstdio>
#include <string>

#include "socket.h"

// vc++
#pragma comment(lib, "ws2_32.lib")

#define PORT 8888

void start_socket()
{
    socketServer();
}

void socketServer()
{
    // 版本号
    WORD version = MAKEWORD(2, 0);
    WSADATA data;
    WSAStartup(version, &data);

    // 1.建立socket套接字
    // AF_INET代表IPV4
    // SOCK_STREAM代表面向数据流
    // IPPROTO_TCP代表TCP协议
    SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    // 2.绑定地址端口
    sockaddr_in _sin = {};
    _sin.sin_family = AF_INET;
    _sin.sin_port = htons(PORT);
    _sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if (bind(_sock, (sockaddr *) &_sin, sizeof(_sin)) == SOCKET_ERROR)
    {
        printf("bind error! \n");
        return;
    }
    // 3.监听网络端口
    if (listen(_sock, 5) == SOCKET_ERROR)
    {
        printf("listen error! \n");
        return;
    }
    // 4.等待客户端连接
    sockaddr_in _client = {};
    int _client_len = sizeof(_client);
    auto client_socket = INVALID_SOCKET;
    std::string msg = "hello";
    while (true)
    {
        client_socket = accept(_sock, (sockaddr *) &_client, &_client_len);
        if (client_socket == SOCKET_ERROR)
        {
            printf("无效的socket客户端连接! \n");
            break;
        }
        printf("一个客户端成功接入,IP=%s! \n",inet_ntoa(_client.sin_addr));
        // 5.发送数据
        send(client_socket, msg.c_str(), msg.length() + 1, 0);
        // 6.关闭socket
        closesocket(_sock);
    }
    WSACleanup();
    printf("ok \n");
}

void socketClient()
{}
