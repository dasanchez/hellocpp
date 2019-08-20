// Ex 13.13: Rectangle.h
// Rectangle class derived from TwoDimensionalShape
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "TwoDimensionalShape.h"

class Rectangle : public TwoDimensionalShape
{
public:
    Rectangle(double base = 0.0, double height = 0.0);

    // keyword virtual signals intent to override
    virtual double getArea() const; // calculate area of rectangle

private:
    double base; // rectangle base
    double height; // rectangle height
};                     // end class Rectangle

#endif // RECTANGLE_H