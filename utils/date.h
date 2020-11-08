/**
* 作者：刘时明
* 时间：2020/11/8 0008-13:16
*/
#ifndef CODE4CPP_DATE_H
#define CODE4CPP_DATE_H

class MyDate
{
private:
    long t;

public:
    static MyDate *now();

    MyDate() = default;

    explicit MyDate(long time);

    [[nodiscard]] long unix_time() const;
};


#endif //CODE4CPP_DATE_H
