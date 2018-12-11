/* 
 * Rectangle.cpp
*/
#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(float w, float h)
{
    setWidth(w);
    setHeight(h);
}

void Rectangle::setWidth(float w)
{
    if (w > 0.0 && w < 20.0)
        width = w;
    else
        width = 1.0;
}

void Rectangle::setHeight(float h)
{
    if (h > 0.0 && h < 20.0)
        height = h;
    else
        height = 1.0;
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
    return (2*width + 2* height);
}

float Rectangle::calcArea()
{
    return width*height;
}