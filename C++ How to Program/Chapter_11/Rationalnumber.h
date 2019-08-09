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
        RationalNumber(long = 0, long = 1); // conversion/default constructor

        private:
        void reduceFraction();
        long numerator;
        long denominator;
        bool negative;
}; // end class RationalNumber

#endif