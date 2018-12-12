/* 
 * Rectangle.cpp
*/
#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(Point p1, Point p2)
{
    setCoordinates(p1, p2);
}

void Rectangle::setCoordinates(Point p1, Point p2)
{
    if (p1.x < 0 || p1.x > 20)
    {
        p1.x = 1;
    }
    if (p1.y < 0 || p1.y > 20)
    {
        p1.y = 1;
    }
    if (p2.x < 0 || p2.x > 20)
    {
        p2.x = 1;
    }
    if (p2.y < 0 || p2.y > 20)
    {
        p2.y = 1;
    }

    leftEdge = min(p1.x, p2.x);
    rightEdge = max(p1.x, p2.x);

    bottomEdge = min(p1.y, p2.y);
    topEdge = max(p1.y, p2.y);

    width = rightEdge - leftEdge;
    height = topEdge - bottomEdge;
}

float Rectangle::getWidth()
{
    return width;
}

float Rectangle::getHeight()
{
    return height;
}

float Rectangle::calcPerimeter()
{
    return (2 * width + 2 * height);
}

float Rectangle::calcArea()
{
    return width * height;
}

void Rectangle::printCoordinates()
{
    cout << "Corner 1: (" << leftEdge << ", " << topEdge << ")" << endl;
    cout << "Corner 2: (" << rightEdge << ", " << topEdge << ")" << endl;
    cout << "Corner 3: (" << rightEdge << ", " << bottomEdge << ")" << endl;
    cout << "Corner 4: (" << leftEdge << ", " << bottomEdge << ")" << endl;
}

bool Rectangle::isSquare()
{
    if (width == height)
        return true;
    else
        return false;
}