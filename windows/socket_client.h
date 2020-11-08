/**
* 作者：刘时明
* 时间：2020/11/8 0008-12:27
*/
#ifndef CODE4CPP_SOCKET_CLIENT_H
#define CODE4CPP_SOCKET_CLIENT_H

// 如果是C++编译器，则按照C标准编译
#ifdef __cplusplus
extern "C"
{
// 初始化环境
int socket_client_init(void **handle);

// 发送信息
int socket_client_send(void *handle, void *buff, int len);

// 接受信息
int socket_client_recv(void *handle, void *buff, int *len);

// 释放资源
int socket_client_destroy();
}
#endif

#endif //CODE4CPP_SOCKET_CLIENT_H
