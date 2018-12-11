/*  
 * Rectangle class
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
  public:
    Rectangle(float = 1, float = 1);
    void setWidth(float);
    void setHeight(float);
    float getWidth();
    float getHeight();
    float calcPerimeter();
    float calcArea();

  private:
    float width;
    float height;
};

#endif