//
// Created by 刘时明 on 2021/3/5.
//
#include "main.h"
#include <boost/json.hpp>

/**
 * CJson使用
 */
//void JsonObject()
//{
//    cJSON *root = cJSON_CreateObject();
//    cJSON *js_body;
//    const char *const body = "body";
//    cJSON_AddItemToObject(root, body, js_body = cJSON_CreateObject());
//    cJSON_AddStringToObject(js_body, "name", "lsm");
//    cJSON_AddNumberToObject(js_body, "value", 600);
//    char *s = cJSON_PrintUnformatted(root);
//    if (s)
//    {
//        printf("create js string is %s\n", s);
//        free(s);
//    }
//    cJSON_Delete(root);
//}

/**
 * 对象转JSON
 */
//void Object2Json()
//{
//    boost::json::object obj{};
//    obj["age"] = 23;
//    obj["name"] = "lsm";
//    std::string str = boost::json::serialize(obj);
//}

/**
 * 解析JSON字符串
 */
//void JsonParse()
//{
//    boost::json::value val = boost::json::parse(R"({"age": 1,"name": "lsm","remake": "..."})");
//
//    if (val.is_object())
//    {
//        for (const auto &o: val.as_object())
//        {
//            std::cout << o.key() << "=" << o.value() << std::endl;
//        }
//    }
//}