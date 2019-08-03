// Fig 11.15: Complex.cpp
// Complex class member-function definition
#include <iostream>
#include "Complex.h" // Complex class definition
using namespace std;

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
    : real(realPart),
      imaginary(imaginaryPart)
{
    // empty body
} // end Complex constructor

//addition operator
Complex Complex::operator+(const Complex &operand2) const
{
    return Complex(real + operand2.real,
                   imaginary + operand2.imaginary);
} // end function operator+

// subtraction operator
Complex Complex::operator-(const Complex &operand2) const
{
    return Complex(real - operand2.real,
                   imaginary - operand2.imaginary);
} // end function operator-

Complex Complex::operator*(const Complex &operand2) const
{
    return Complex(real * operand2.real - imaginary * operand2.imaginary,
                   real * operand2.imaginary + imaginary * operand2.real);
} // end function operator*

bool Complex::operator==(const Complex &right) const
{
    if (real != right.real || imaginary != right.imaginary)
        return false; // arrays of different number of elements

    return true; // numbers are equal
}

// overloaded input operator for Complex class;
// inputs values for real and imaginary parts
istream &operator>>(istream &input, Complex &c)
{
    input >> c.real >> c.imaginary;
    return input; // enables cin >> x >> y;
} // end function

// overloaded output operator for Complex class
ostream &operator<<(ostream &output, const Complex &c)
{
    if (c.imaginary < 0)
        cout << c.real << " - " << c.imaginary * (-1) << 'i';
    else
        cout << c.real << " + " << c.imaginary << "i";

    return output; // enables cout << x << y;
} // end function operator<<