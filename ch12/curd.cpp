#include "ch12.h"
#include "mysql.h"

MYSQL *conn;

// 连接数据库
bool ConnectMysql()
{
    cout << "start !!!" << endl;
    // 初始化mysql
    mysql_init(conn);
    return false;

//    if (!(mysql_real_connect(conn,
//                             "localhost",//主机
//                             "root",//用户名
//                             "",//密码
//                             "myDatabase",//数据库名
//                             3306,//端口号
//                             NULL, 0//最后两个参数的常用写法 几乎都是这两个
//    )))
//    {
//        cout << "Error connecting to database:" + (string) mysql_error(&mysql) << endl;
//        return false;
//    } else
//    {
//        cout << "Connected..." << endl;
//        return true;
//    }
}