// Ex 13.13: TwoDimensionalShape.h
// TwoDimensionalShape class derived from Shape.
#ifndef TWODIMENSIONALSHAPE_H
#define TWODIMENSIONALSHAPE_H

#include "Shape.h"

class TwoDimensionalShape : public Shape
{
public:
    TwoDimensionalShape();

    virtual void print() const;         // print TwoDimensional object
    virtual double getArea() const = 0; // calculate area

}; //end class TwoDimensionalShape

#endif // TWODIMENSIONALSHAPE_H