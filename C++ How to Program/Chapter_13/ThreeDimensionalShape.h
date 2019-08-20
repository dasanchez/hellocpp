// Ex 13.13: ThreeDimensionalShape.h
// ThreeDimensionalShape class derived from Shape.
#ifndef THREEDIMENSIONALSHAPE_H
#define THREEDIMENSIONALSHAPE_H

#include "Shape.h"

class ThreeDimensionalShape : public Shape
{
public:
    ThreeDimensionalShape();

    virtual void print() const;         // print ThreeDimensional object
    virtual double getArea() const = 0; // calculate surface area
    virtual double getVolume() const = 0; // calculate volume

}; //end class ThreeDimensionalShape

#endif // THREEDIMENSIONALSHAPE_H