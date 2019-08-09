// RationalNumber class definition
#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>
#include <string>
using namespace std;

class RationalNumber
{
    friend ostream &operator<<(ostream &, const RationalNumber &);

public:
    RationalNumber(const long = 0, const long = 1); // conversion/default constructor

    // addition operator; RationalNumber + RationalNumber
    RationalNumber operator+(const RationalNumber &) const;

    // subtraction operator; RationalNumber - RationalNumber
    RationalNumber operator-(const RationalNumber &) const;

    // multiplication operator; RationalNumber * RationalNumber
    RationalNumber operator*(const RationalNumber &)const;

    // division operator; RationalNumber / RationalNumber
    RationalNumber operator/(const RationalNumber &) const;

    // comparison operators:
    bool operator<(const RationalNumber &) const;
    bool operator<=(const RationalNumber &) const;
    bool operator>(const RationalNumber &) const;
    bool operator>=(const RationalNumber &) const;
    bool operator==(const RationalNumber &) const;
    //  inequality operator; returns opposite of == operator
    bool operator!=(const RationalNumber &right) const
    {
        return !(*this == right); // invokes RationalNumber::operator==
    }                             // end function operator !=

private:
    void reduceFraction();
    double division() const;
    long numerator;
    long denominator;
}; // end class RationalNumber

#endif