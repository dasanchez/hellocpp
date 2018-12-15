// HugeInteger class

#include <iostream>
#include "HugeInteger.h"
using namespace std;

HugeInteger::HugeInteger()
{
    // set number to zero
    for (int i = 0; i < numberLimit; ++i)
    {
        numberArray[i] = 0;
    }
    numberSize = numberLimit;
}

// assign digits from an input array to numberArray
void HugeInteger::input(const int *inputArray, int inputSize)
{
    if (inputSize > numberLimit)
        numberSize = numberLimit;

    if (inputSize <= 0)
        return;

    numberSize = inputSize;

    for (int i = 0; i < numberSize; ++i)
    {
        numberArray[i] = inputArray[i];
    }
}

// print contents of numberArray
void HugeInteger::output()
{
    for (int i = 0; i < numberSize; ++i)
    {
        cout << numberArray[i];
    }
}

void HugeInteger::add(const int *addArray, int addSize)
{
    // Start adding digits from the right:
    bool carry = false;
    int addition = 0;

    for (int i = addSize - 1, j = numberSize - 1; i >= 0; --i, --j)
    {
        addition = addArray[i] + numberArray[j] + (carry ? 1 : 0);
        if (addition >= 10)
            carry = true;
        else
            carry = false;
        numberArray[j] = addition % 10;
        addition = j;
    }
    if (carry)
        numberArray[addition - 1]++; // yes this may result in an error ^^
}

void HugeInteger::subtract(const int *subArray, int subSize)
{
    // Start from the right:
    bool borrow = false;
    int subtraction = 0;
    for (int i = subSize - 1, j = numberSize - 1; i >= 0; --i, j--)
    {
        subtraction = numberArray[j] - subArray[i] - (borrow ? 1 : 0);
        if (subtraction < 0)
        {
            borrow = true;
            subtraction += 10;
        }
        else
            borrow = false;

        numberArray[j] = subtraction;
        subtraction = j;
    }

    if (borrow)
        numberArray[subtraction - 1]--; // yes this may result in an error
}

bool HugeInteger::isEqualTo(HugeInteger hi)
{
    if (numberSize == hi.numberSize)
    {
        for (int i = 0; i < numberSize; ++i)
        {
            if (numberArray[i] != hi.numberArray[i])
                return false;
        }
        return true;
    }
    else
        return false;
}

bool HugeInteger::isNotEqualTo(HugeInteger hi)
{
    return !isEqualTo(hi);
}

bool HugeInteger::isGreaterThan(HugeInteger hi)
{
    if (numberSize > hi.numberSize)
    {
        return true;
    }
    else if (numberSize < hi.numberSize)
    {
        return false;
    }
    else
    {
        // both numbers have the same length
        for (int i = 0; i < numberSize; ++i)
        {
            if (numberArray[i] < hi.numberArray[i])
                return false;
            else if (numberArray[i] > hi.numberArray[i])
                return true;
        }
        return false;
    }
}

bool HugeInteger::isLessThan(HugeInteger hi)
{
    if (numberSize < hi.numberSize)
    {
        return true;
    }
    else if (numberSize > hi.numberSize)
    {
        return false;
    }
    else
    {
        // both numbers have the same length
        for (int i = 0; i < numberSize; ++i)
        {
            if (numberArray[i] > hi.numberArray[i])
                return false;
            else if (numberArray[i] < hi.numberArray[i])
                return true;
        }
        return false;
    }
}

bool HugeInteger::isZero()
{
    for (int i = 0; i < numberSize; ++i)
    {
        if (numberArray[i] != 0)
            return false;
    }
    return true;
}