/*
* 作者：刘时明
* 时间：2020/5/31-20:11
* 作用：
*/
#include "rational.h"

Rational::Rational()
{
    this->numerator = 0;
    this->denominator = 1;
}

int Rational::getNumerator() const
{
    return numerator;
}

int Rational::getDenominator() const
{
    return denominator;
}

Rational::Rational(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

Rational Rational::add(const Rational &second) const
{
    int n = numerator * second.getDenominator() + denominator * second.getNumerator();
    int d = denominator * second.getDenominator();
    return {n, d};
}

Rational Rational::sub(const Rational &second) const
{
    int n = numerator * second.getDenominator() - denominator * second.getNumerator();
    int d = denominator * second.getDenominator();
    return {n, d};
}

Rational Rational::mul(const Rational &second) const
{
    int n = numerator * second.getDenominator() * denominator * second.getNumerator();
    int d = denominator * second.getDenominator();
    return {n, d};
}

Rational Rational::div(const Rational &second) const
{
    int n = numerator * second.getDenominator() / denominator * second.getNumerator();
    int d = denominator * second.getDenominator();
    return {n, d};
}

int Rational::compareTo(const Rational &second) const
{
    Rational temp = sub(second);
    if (temp.getNumerator() < 0)
    {
        return -1;
    } else if (temp.getNumerator() > 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}

bool Rational::equals(const Rational &second) const
{
    return compareTo(second) == 0;
}

int Rational::intValue() const
{
    return getNumerator();
}

double Rational::doubleValue() const
{
    return getNumerator() * 1.0;
}

string Rational::toString() const
{
    string str(to_string(numerator));
    str.append("/").append(to_string(denominator));
    return str;
}

int Rational::gcd(int n, int d)
{
    int n1 = abs(n);
    int n2 = abs(d);
    int gcd = 1;
    for (int k = 1; k < n1 && k <= n2; ++k)
    {
        if (n1 % k && n2 % k == 0)
        {
            gcd = k;
        }
    }
    return gcd;
}

bool Rational::operator<(const Rational &second) const
{
    return compareTo(second) < 0;
}

bool Rational::operator>(const Rational &second) const
{
    return compareTo(second) > 0;
}

Rational Rational::operator*(const Rational &second) const
{
    return mul(second);
}

Rational Rational::operator/(const Rational &second) const
{
    return div(second);
}

int Rational::operator[](int index) const
{
    if (index == 0)
    {
        return numerator;
    }
    return denominator;
}

/**
 * 通过友元函数可以访问类的私有属性
 * @param rational
 * @param numerator
 * @param denominator
 */
void change(Rational &rational, int numerator, int denominator)
{
    rational.numerator = numerator;
    rational.denominator = denominator;
}

/**
 * 自动类型转换
 * @return
 */
Rational::operator double() const
{
    return this->doubleValue();
}

Rational::operator int() const
{
    return this->intValue();
}

Rational Rational::operator+(const Rational &second) const
{
    return add(second);
}

Rational Rational::operator=(const Rational &second) const
{
    return Rational(second.getNumerator(), second.getDenominator());
}

//Rational operator+(const Rational &second1, const Rational &second2)
//{
//    return second1.add(second2);
//}