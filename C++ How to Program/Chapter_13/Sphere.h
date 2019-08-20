// Ex 13.13: Sphere.h
// Sphere class derived from TwoDimensionalShape
#ifndef SPHERE_H
#define SPHERE_H

#include "ThreeDimensionalShape.h"

class Sphere : public ThreeDimensionalShape
{
public:
    Sphere(double radius = 0.0);

    virtual double getArea() const;
    virtual double getVolume() const;

private:
    double radius;
};               // end class Sphere

#endif // SPHERE_H