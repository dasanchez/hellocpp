// Ex 13.13: Cube.h
// Cube class derived from ThreeDimensionalShape
#ifndef CUBE_H
#define CUBE_H

#include "ThreeDimensionalShape.h"

class Cube : public ThreeDimensionalShape
{
public:
    Cube(double side = 0.0);

    // keyword virtual signals intent to override
    virtual double getArea() const; // calculate area of cube
    virtual double getVolume() const; // calculate volume of cube

private:
    double side;
};                     // end class Cube

#endif // CUBE_H