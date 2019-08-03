// Fig 11.14: Complex.h
// Complex class definition.
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class Complex
{
    friend ostream &operator<<(ostream &, const Complex &);
    friend istream &operator>>(istream &, Complex &);

public:
    Complex(double = 0.0, double = 0.0);      // constructor
    Complex operator+(const Complex &) const; // addition
    Complex operator-(const Complex &) const; // subtraction
    Complex operator*(const Complex &) const; // multiplication
    void print() const;                       // output
private:
    double real;      // real part
    double imaginary; // imaginary part
};                    // end class Complex

#endif