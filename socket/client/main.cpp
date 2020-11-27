/**
* 作者：刘时明
* 时间：2020/11/23 0023
*/
#include "main.h"

int main()
{
    int cfd;
    int recBytes;
    int sin_size;
    char buffer[1024];
    struct sockaddr_in s_add{}, c_add{};
    unsigned short port = 10051;
    cout << "客户端准备就绪" << endl;
    char ip[] = "127.0.0.1";
    cfd = socket(AF_INET, SOCK_STREAM, 0);
    if (cfd == -1)
    {
        cout << "socket fail!" << endl;
        return 0;
    }
    bzero(&s_add, sizeof(struct sockaddr_in));
    s_add.sin_family = AF_INET;
    s_add.sin_addr.s_addr = inet_addr(ip);
    s_add.sin_port = htons(port);

    if (connect(cfd, (struct sockaddr *) (&s_add), sizeof(struct sockaddr)) == -1)
    {
        cout << "connect fail!" << endl;
        return 0;
    }
    if ((recBytes = read(cfd, buffer, 1024)) == -1)
    {
        cout << "read fail!" << endl;
        return 0;
    }
    buffer[recBytes] = '\0';
    cout << buffer << endl;
    getchar();
    close(cfd);
    return 0;
}