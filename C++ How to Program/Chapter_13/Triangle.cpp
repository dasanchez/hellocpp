// Ex 13.13: Triangle.cpp
// Class Triangle member-function definitions.
#include <iostream>
#include "Triangle.h" // Triangle class definition
using namespace std;

// constructor
Triangle::Triangle(double b, double h)
    : base(b), height(h)
{
} // end Rectangle constructor

double Triangle::getArea() const
{
    return (base * height) / 2;
}

