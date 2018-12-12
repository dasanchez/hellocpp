/*
 * Ex 9.13: Enhancing Class Rectangle
 * Modify class Rectangle to include a draw function that displays the rectangle
 * inside a 25-by-25 box enclosing the portion of the first quadrant in which
 * the rectangle resides.
 * Include a setFillCharacter function to specity the character out of which the
 * body of the rectangle ill be drawn.
 * Include a setPerimeterCharacter function to specify the character that will be
 * used to draw the border of the rectangle.
*/

#include <iostream>
#include "Rectangle.h"
#include "Point.h"
using namespace std;

int main()
{
    Point p1(16, 12);
    Point p2(4, 5);

    Rectangle rect(p1, p2);
    rect.setPerimeterCharacter('O');
    rect.setFillCharacter('x');

    rect.draw();

} // end main
