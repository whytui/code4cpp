//
// Created by 刘时明 on 2020/11/24.
//
#include "ch02.h"

#include <string>
#ifdef _WIN32
#include <Rpc.h>
#pragma  comment(lib, "Rpcrt4.lib")
#else
//编译链接时，需要加入 -luuid
#include <uuid/uuid.h>
#endif

// 提供一个跨平台的 UUID 函数
string GenerateUUID()
{
    string guid;
#ifdef _WIN32
    UUID uuid;
	if (RPC_S_OK != UuidCreate(&uuid))
	{
		return guid;
	}
	char tmp[37] = { 0 };
	sprintf_s(tmp, "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
		uuid.Data1, uuid.Data2, uuid.Data3,
		uuid.Data4[0], uuid.Data4[1],
		uuid.Data4[2], uuid.Data4[3],
		uuid.Data4[4], uuid.Data4[5],
		uuid.Data4[6], uuid.Data4[7]);
	guid.assign(tmp);
#else
    uuid_t uuid;
    char str[50] = {};
    uuid_generate(uuid);
    uuid_unparse(uuid, str);
    guid.assign(str);
#endif
    return guid;
}

