/*
 * Ex 8.9: Write C++ Statements
 * Assume that long variables value1 and value2
 * have been declared and value1 == 200,000.
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    long value1 = 200000;
    long value2;

    // a. declare variable longPtr to be a pointer
    // to an object of type long.
    long *longPtr;

    // b. assign the address of variable value1 to longPtr.
    longPtr = &value1;

    // c. print the value of the object pointed to by longPtr.
    cout << "*longPtr = " << *longPtr << endl;

    // d. assign the calue of the object pointed to by
    // longPtr to variable value2.
    value2 = *longPtr;

    // e. print the value of value2.
    cout << "value2 = " << value2 << endl;

    // f. print the address of value1.
    cout << "&value1 = " << &value1 << endl;

    // g. print the address stored in longPtr.
    // if the value printed the same as value1's address?
    cout << "longPtr = " << longPtr << endl;
    if (longPtr == &value1)
        cout << "The address stored in longPtr is the same "
             << "as value1's address." << endl;
} // end main

