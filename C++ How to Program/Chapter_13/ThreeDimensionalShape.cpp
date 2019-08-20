// Ex 13.13: TwoDimensionalShape.cpp
#include <iostream>
#include "ThreeDimensionalShape.h"
using namespace std;

// constructor
ThreeDimensionalShape::ThreeDimensionalShape()
{
 // empty body
} // end ThreeDimensionalShape constructor

// print object information
void ThreeDimensionalShape::print() const
{
    cout << "- 3D shape -" << endl;
    cout << "Surface area: " << getArea() << endl;
    cout << "Volume: " << getVolume() << endl;
    cout << "------------" << endl;
} // end function print