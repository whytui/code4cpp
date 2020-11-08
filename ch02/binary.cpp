/**
* 作者：刘时明
* 时间：2020/11/8 0008-19:51
*/
#include <cstdio>
#include <cstring>

struct Stu
{
    char name[30];
    int age;
    double score;
};

// 二进制IO
void binary_write()
{
    Stu student[2];
    strcpy(student[0].name, "lsm");
    student[0].age = 22;
    student[0].score = 100;

    strcpy(student[1].name, "lw");
    student[1].age = 21;
    student[1].score = 100;

    FILE *fp = fopen("../resource/data.bin", "wb");
    if (fp == nullptr)
    {
        printf("文件打开失败");
        return;
    }
    int size = sizeof(Stu);
    int result = fwrite(&student, size, 2, fp);
    printf("%d \n", result);
    fclose(fp);
}

void binary_read()
{
    FILE *fp = fopen("../resource/data.bin", "rb");
    if (fp == nullptr)
    {
        printf("文件打开失败");
        return;
    }
    Stu student[2];
    int size = sizeof(Stu);
    fread(&student, size, 2, fp);

    for (auto & i : student)
    {
        printf("%s\n", i.name);
    }
    fclose(fp);
}
