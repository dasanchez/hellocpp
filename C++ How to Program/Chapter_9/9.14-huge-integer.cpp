/*
 * Ex 9.14: HugeInteger Class
 * Create a class HugeInteger that uses a 40-element array of digits to store
 * integers as large as 40 digits each. Provide member functions input, output,
 * add, and subtract.
 * For comparing HugeInteger objects, provide functions isEqualTo, isNotEqualTo,
 * isGreaterThan, isLessThan, isGreaterThanOrEqualTo, and isLessThanOrEqualTo.
 * Provide a predicate function isZero. 
*/

#include <iostream>
#include <iomanip>
#include "HugeInteger.h"
using namespace std;

int main()
{
    HugeInteger hi1, hi2;
    int inputInt[40] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
                        0, 9, 8, 7, 6, 5, 4, 3, 2, 1,
                        1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
                        0, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int addArray[] = {3, 4, 5, 6, 7, 9};
    int addCount = sizeof(addArray)/sizeof(int);
    hi1.input(inputInt, 40);
    hi2.input(inputInt, 40);

    cout << "Test addition:" << endl;
    hi1.output();
    cout << endl;
    cout << "+" << endl;
    for (int i = 0; i < 40-addCount; ++i)
        cout << " ";
    for (int i = 0; i < addCount; ++i)
        cout << addArray[i];
    cout << endl;
    for (int i =0; i< 40; ++i)
        cout << "-";
    cout << endl;
    hi1.add(addArray, addCount);
    hi1.output();
    cout << endl;

    cout << "Test subtraction:" << endl;
    hi1.output();
    cout << endl << "-" << endl;

    for (int i = 0; i < 40-addCount; ++i)
        cout << " ";
    for (int i = 0; i < addCount; ++i)
        cout << addArray[i];
    cout << endl;
    for (int i =0; i< 40; ++i)
        cout << "-";
    cout << endl;
    hi1.subtract(addArray, addCount);

    hi1.output();
    cout << endl;

    cout << "Test isEqualTo:" << endl;
    hi1.output();
    cout << " is " << (hi1.isEqualTo(hi2) ? "" : "not ") << "equal to ";
    hi2.output();
    cout << endl;

    hi2.add(addArray, addCount);
    hi1.output();
    cout << " is " << (hi1.isEqualTo(hi2) ? "" : "not ") << "equal to ";
    hi2.output();
    cout << endl;

    cout << "Test isNotEqualTo:" << endl;
    if (hi1.isNotEqualTo(hi2))
    {
        hi1.output();
        cout << " is not equal to ";
        hi2.output();
        cout << endl;
    }

    cout << "Test isGreaterThan:" << endl;
    hi1.output();
    cout << " is " <<  (hi1.isGreaterThan(hi2) ? "" : "not " ) << "greater than ";
    hi2.output();
    cout << endl;

    hi2.subtract(addArray, addCount);
    hi2.subtract(addArray, addCount);

    hi1.output();
    cout << " is " <<  (hi1.isGreaterThan(hi2) ? "" : "not " ) << "greater than ";
    hi2.output();
    cout << endl;

    cout << "Test isLessThan:" << endl;
    hi1.output();
    cout << " is " <<  (hi1.isLessThan(hi2) ? "" : "not " ) << "less than ";
    hi2.output();
    cout << endl;

    hi2.add(addArray, addCount);
    hi2.add(addArray, addCount);

    hi1.output();
    cout << " is " <<  (hi1.isLessThan(hi2) ? "" : "not " ) << "less than ";
    hi2.output();
    cout << endl;

    cout << "Test isZero:" << endl;
    hi1.subtract(inputInt, 40);
    hi1.output();
    cout << " is zero: " << (hi1.isZero() ? "yes." : "no.") << endl;
    hi2.output();
    cout << " is zero: " << (hi2.isZero() ? "yes." : "no.") << endl;

} // end main

