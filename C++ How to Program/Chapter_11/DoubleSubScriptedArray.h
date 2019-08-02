// Ex. 11.7: DoubleSubscriptedArray.h
// Array class definition with overloaded operators.
#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H

#include <iostream>
using namespace std;

class DoubleSubScriptedArray
{
    friend ostream &operator<<(ostream &, const DoubleSubScriptedArray &);
    friend istream &operator>>(istream &, DoubleSubScriptedArray &);

  public:
    explicit DoubleSubScriptedArray(int = 2, int = 2);      // default constructor
    DoubleSubScriptedArray(const DoubleSubScriptedArray &); // copy constructor
    ~DoubleSubScriptedArray();             // destructor
    int getSize() const;  // return size

    const DoubleSubScriptedArray &operator=(const DoubleSubScriptedArray &); // assignment operator
    bool operator==(const DoubleSubScriptedArray &) const;   // equality operator

    // inequality operator; returns opposite of == operator
    bool operator!=(const DoubleSubScriptedArray &right) const
    {
        return !(*this == right); // invokes Array::operator==
    }                             // end function operator !=

    // subscript operator for non-const objects returns modifiable lvalue
    int &operator[](int);

    // subscript operator for const objects returns rvalue
    int operator[](int) const;

    // operator for non-const objects returns modifiable row/column lvalue
    int &operator()(int, int);

    // operator for const objects returns value
    int operator()(int, int) const;

  private:
    int size; // pointer-based array size
    int *ptr; // pointer to first element of pointer-based array
    int rows;
    int cols;
};            // end class Array

#endif