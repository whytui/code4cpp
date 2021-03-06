//
// Created by 刘时明 on 2021/3/5.
//
#include "main.h"
#include <hiredis/hiredis.h>

#include <utility>

class RedisClient
{
private:
    string host;
    int port;

    bool connect_flag;

    redisContext *connect;

public:
    RedisClient() = default;

    RedisClient(string host, int port)
    {
        this->host = std::move(host);
        this->port = port;
    }

    void Connect()
    {
        this->connect = redisConnect(host.c_str(), this->port);
        if (connect != nullptr && connect->err)
        {
            cout << "connect error: " << connect->errstr << endl;
            return;
        }
        this->connect_flag = true;
    }

    string get(const string &key)
    {
        if (!this->connect_flag)
        {
            cout << "not connect!!!" << endl;
            return nullptr;
        }
        auto reply = (redisReply *) redisCommand(this->connect, "GET %s", key.c_str());
        std::string str = reply->str;
        freeReplyObject(reply);
        return str;
    }

    void set(const string &key, const string &value)
    {
        if (!this->connect_flag)
        {
            cout << "not connect!!!" << endl;
            return;
        }
        redisCommand(this->connect, "SET %s %s", key.c_str(), value.c_str());
    }
};

void RedisTest()
{
    auto client = new RedisClient("127.0.0.1", 6379);

    client->Connect();
}