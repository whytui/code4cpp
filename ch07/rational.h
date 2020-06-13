/*
* 作者：刘时明
* 时间：2020/5/31-20:11
* 作用：
*/
#ifndef CODE4CPP_RATIONAL_H
#define CODE4CPP_RATIONAL_H

#include <string>

using namespace std;

class Rational
{
public:
    Rational();

    Rational(int numerator, int denominator);

    int getNumerator() const;

    int getDenominator() const;

    Rational add(const Rational &second) const;

    Rational sub(const Rational &second) const;

    Rational mul(const Rational &second) const;

    Rational div(const Rational &second) const;

    int compareTo(const Rational &second) const;

    bool equals(const Rational &second) const;

    int intValue() const;

    double doubleValue() const;

    string toString() const;

    bool operator<(const Rational &second) const;

    bool operator>(const Rational &second) const;

    Rational operator+(const Rational &second) const;

    Rational operator*(const Rational &second) const;

    Rational operator/(const Rational &second) const;

    Rational operator=(const Rational &second) const;

    int operator[](int index) const;

    operator double() const;

    operator int() const;

private:
    int numerator;
    int denominator;

    static int gcd(int n, int d);

public:
    friend void change(Rational &rational, int numerator, int denominator);
};

void change(Rational &rational, int numerator, int denominator);

// Rational operator+(const Rational &second1, const Rational &second2);

#endif //CODE4CPP_RATIONAL_H
