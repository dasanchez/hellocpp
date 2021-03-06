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
    cout << "(20, 36) is converted  to " << rn << endl;
    rn = RationalNumber(2, 2); // reduce to 1/1
    cout << "(2, 2) is converted to " << rn << endl;
    rn = RationalNumber(2, -2); // makes denominator positive
    cout << "(2, -2) is converted  to " << rn << endl;
    rn = RationalNumber(-2, 2); // keeps numerator negative
    cout << "(-2, 2) is converted  to " << rn << endl;
    rn = RationalNumber(2);
    cout << "(2) is converted  to " << rn << endl;
    rn = RationalNumber(-3);
    cout << "(-3) is converted  to " << rn << endl;

    RationalNumber rn2(2, 3);
    // addition:
    cout << rn << " + " << rn2 << " = " << rn + rn2 << endl;
    cout << rn2 << " + " << 5 << " = " << rn2 + 5 << endl;
    // subtraction:
    cout << rn << " - " << rn2 << " = " << rn - rn2 << endl;
    cout << 5 << " - " << rn2 << " = " << (RationalNumber(5) - rn2) << endl;
    // multiplication:
    cout << rn << " * " << rn2 << " = " << rn * rn2 << endl;
    cout << 5 << " * " << rn2 << " = " << (RationalNumber(5) * rn2) << endl;
    // division:
    cout << rn << " / " << rn2 << " = " << rn / rn2 << endl;
    cout << 5 << " / " << rn2 << " = " << (RationalNumber(5) / rn2) << endl;
    cout << "(4 / 6)"
         << " / " << rn2 << " = " << (RationalNumber(4, 6) / rn2) << endl;

    // less-than operator:
    cout << rn << " < " << rn2 << " = " << (rn < rn2) << endl;
    cout << rn2 << " < " << rn << " = " << (rn2 < rn) << endl;
    cout << rn2 << " < " << rn2 << " = " << (rn2 < rn2) << endl;

    // less-than-or-equal operator:
    cout << rn << " <= " << rn2 << " = " << (rn <= rn2) << endl;
    cout << rn2 << " <= " << rn << " = " << (rn2 <= rn) << endl;
    cout << rn2 << " <= " << rn2 << " = " << (rn2 <= rn2) << endl;

    // greater-than operator:
    cout << rn << " > " << rn2 << " = " << (rn > rn2) << endl;
    cout << rn2 << " > " << rn << " = " << (rn2 > rn) << endl;
    cout << rn2 << " > " << rn2 << " = " << (rn2 > rn2) << endl;

    // greater-than-or-equal operator:
    cout << rn << " >= " << rn2 << " = " << (rn >= rn2) << endl;
    cout << rn2 << " >= " << rn << " = " << (rn2 >= rn) << endl;
    cout << rn2 << " >= " << rn2 << " = " << (rn2 >= rn2) << endl;

    // equality operator:
    cout << rn << " == " << rn2 << " = " << (rn == rn2) << endl;
    cout << rn2 << " == " << rn << " = " << (rn2 == rn) << endl;
    cout << rn2 << " == " << rn2 << " = " << (rn2 == rn2) << endl;

    // inequality operator:
    cout << rn << " != " << rn2 << " = " << (rn != rn2) << endl;
    cout << rn2 << " != " << rn << " = " << (rn2 != rn) << endl;
    cout << rn2 << " != " << rn2 << " = " << (rn2 != rn2) << endl;

} // end main
