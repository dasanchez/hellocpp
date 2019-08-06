// Fig 11.18: Hugeint.cpp
// HugeInt member-function and friend-function definitions.
#include <cctype>    // isdigit function prototype
#include "Hugeint.h" // HugeInt class definition
using namespace std;

// default constructor; conversion constructor that converts
// a long integer into a HugeInt object
HugeInt::HugeInt(long value)
{
    // initialize array to zero
    for (int i = 0; i < digits; ++i)
        integer[i] = 0;
    negative = false;

    // place digits of argument into array
    for (int j = digits - 1; value != 0 && j >= 0; j--)
    {
        integer[j] = value % 10;
        value /= 10;
    } // end for
} // end HugeInt default/conversion constructor

// conversion constructor that converts a character string
// representing a large integer into a HugeInt object
HugeInt::HugeInt(const string &number)
{
    // initialize array to zero
    for (int i = 0; i < digits; ++i)
        integer[i] = 0;

    // place digits of argument into array
    int length = number.size();

    for (int j = digits - length, k = 0; j < digits; ++j, ++k)
        if (isdigit(number[k])) // ensure that character is a digit
        {
            integer[j] = number[k] - '0';
        }
}

int HugeInt::integerSize() const
{
    int i;
    for (i = 0; (integer[i] == 0) && (i <= digits); ++i)
        ; // skip leading zeros
    return (digits - i);
}

// addition operator; HugeInt + HugeInt
HugeInt HugeInt::operator+(const HugeInt &op2) const
{
    HugeInt temp; // temporary result
    int carry = 0;

    for (int i = digits - 1; i >= 0; i--)
    {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;

        // determine whether to carry a 1
        if (temp.integer[i] > 9)
        {
            temp.integer[i] %= 10; // reduce to 0-9
            carry = 1;
        }    // end if
        else // no carry
            carry = 0;
    } // end for

    return temp; // return copy of temporary object
} // end function operator+

// addition operator; HugeInt  + int
HugeInt HugeInt::operator+(int op2) const
{
    // convert op2 to a HugeInt, then invoke
    // operator+ for two HugeInt objects
    return *this + HugeInt(op2);
} // end function operator+

// addition operator;
// HugeInt  + string that represents large integer value
HugeInt HugeInt::operator+(const string &op2) const
{
    // convert op2 to a HugeInt, then invoke
    // operator+ for two HugeInt objects
    return *this + HugeInt(op2);
} // end operator+

