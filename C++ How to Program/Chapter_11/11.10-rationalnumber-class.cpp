// Ex 11.10: RationalNumber class
// Create a class RationalNumber (fractions) with the following capabilities:
// a) Create a constructor that prevents a 0 denominator in  a fraction, reduces
// or simplifies fractions that are not in reduced form and avoids negative
// denominators.
// b) Overload the addition, subtraction, multiplication and division operatos for
// this class.
// c) Overload the relational and equality operators for this class.

#include <iostream>
#include "Rationalnumber.h"
using namespace std;

int main()
{
    RationalNumber rn;
    // denominator cannot be zero
    try
    {
        rn = RationalNumber(1, 0);
    }
    catch (invalid_argument &err)
    {
        cout << err.what();
    }
    try
    {
        rn = RationalNumber(1, 2);
    }
    catch (invalid_argument &err)
    {
        cout << err.what();
    }
    cout << "The number is " << rn << endl;
    rn = RationalNumber(2, 4); // reduce to 1/2
    cout << "(2, 4) is converted to " << rn << endl;
    rn = RationalNumber(20, 36); // reduce to 5/9
    cout<< "(20, 36) is converted  to " << rn << endl;
    rn = RationalNumber(2, 2); // reduce to 1/1
    cout << "(2, 2) is converted to " << rn << endl;
    rn = RationalNumber(2, -2); // makes denominator positive
    cout << "(2, -2) is converted  to " << rn << endl;
    rn = RationalNumber(-2, 2); // keeps numerator negative
    cout << "(-2, 2) is converted  to " << rn << endl;

} // end main
