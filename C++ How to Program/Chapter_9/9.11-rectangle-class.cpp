/*
 * Ex 9.11: Rectangle Class
 * Create a class Rectangle with attributes length and width,
 * each of which defaults to 1. 
 * Provide member functions that calculate the perimeter and
 * the area of the rectangle.
 * Provide set and get functions for the  length and width
 * attributes. The set functions should verify that length
 * and width are each floating-point numbers larger than
 * 0.0 and less than 20.0.
*/

#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    Rectangle rect(10, 5);
    rect.setHeight(4);

    cout << "Width: " << rect.getWidth() << ", height: " << rect.getHeight() << endl;
    cout << "Perimeter: " << rect.calcPerimeter() << endl;
    cout << "Area: " << rect.calcArea() << endl;

} // end main
