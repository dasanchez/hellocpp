// RationalNumber member-function and friend-function definitions.
#include <cctype>           // isdigit function prototype
#include "Rationalnumber.h" // HugeInt class definition
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
RationalNumber::RationalNumber(long val1, long val2)
    : numerator(val1), denominator(val2)
{
    // check for denominator != 0
    if (denominator == 0)
    {
        numerator = 1;
        denominator = 1;
        throw invalid_argument("Denominator cannot be zero.\n");
    }
    if (denominator < 0)
        denominator *= -1;

    if (numerator < 0)
    {
        numerator *= -1;
        negative = true;
    }
    else
    {
        negative = false;
    }

    // reduce numerator and denominator
    reduceFraction();

} // end HugeInt default/conversion constructor

void RationalNumber::reduceFraction()
{
    int small = 1;
    // which number is smaller?
    if (numerator < denominator)
        small = numerator;
    else if (denominator < numerator)
        small = denominator;
    else
    {
        numerator = 1;
        denominator = 1;
        return;
    }

    for (int i = 2; i <= small; ++i)
    {
        if (numerator % i == 0 && denominator % i == 0)
        {
            numerator /= i;
            denominator /= i;
            i = 1;
        }
    }
}

// overloaded output operator
ostream &operator<<(ostream &output, const RationalNumber &num)
{
    if (num.negative)
        cout << "- ";
    cout << num.numerator << " / " << num.denominator;
    return output;
} // end function operator<<
