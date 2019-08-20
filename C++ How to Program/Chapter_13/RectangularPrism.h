// Ex 13.13: RectangularPrism.h
// RectangularPrism class derived from ThreeDimensionalShape
#ifndef RECTPRISM_H
#define RECTPRISM_H

#include "ThreeDimensionalShape.h"

class RectangularPrism : public ThreeDimensionalShape
{
public:
    RectangularPrism(double base = 0.0, double height = 0.0, double depth = 0.0);

    // keyword virtual signals intent to override
    virtual double getArea() const; // calculate area of prism
    virtual double getVolume() const; // calculate volume of prism

private:
    double base; // prism base
    double height; // prism height
    double depth; // prism depth
};                     // end class Rectangle

#endif // RECTPRISM_H