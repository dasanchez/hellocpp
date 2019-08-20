// Ex 13.13: Shape.h
// Shape abstract base class.
#ifndef SHAPE_H
#define SHAPE_H

#include <string> // C++ standard string class
using namespace std;

class Shape
{
public:
    Shape();
    virtual ~Shape();
    virtual void print() const = 0;

protected:
}; // end class Shape

#endif // SHAPE_H