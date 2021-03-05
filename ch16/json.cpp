//
// Created by 刘时明 on 2021/3/5.
//
#include "main.h"
#include <cjson/cJSON.h>
#include <json/json.h>

/**
 * CJson使用
 */
void JsonObject()
{
    cJSON *root = cJSON_CreateObject();
    cJSON *js_body;
    const char *const body = "body";
    cJSON_AddItemToObject(root, body, js_body = cJSON_CreateObject());
    cJSON_AddStringToObject(js_body, "name", "lsm");
    cJSON_AddNumberToObject(js_body, "value", 600);
    char *s = cJSON_PrintUnformatted(root);
    if (s)
    {
        printf("create js string is %s\n", s);
        free(s);
    }
    cJSON_Delete(root);
}

/**
 * 对象转JSON
 */
void Object2Json()
{
    typedef struct Student
    {
        string name;
        int age;
    } Student;
    Student s1{};
    s1.age = 23;
    s1.name = "lsm";

    Json::FastWriter writer;
    Json::Value person;

    person["age"] = s1.age;
    person["name"] = s1.name;

    string json_str = writer.write(person);
    cout << json_str << endl;
}

/**
 * 解析JSON字符串
 */
void JsonParse()
{
    string strJsonContent = R"({"age": 1,"name": "lsm","remake": "..."})";

    int age = 0;
    string name;
    string remake;

    Json::Reader reader{};
    Json::Value root{};

    if (reader.parse(strJsonContent, root))
    {
        age = root["age"].asInt();
        name = root["name"].asString();
        remake = root["remake"].asString();
    }

    cout << "name is: " << age << endl;
    cout << "age is: " << name << endl;
    cout << "remake is: " << remake << endl;
}