// Ex 13.13: TwoDimensionalShape.cpp
#include <iostream>
#include "TwoDimensionalShape.h"
using namespace std;

// constructor
TwoDimensionalShape::TwoDimensionalShape()
{
 // empty body
} // end TwoDimensionalShape constructor

// print object information
void TwoDimensionalShape::print() const
{
    cout << "- 2D shape -" << endl;
    cout << "Area: " << getArea() << endl;
    cout << "------------" << endl;
} // end function print