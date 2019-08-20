// Ex 13.13: Triangle.h
// Triangle class derived from TwoDimensionalShape
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "TwoDimensionalShape.h"

class Triangle : public TwoDimensionalShape
{
public:
    Triangle(double base = 0.0, double height = 0.0);

    virtual double getArea() const;

private:
    double base;
    double height;
};               // end class Triangle

#endif // TRIANGLE_H