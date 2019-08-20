// Ex 13.13: Circle.cpp
// Class Circle member-function definitions.
#include <iostream>
#include "Circle.h" // Circle class definition
#include <cmath>
using namespace std;

// constructor
Circle::Circle(double rad)
    // explicitly call base-class constructor
    : radius(rad)
{
} // end Circle constructor

// calculate Circle area
double Circle::getArea() const
{
    return radius*radius*M_PI;
} // end function getArea