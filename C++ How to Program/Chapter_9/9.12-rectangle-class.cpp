/*
 * Ex 9.12: Enhancing Class Rectangle
 * Store only the Cartesian coordinates of the four corners of the rectangle.
 * The constructor calls a set function that accepts four sets of coordinates
 * and verifies that each of these is in the first quadrant with no single
 * x- or y- coordinate larger than 20.0.
 * The set function also verifies that the supplied coordinates do, in fact,
 * specify a rectangle.
 * Provide member member functions that calculate the length, width, perimeter,
 * and area. The length is the larger of the two dimensions.
 * Include a predicate function square that determines whether the rectangle
 * is a square. 
*/

#include <iostream>
// #include <vector>
#include "Rectangle.h"
#include "Point.h"
using namespace std;

int main()
{
    Point p1, p2;

    cout << "=Rectangle entry=" << endl;
    cout << "Enter the coordinates of two opposing corners (x1, y1, x2, y2):" << endl;
    cin >> p1.x >>  p1.y >>  p2.x >> p2.y;
    
    Rectangle rect(p1, p2);

    cout << "Width: \t" << rect.getWidth() << endl << "Height: " << rect.getHeight()
         << endl << "Perimeter: " << rect.calcPerimeter() << endl << "Area: " << rect.calcArea()
         << endl << "Square: " << (rect.isSquare() ? "yes" : "no") << endl;

} // end main
