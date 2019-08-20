// Ex 13.13: Sphere.cpp
// Class Sphere member-function definitions.
#include <iostream>
#include "Sphere.h" // Triangle class definition
#include <cmath>
using namespace std;

// constructor
Sphere::Sphere(double rad)
    : radius(rad)
{
} // end Sphere constructor

// calculate surface area
double Sphere::getArea() const
{
    return 4 * M_PI * (radius * radius);
} // end getArea function

// calculate volume
double Sphere::getVolume() const
{
    return (4 * M_PI * pow(radius, 3))/3; 
} // end getVolume function
