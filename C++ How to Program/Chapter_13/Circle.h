// Ex 13.13: Circle.h
// Circle class derived from TwoDimensionalShape
#ifndef CIRCLE_H
#define CIRCLE_H

#include "TwoDimensionalShape.h"

class Circle : public TwoDimensionalShape
{
public:
    Circle(double radius = 0.0);

    // keyword virtual signals intent to override
    virtual double getArea() const; //calculate area of circle

private:
    double radius; // circle radius
};                     // end class Circle

#endif // CIRCLE_H