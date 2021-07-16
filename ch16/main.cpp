//
// Created by 刘时明 on 2020/12/24.
//
#include "main.h"
#include <boost/array.hpp>

int main()
{
    //Object2Json();

    //JsonParse();

    RedisTest();

    // SqlInsert("INSERT INTO t_demo(id,`name`,age) VALUES(?,?,?)", 3, 9, "lsm", 23);

    SqlQuery("select id,nickname from t_user");

    boost::array<int, 5> array = {1, 2, 3, 4, 5};

    std::cout << array[0] << std::endl;
    return 0;
}
