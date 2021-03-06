//
// Created by 刘时明 on 2020/12/24.
//
#include "main.h"

int main()
{
    Object2Json();

    JsonParse();

    SqlQuery("select id,nickname from t_user");

    RedisTest();

    // SqlInsert("INSERT INTO t_demo(id,`name`,age) VALUES(?,?,?)", 3, 9, "lsm", 23);
    return 0;
}
