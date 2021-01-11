#include <dirent.h>
#include <cstring>
#include <fstream>
#include "file_util.h"

/**
 * ��ȡĿ¼�µ��ļ��б�
 * @param path
 * @param files
 */
void file_list(const string &path, vector<string> *files)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(path.c_str())) != nullptr)
    {
        while ((ent = readdir(dir)) != nullptr)
        {
            if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
            {
                continue;
            }
            files->emplace_back(ent->d_name);
        }
        closedir(dir);
    }
}

/**
 * ��ȡĿ¼�µ��ļ��б�
 * @param root
 * @return
 */
vector<string> *file_list(const string &path)
{
    auto *list = new vector<string>;
    file_list(path, list);
    return list;
}

/**
 * ����Ŀ¼,֧�ֶ༶Ŀ¼����
 * @param dirs
 */
void make_dirs(const string &dirs)
{

}

/**
 * �����ļ�
 * @param dist
 * @param src
 */
void copy(const string &dist, const string &src)
{
    if (is_dir(src))
    {
        make_dirs(dist);
        auto v = file_list(src);
        for (auto &i:*v)
        {
            string dist_temp = dist;
            string src_temp = src;
            dist_temp.append("\\").append(i);
            src_temp.append("\\").append(i);
            if (is_dir(src_temp))
            {
                // ��Ŀ¼
                copy(dist_temp, src_temp);
            } else
            {
                // �ļ�
                copy_file(dist_temp, src_temp);
            }
        }
        delete v;
    } else
    {
        copy_file(dist, src);
    }
}

/**
 * ʹ�ö�����������ļ�����
 * @param dist
 * @param src
 */
void copy_file(const string &dist, const string &src)
{
    fstream input(src, ios::in | ios::binary);
    fstream output(dist, ios::out | ios::binary);
    int size = 1024;
    while (true)
    {
        char arr[size];
        input.read(arr, size);
        int len = input.gcount();
        if (len == 0)
        {
            break;
        }
        output.write(arr, len);
    }
    input.close();
}

/**
 * �ж�ָ��·���Ƿ�ΪĿ¼
 * @param path
 * @return
 */
bool is_dir(const string &path)
{
    DIR *dir = opendir(path.c_str());
    bool result = dir != nullptr;
    closedir(dir);
    return result;
}