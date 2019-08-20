// Ex 13.13: Cube.cpp
// Class Cube member-function definitions.
#include <iostream>
#include "Cube.h" // Circle class definition
using namespace std;

// constructor
Cube::Cube(double s)
    : side(s)
{
} // end Cube constructor

// calculate area
double Cube::getArea() const
{
    return 6*(side*side);
} // end function getArea

// calculate volume
double Cube::getVolume() const
{
    return (side * side * side);
} // end function getVolume