/* 
 * Rectangle.cpp
*/
#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(Point p1, Point p2)
{
    setCoordinates(p1, p2);
    setPerimeterCharacter('+');
    setFillCharacter('o');
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

void Rectangle::draw()
{
    // draw the shape enclosed in a 25 x 25 box:
    int ymin = 25 - topEdge;
    int ymax = 25 - bottomEdge;
    int xmin = leftEdge;
    int xmax = rightEdge;
    cout << "ymin = " << ymin << ", ymax = " << ymax << ", xmin = " << xmin << ", xmax = " << xmax << endl;

    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if (i == 0 || i == 25 || j == 0 || j == 25)
            {
                cout << "* ";
                if (j == 25)
                    cout << endl;
                continue;
            }
            else
            {
                if ((i >= ymin && i <= ymax) && (j <= xmax && j >= xmin))
                {
                    if (i == ymin || i == ymax || j == xmin || j == xmax)
                        cout << perimeterChar << ' ';
                    else
                        cout << fillChar << ' ';
                }
                else
                {
                    cout << "  ";
                }
            }
        }
    }
}

void Rectangle::setPerimeterCharacter(char newChar)
{
    perimeterChar = newChar;
}

void Rectangle::setFillCharacter(char newChar)
{
    fillChar = newChar;
}