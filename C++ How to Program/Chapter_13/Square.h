// Ex 13.13: Square.h
// Square class derived from Rectangle
#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle
{
public:
    Square(double side = 0.0);

};               // end class Square

#endif // SQUARE_H