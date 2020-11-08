/**
* 作者：刘时明
* 时间：2020/11/8 0008-15:12
*/
#include <iostream>

using namespace std;

// & 与
// | 或
// ^ 异或（如果相等为0，否则为1）
// ~ 取反
// << 左移
// >> 右移

#define MAX_U_BYTE 0b11111111

void bit_demo()
{
    cout << (MAX_U_BYTE << 1) << endl;

    cout << (MAX_U_BYTE >> 1) << endl;

    cout << (MAX_U_BYTE | 0b10000000) << endl;

    cout << (MAX_U_BYTE & 0b10000000) << endl;

    cout << (MAX_U_BYTE & 0b10000000) << endl;

    cout << (MAX_U_BYTE ^ 0b10000000) << endl;
}