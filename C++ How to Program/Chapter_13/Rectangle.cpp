// Ex 13.13: Rectangle.cpp
// Class Rectangle member-function definitions.
#include <iostream>
#include "Rectangle.h" // Circle class definition
using namespace std;

// constructor
Rectangle::Rectangle(double b, double h)
    // explicitly call base-class constructor
    : base(b), height(h)
{
} // end Rectangle constructor

// calculate Rectangle area
double Rectangle::getArea() const
{
    return base * height;
} // end function getArea