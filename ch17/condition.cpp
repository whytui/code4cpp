#include <iostream>

using namespace std;

#ifdef __ANDROID__
string hello("hello android");
#elif __linux__
string hello("hello linux");
#elif _WIN32
string hello("hello windows");
#elif __unix__
string hello("hello unix");
#elif __APPLE__
string hello("hello macos");
#endif

#define DEBUG

const int *p = new int(100);

constexpr int port = 100;

int main()
{
    cout << hello << endl;

#ifdef DEBUG
    printf("debug!!! \n");
#endif
    return 0;
}