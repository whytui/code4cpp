using namespace std;

#ifndef CODE4CPP_FILE_UTIL_H
#define CODE4CPP_FILE_UTIL_H
#include <string>
#include <vector>

void file_list(const string &path, vector<string> *files);

vector<string> *file_list(const string &path);

void make_dirs(const string &dirs);

void copy(const string &dist,const string &src);

void copy_file(const string &dist, const string &src);

bool is_dir(const string &path);

#endif //CODE4CPP_FILE_UTIL_H