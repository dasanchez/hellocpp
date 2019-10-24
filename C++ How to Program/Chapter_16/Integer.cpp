// Fig 16.8: Integer.cpp
// Integer member function definitions
#include <iostream>
#include "Integer.h"
using namespace std;

// Integer default constructor
Integer::Integer(int i)
: value(i)
{
    cout << "Constructor for Integer " << value << endl; 
} // end Integer constructor

// Integer destructor
Integer::~Integer()
{
    cout << "Destructor for Integer " << value << endl;
} // end Integer destructor

// set Integer value
void Integer::setInteger(int i)
{
    value = i;
} // end function setInteger

// return Integer value
int Integer::getInteger() const
{
    return value;
} // end function getInteger