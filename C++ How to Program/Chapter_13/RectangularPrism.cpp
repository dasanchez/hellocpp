// Ex 13.13: RectangularPrism.cpp
// Class RectangularPrism member-function definitions.
#include <iostream>
#include "RectangularPrism.h" // Circle class definition
using namespace std;

// constructor
RectangularPrism::RectangularPrism(double b, double h, double d)
    : base(b), height(h), depth(d)
{
} // end RectangularPrism constructor

// calculate area
double RectangularPrism::getArea() const
{
    return 2*(base*height + base*depth + height*depth);
} // end function getArea

// calculate volume
double RectangularPrism::getVolume() const
{
    return base * height * depth;
} // end function getVolume