//
// Created by 刘时明 on 2020/11/28.
//
#include <netinet/in.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <zconf.h>
#include <arpa/inet.h>

#ifndef    HAVE_INET_PTON_PROTO

const char *inet_ntop(int, const void *, char *, size_t);

#endif

#define MAX_LINE 4096

#define ERROR(fmt) {printf((fmt));exit(1);}

#define    SA    struct sockaddr

void time_server(int argc, char **argv)
{
    int sock_fd, n;
    char recv_line[MAX_LINE + 1];
    struct sockaddr_in serv_addr{};

    if (argc != 2)
    {
        ERROR("usage: a.out <IPAddress>")
    }
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        ERROR("socket error")
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(13);

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
    {
        ERROR("inet_pton error")
    }
    if (connect(sock_fd, (SA *) &serv_addr, sizeof(serv_addr)) <= 0)
    {
        ERROR("inet_pton error")
    }

    while ((n = read(sock_fd, recv_line, MAX_LINE)) > 0)
    {
        recv_line[n] = 0;
        if (fputs(recv_line, stdout) == EOF)
        ERROR("fputs error");
    }
    if (n < 0)
    {
        ERROR("read error")
    }
    exit(0);
}
