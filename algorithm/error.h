/*
* 作者：刘时明
* 时间：2020/6/15-23:42
* 作用：
*/

#ifndef CODE4CPP_ERROR_H
#define CODE4CPP_ERROR_H

#include <string>
#include <iostream>

using namespace std;

class illegalParameterValue
{
private:
    string errorMsg;

public:
    illegalParameterValue() : errorMsg("illegal parameter value")
    {}

    illegalParameterValue(char *theMessage)
    {
        this->errorMsg = theMessage;
    }

    void outputMessage()
    {
        cout << this->errorMsg << endl;
    }
};

#endif //CODE4CPP_ERROR_H
