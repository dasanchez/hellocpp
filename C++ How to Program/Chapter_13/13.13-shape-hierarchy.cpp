// Ex 13.13: Shape Hierarchy.
// Implement a Shape hierarchy: each TwoDimensionalShape should contain function
// getArea, and each ThreeDimensionalShape should have members getArea and getVolume
// to calculate the surface area and volume.
// Create a program that uses a vector of Shape pointers to objects of each concrete
// class in the hierarchy.
// The program should print the object to which each vector element points.
// Also, in the loop that processes all the shapes in the vector, determine whether
// each shape is a TwoDimensionalShape or a ThreeDimensionalShape. If it is a 
// TwoDimensionalShape, display its area. If it is a ThreeDimensionalShape, display
// its area and volume.

#include <iostream>
#include <iomanip>
#include <vector>
#include <typeinfo>
#include "Shape.h"
#include "TwoDimensionalShape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "Sphere.h"
#include "RectangularPrism.h"
#include "Cube.h"

using namespace std;

int main()
{
    // set floating-point formatting
    cout << fixed << setprecision(2);

    // create shapes vector
    vector<Shape *> shapes(7);

    // initialize vector with several items
    shapes[0] = new Circle(2);
    shapes[1] = new Rectangle(3, 4);
    shapes[2] = new Square(5);
    shapes[3] = new Triangle(6, 7);
    shapes[4] = new Sphere(8);
    shapes[5] = new RectangularPrism(9, 10, 11); 
    shapes[6] = new Cube(12);
    
    // process each shape polymorphically
    for (size_t i=0; i<shapes.size(); ++i)
    {
        cout << "This object is a " << typeid(*shapes[i]).name() << ':' << endl;
        shapes[i]->print();
        delete shapes[i];
    }
    
} // end main