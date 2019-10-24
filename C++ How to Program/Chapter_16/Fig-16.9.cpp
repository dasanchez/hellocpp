// Fig 16.9
// Demonstrating unique_ptr.

#include <iostream>
#include <memory>
using namespace std;

#include "Integer.h"

// use unique_ptr to manipulate Integer object
int main()
{
    cout << "Creating a unique_ptr object that points to an Integer\n";

    // "aim" unique_ptr at Integer object
    unique_ptr<Integer> ptrToInteger(new Integer(7));

    cout << "\nUsing the unique_ptr to manipulate the Integer\n";
    ptrToInteger->setInteger(99); // use  unique_ptr to set Integer value

    // use unique_ptr to get Integer value
    cout << "Integer after setInteger: " << (*ptrToInteger).getInteger() << endl;
} // end main
