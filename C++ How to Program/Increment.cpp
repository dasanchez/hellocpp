// Fig 10.5: Increment.cpp
// Using a member initializer to initialize  a constant
// of a built-in data type.
#include <iostream>
#include "Increment.h"
using namespace std;

// constructor
Increment::Increment(int c, int i)
: count(c), // initializer for non-const member
  increment(i) // required initializer for const member
{
    // empty body
} // end constructor Increment

// print count and increment values
void Increment::print() const
{
    cout << "count = " << count << ", increment = " << increment << endl;
} // end function print