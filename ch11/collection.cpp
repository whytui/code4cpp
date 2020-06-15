/*
* 作者：刘时明
* 时间：2020/6/14-22:37
* 作用：
*/
#include "ch11.h"
#include <map>

void mapDemo();

void collectionDemo()
{
    mapDemo();
}

void mapDemo()
{
    auto *demoMap = new map<int, string>();
    bool result = demoMap->insert(pair<int, string>(1, "hello")).second;
    cout << "插入结果=" << result << endl;
    demoMap->insert(pair<int, string>(2, "lw"));
    (*demoMap)[3] = "simple";
    string val = demoMap->at(1);
    cout << "val=" << val << endl;

    cout << "find=" << demoMap->find(1)->first << endl;
    cout << "find=" << demoMap->find(1)->second << endl;

    // 遍历map
    auto iter = demoMap->begin();
    while (iter != demoMap->end())
    {
        cout << iter->first << ":" << iter->second << endl;
        iter++;
    }

    delete demoMap;
}