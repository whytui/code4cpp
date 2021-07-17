//
// Created by 刘时明 on 2021/3/5.
//

#include "main.h"
#include <mysql.h>
#include <cstring>

const string &host = "119.29.117.244";
const string &user = "root";
const string &passwd = "fuck123";
const string &db = "im";
const int port = 3306;

void FreeConnect(MYSQL *mysql_client)
{
    delete mysql_client;
    mysql_client = nullptr;
}

void CloseConnect(MYSQL *mysql_client)
{
    if (mysql_client == nullptr)
        return;
    mysql_close(mysql_client);
    FreeConnect(mysql_client);
}

MYSQL *GetConnect()
{
    auto mysql_client = new MYSQL();
    if (mysql_init(mysql_client) == nullptr)
    {
        printf("mysql_init fail!\n");
        cout << "mysql_init fail!" << "error=" << mysql_error(mysql_client) << endl;
        FreeConnect(mysql_client);
        return nullptr;
    }
    if (mysql_real_connect(mysql_client, host.c_str(), user.c_str(), passwd.c_str(),
                           db.c_str(), port, nullptr, 0) == nullptr)
    {
        cout << "mysql_real_connect !" << "error=" << mysql_error(mysql_client) << endl;
        FreeConnect(mysql_client);
        return nullptr;
    }
    return mysql_client;
}

void SqlQuery(const string &sql)
{
    auto mysql_client = GetConnect();
    if (mysql_client == nullptr)
    {
        cout << "GetConnect fail!" << endl;
        return;
    }
    int result = mysql_query(mysql_client, sql.c_str());
    if (result)
    {
        cout << "mysql_query fail!" << "error=" << mysql_error(mysql_client) << endl;
        return;
    }
    MYSQL_RES *res = mysql_store_result(mysql_client);
    if (res == nullptr)
    {
        cout << "mysql_query fail!" << "error=" << mysql_error(mysql_client) << endl;
        return;
    }
    cout << "结果count=" << mysql_affected_rows(mysql_client) << endl;
    MYSQL_ROW hs;
    while ((hs = mysql_fetch_row(res)) != nullptr)
    {
        for (int i = 0; i < res->field_count; ++i)
        {
            cout << "第" << (i + 1) << "列数据=" << hs[i] << " ";
        }
        cout << endl;
    }
    mysql_free_result(res);
    CloseConnect(mysql_client);
}

void SqlInsert(const string &sql, int count, ...)
{
    MYSQL_STMT *stmt;
    MYSQL_BIND bind[count];
    my_ulonglong affected_rows;

    unsigned long str_length = 50;

    bool is_null;
    MYSQL *mysql = GetConnect();

    stmt = mysql_stmt_init(mysql);
    if (!stmt)
    {
        fprintf(stderr, " mysql_stmt_init(), out of memory\n");
        exit(0);
    }
    if (mysql_stmt_prepare(stmt, sql.c_str(), strlen(sql.c_str())))
    {
        fprintf(stderr, " mysql_stmt_prepare(), INSERT failed\n");
        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
        exit(0);
    }
    int param_count = mysql_stmt_param_count(stmt);
    cout << "预编译参数数量=" << param_count << endl;

    memset(bind, 0, sizeof(bind));

    va_list args;
    va_start(args, count);


    int id = va_arg(args, int);
    bind[0].buffer_type = MYSQL_TYPE_LONG;
    bind[0].buffer = (char *) &id;
    bind[0].is_null = 0;
    bind[0].length = 0;

    char *name = va_arg(args, char*);
    bind[1].buffer_type = MYSQL_TYPE_STRING;
    bind[1].buffer = (char *) name;
    bind[1].buffer_length = 50;
    bind[1].is_null = 0;
    bind[1].length = &str_length;

    int age = va_arg(args, int);
    bind[2].buffer_type = MYSQL_TYPE_SHORT;
    bind[2].buffer = (char *) &age;
    bind[2].is_null = &is_null;
    bind[2].length = 0;
    va_end(args);

    if (mysql_stmt_bind_param(stmt, bind))
    {
        fprintf(stderr, " mysql_stmt_bind_param() failed\n");
        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
        exit(0);
    }

    if (mysql_stmt_execute(stmt))
    {
        fprintf(stderr, " mysql_stmt_execute(), 1 failed\n");
        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
        exit(0);
    }

    affected_rows = mysql_stmt_affected_rows(stmt);
    fprintf(stdout, " total affected rows(insert 1): %lu\n",
            (unsigned long) affected_rows);

    if (affected_rows != 1)
    {
        fprintf(stderr, " invalid affected rows by MySQL\n");
        exit(0);
    }

    if (mysql_stmt_close(stmt))
    {
        fprintf(stderr, " failed while closing the statement\n");
        fprintf(stderr, " %s\n", mysql_stmt_error(stmt));
        exit(0);
    }
}