// subtraction operator; HugeInt - HugeInt
HugeInt HugeInt::operator-(const HugeInt &op2) const
{
    HugeInt temp;
    int borrow = 0;

    // check if the subtrahend (op2) is larger than the minuend
    if (op2 > *this)
    {
        temp.negative = true;
        for (int i = digits - 1; i >= digits - op2.integerSize(); --i)
        {
            int sub;
            sub = op2.integer[i] - integer[i] - borrow;
            if (sub < 0)
            {
                sub += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            temp.integer[i] = sub;
        }
    }
    else
        for (int i = digits - 1; i >= digits - integerSize(); --i)
        {
            int sub;
            sub = integer[i] - op2.integer[i] - borrow;
            if (sub < 0)
            {
                sub += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            temp.integer[i] = sub;
        }
    return temp;
}

// decade multiplier
HugeInt HugeInt::multiplyDecade(int digit, int decade) const
{
    HugeInt result;
    // multiply HugeInt by the digit
    int carry = 0;
    for (int i = digits - 1; i >= 0; --i)
    {
        int temp = integer[i] * digit + carry;
        carry = temp / 10;
        result.integer[i] = temp % 10;
    }

    // shift HugeInt to the left by decade number
    for (int i = 0; i < decade; ++i)
    {
        for (int j = 0; j < digits - 1; j++)
        {
            result.integer[j] = result.integer[j + 1];
        }
        result.integer[digits - 1] = 0;
    }
    return result;
} // end function multiplyDecade

// multiplication operator; HugeInt * HugeInt
HugeInt HugeInt::operator*(const HugeInt &op2) const
{
    HugeInt temp;

    // cout << multiplyDecade(2, 0) << endl; // multiply by 2
    // cout << multiplyDecade(2, 1) << endl; // multiply by 20
    int decade = 0;
    for (int i = digits - 1; i >= 0; --i)
    {
        // iterate through each digit of op2 and multiply times op1
        temp = temp + multiplyDecade(op2.integer[i], decade++);
    }
    return temp;
} // end function operator*

// less-than operator; HugeInt < HugeInt
bool HugeInt::operator<(const HugeInt &op2) const
{
    if (integerSize() < op2.integerSize())
        return true;
    else if (integerSize() > op2.integerSize())
        return false;
    else
    {
        // both integers have the same amount of digits
        for (int i = digits - integerSize(); i < digits; ++i)
        {
            if (integer[i] > op2.integer[i])
                return false;
            else if (integer[i] < op2.integer[i])
                return true;
        }
        return false;
    }
} // end function operator<

// less-than-or-equal-to operator; HugeInt <= HugeInt
bool HugeInt::operator<=(const HugeInt &op2) const
{
    if (integerSize() < op2.integerSize())
        return true;
    else if (integerSize() > op2.integerSize())
        return false;
    else
    {
        // both integers have the same amount of digits
        for (int i = digits - integerSize(); i < digits; ++i)
        {
            if (integer[i] > op2.integer[i])
                return false;
            else if (integer[i] < op2.integer[i])
                return true;
        }
        return true;
    }
} // end function operator<=

// greater-than operator; HugeInt > HugeInt
bool HugeInt::operator>(const HugeInt &op2) const
{
    if (integerSize() > op2.integerSize())
        return true;
    else if (integerSize() < op2.integerSize())
        return false;
    else
    {
        // both integers have the same amount of digits
        for (int i = digits - integerSize(); i < digits; ++i)
        {
            if (integer[i] > op2.integer[i])
                return true;
            else if (integer[i] < op2.integer[i])
                return false;
        }
        return false;
    }
} // end function operator>

// greater-than-or-equal-to operator; HugeInt >= HugeInt
bool HugeInt::operator>=(const HugeInt &op2) const
{
    if (integerSize() > op2.integerSize())
        return true;
    else if (integerSize() < op2.integerSize())
        return false;
    else
    {
        // both integers have the same amount of digits
        for (int i = digits - integerSize(); i < digits; ++i)
        {
            if (integer[i] > op2.integer[i])
                return true;
            else if (integer[i] < op2.integer[i])
                return false;
        }
        return true;
    }
} // end function operator>=

// equal-to operator; HugeInt == HugeInt
bool HugeInt::operator==(const HugeInt &op2) const
{
    if (integerSize() != op2.integerSize())
        return false;
    else
    {
        for (int i = digits - integerSize(); i < digits; ++i)
        {
            if (integer[i] != op2.integer[i])
                return false;
        }
        return true;
    }
} // end function operator==

// division operator; HugeInt / HugeInt
HugeInt HugeInt::operator/(const HugeInt &op2) const
{
    HugeInt temp;
    // is the dividend equal to the divisor?
    if (*this == op2)
    {
        temp = 1;
    }
    // if the dividend larger than the divisor?
    else if (*this > op2)
    {
        // dividend is larger than the divisor
        // super crappy algorithm: multiply divisor until it's larger than the dividend
        HugeInt quotient(1);
        // shift quotient to the left by decade number
        int decadeDiff = integerSize() - op2.integerSize();
        for (int i = 0; i < decadeDiff; ++i)
        {
            for (int j = 0; j < digits - 1; j++)
            {
                quotient.integer[j] = quotient.integer[j + 1];
            }
            quotient.integer[digits - 1] = 0;
        }

        temp = op2 * quotient;
        while (*this >= temp)
        {
            quotient = quotient + 1;
            temp = op2 * quotient;
        }
        temp = quotient - 1;
    }

    return temp;
}

// overloaded output operator
ostream &operator<<(ostream &output, const HugeInt &num)
{
    int i;

    for (i = 0; (num.integer[i] == 0) && (i <= HugeInt::digits); ++i)
        ; // skip leading zeros

    if (i == HugeInt::digits)
        output << 0;
    else
    {
        if (num.negative)
            output << '-';
        for (; i < HugeInt::digits; ++i)
            output << num.integer[i];
    }
    return output;
} // end function operator<<
