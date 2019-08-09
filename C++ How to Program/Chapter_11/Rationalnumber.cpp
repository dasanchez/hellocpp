// RationalNumber member-function and friend-function definitions.
#include <cctype>           // isdigit function prototype
#include "Rationalnumber.h" // HugeInt class definition
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
RationalNumber::RationalNumber(const long val1, const long val2)
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
    {
        denominator = -denominator;
        numerator = -numerator;
    }

    // reduce numerator and denominator
    reduceFraction();

} // end RationalNumber default constructor

void RationalNumber::reduceFraction()
{
    int small = 1;
    // which number is smaller?
    int numtemp = numerator;
    if (numerator < 0)
        numtemp = -numerator;

    if (numtemp < denominator)
        small = numtemp;
    else if (denominator < numtemp)
        small = denominator;
    else
    {
        if (numerator < 0)
            numerator = -1;
        else
            numerator = 1;

        denominator = 1;
        return;
    }

    for (int i = 2; i <= small; ++i)
    {
        if (numtemp % i == 0 && denominator % i == 0)
        {
            numtemp /= i;
            denominator /= i;
            i = 1;
        }
    }

    if (numerator < 0)
        numerator = -numtemp;
    else
        numerator = numtemp;
}

// addition operator; RationalNumber + RationalNumber
RationalNumber RationalNumber::operator+(const RationalNumber &op2) const
{
    int commonDenominator = denominator * op2.denominator;
    RationalNumber sum((commonDenominator / denominator * numerator) + (commonDenominator / op2.denominator * op2.numerator),
                       commonDenominator);

    sum.reduceFraction();
    return sum;
} // end function operator+

// subtraction operator; RationalNumber - RationalNumber
RationalNumber RationalNumber::operator-(const RationalNumber &op2) const
{
    int commonDenominator = denominator * op2.denominator;
    RationalNumber sum((commonDenominator / denominator * numerator) - (commonDenominator / op2.denominator * op2.numerator),
                       commonDenominator);

    sum.reduceFraction();
    return sum;
}

// multiplication operator; RationalNumber * RationalNumber
RationalNumber RationalNumber::operator*(const RationalNumber &op2) const
{
    RationalNumber rn(numerator * op2.numerator, denominator * op2.denominator);
    rn.reduceFraction();

    return rn;
} // end function operator*

// division operator; RationalNumber / RationalNumber
RationalNumber RationalNumber::operator/(const RationalNumber &op2) const
{
    RationalNumber rn(numerator * op2.denominator, denominator * op2.numerator);
    rn.reduceFraction();

    return rn;
} // end function operator/

// utility function: returns the division of the numbers
double RationalNumber::division() const
{
    return static_cast<double>(numerator/denominator);
}

// less-than operator; RationalNumber < RationalNumber
bool RationalNumber::operator<(const RationalNumber &op2) const
{
    return (division() < op2.division());
} // end function operator<

// less-than-or-equal operator; RationalNumber <= RationalNumber
bool RationalNumber::operator<=(const RationalNumber &op2) const
{
    return (division() <= op2.division());
} // end function operator<=

// greater-than operator; RationalNumber > RationalNumber
bool RationalNumber::operator>(const RationalNumber &op2) const
{
    return (division() > op2.division());
} // end function operator>=

// greater-than-or-equal operator; RationalNumber >= RationalNumber
bool RationalNumber::operator>=(const RationalNumber &op2) const
{
    return (division() >= op2.division());
} // end function operator>=

// equal-to operator; RationalNumber == RationalNumber
bool RationalNumber::operator==(const RationalNumber &op2) const
{
    return (division() == op2.division());
} // end function operator==

// overloaded output operator
ostream &operator<<(ostream &output, const RationalNumber &num)
{
    cout << num.numerator << " / " << num.denominator;
    return output;
} // end function operator<<
