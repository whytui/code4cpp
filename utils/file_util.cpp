//
// Created by Administrator on 2020/5/30.
//
using namespace std;

#include <dirent.h>
#include <cstring>
#include "file_util.h"

void FindFiles(string root, vector<string> &files) {
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(root.c_str())) != NULL) {

        while ((ent = readdir(dir)) != NULL) {
            if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
                continue;
            files.push_back(ent->d_name);
        }
        closedir(dir);
    }
}