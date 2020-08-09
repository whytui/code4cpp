/*
* 作者：刘时明
* 时间：2020/5/31-0:10
* 作用：
*/

#ifndef CODE4CPP_SOCKET_H
#define CODE4CPP_SOCKET_H

#include <string>

using namespace std;

class Socket
{
private:
    int port;
    string adders;

public:
    Socket() = default;

    Socket(string adders, int port);
};


#endif
