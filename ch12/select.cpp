//
// Created by 刘时明 on 2021/3/15.
//
#include <iostream>
#include <cstdio>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8090

#define SERVER_QUEUE 10
#define FD_SET_SIZE 10
#define MAX_BUF 1024

void select_demo()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 设置非阻塞
    int opt = SO_REUSEADDR;
    setsockopt(server_fd, SOL_SOCKET, opt, &opt, sizeof(opt));

    struct sockaddr_in serverAddr{};
    socklen_t server_addr_len = sizeof(sockaddr_in);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(SERVER_PORT);

    // 绑定
    if (bind(server_fd, (struct sockaddr *) &serverAddr, server_addr_len))
    {
        std::cout << "Binding on " << SERVER_PORT << " fail." << std::endl;
        return;
    }

    // 创建等待队列
    listen(server_fd, SERVER_QUEUE);

    // 设定fd_set
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(server_fd, &read_fds);

    // 非阻塞模式等待客户连接
    struct sockaddr_in clientAddr{};
    int client_fd;
    socklen_t clientAddrLen;
    int len;
    char buf[MAX_BUF];

    while (true)
    {
        FD_SET(server_fd, &read_fds);
        fd_set temp_fds = read_fds;

        // 选择read_fds中可用的fd
        if (select(FD_SET_SIZE, &temp_fds, (fd_set *) nullptr, (fd_set *) nullptr,
                   (struct timeval *) nullptr) > 0)
        {
            if (FD_ISSET(server_fd, &temp_fds))
            {
                // 如果服务器fd可用，则为accept
                clientAddrLen = sizeof(sockaddr_in);
                client_fd = accept(server_fd, (struct sockaddr *) &clientAddr,
                                  &clientAddrLen);
                if (client_fd == -1)
                {
                    std::cout << "accept() error" << std::endl;
                    break;
                } else
                {
                    FD_SET(client_fd, &read_fds);
                    std::cout << inet_ntoa(clientAddr.sin_addr) << " connect"
                              << " at fd" << client_fd << std::endl;
                }
            }
            // 依次查询
            for (int fd = 0; fd < FD_SET_SIZE; fd++)
            {
                if (FD_ISSET(fd, &temp_fds))
                {
                    // 如果是Client活动，进行Echo
                    len = read(fd, buf, MAX_BUF);
                    if (len > 0)
                    {
                        write(fd, buf, len);
                    } else
                    {
                        // 结束
                        std::cout << "Client end at" << client_fd << std::endl;
                        FD_CLR(fd, &read_fds);
                    }
                }
            }
        }
    }
    close(server_fd);
}