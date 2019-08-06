// Fig 11.17: Hugeint.h
// HugeInt class definition
#ifndef HUGEINT_H
#define HUGEINT_H

#include <iostream>
#include <string>
using namespace std;

class HugeInt
{
    friend ostream &operator<<(ostream &, const HugeInt &);
    public:
        static const int digits = 30; // maximum digits in a HugeInt

        HugeInt(long = 0); // conversion/default constructor
        HugeInt(const string &); // conversion constructor

        // addition operator; HugeInt + HugeInt
        HugeInt operator+(const HugeInt &) const;

        // addition operator; HugeInt + int
        HugeInt operator+(int) const;

        // addition operator;
        // HugeInt + string that represents large integer value
        HugeInt operator+(const string &) const;

        // subtraction operator; HugeInt - HugeInt
        HugeInt operator-(const HugeInt &) const;

        // utility function: decade multiplier
        HugeInt multiplyDecade(int = 1, int = 0) const;

        // multiplication operator; HugeInt * HugeInt
        HugeInt operator*(const HugeInt &) const;

        // division operator; HugeInt / HugeInt
        HugeInt operator/(const HugeInt &) const;

        // comparison operators:
        bool operator<(const HugeInt &) const;
        bool operator<=(const HugeInt &) const;
        bool operator>(const HugeInt &) const;
        bool operator>=(const HugeInt &) const;
        bool operator==(const HugeInt &) const;
         // inequality operator; returns opposite of == operator
        bool operator!=(const HugeInt &right) const
        {
            return !(*this == right); // invokes HugeInt::operator==
        }                             // end function operator !=
        
        int integerSize() const;

        private:
        short integer[digits];
        bool negative;
}; // end class HugeInt

#endif