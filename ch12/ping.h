/**
* 作者：刘时明
* 时间：2020/11/7 0007-22:05
*/
#ifndef CODE4CPP_PING_H
#define CODE4CPP_PING_H

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

#define MAGIC "1234567890"
#define MAGIC_LEN 11
#define MTU 1500
#define RECV_TIMEOUT_USEC 100000

struct icmp_echo
{
    // header
    uint8_t type;
    uint8_t code;
    uint16_t checksum;

    uint16_t ident;
    uint16_t seq;

    // data
    double sending_ts;
    char magic[MAGIC_LEN];
};

#endif //CODE4CPP_PING_H
