// Ex 13.13: Square.cpp
// Class Square member-function definitions.
#include <iostream>
#include "Square.h" // Square class definition
using namespace std;

// constructor
Square::Square(double s)
    // explicitly call base-class constructor
    : Rectangle(s, s)
{
} // end Rectangle constructor
