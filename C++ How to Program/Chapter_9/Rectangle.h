/*  
 * Rectangle class
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

class Rectangle
{
public:
  Rectangle(Point, Point); // top left and bottom right corners
  void setCoordinates(Point, Point);
  void setPerimeterCharacter(char);
  void setFillCharacter(char);

  float getWidth();
  float getHeight();
  void printCoordinates();
  float calcPerimeter();
  float calcArea();
  bool isSquare();
  void draw();

private:
  Point tlCorner;
  Point trCorner;
  Point brCorner;
  Point blCorner;
  float rightEdge;
  float leftEdge;
  float topEdge;
  float bottomEdge;

  float width;
  float height;
  char perimeterChar;
  char fillChar;
};

#endif