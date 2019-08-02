// Ex 11.7: DoubleSubScriptedArray.cpp
// Array class member-and friend- function definitions.
#include <iostream>
#include <iomanip>
#include <cstdlib> // exit function prototype
#include "DoubleSubScriptedArray.h"
using namespace std;

// default constructor for class Array (default size 10)
DoubleSubScriptedArray::DoubleSubScriptedArray(int rowSize, int colSize)
{
    // validate arraySize
    if (rowSize > 0 && colSize > 0)
    {
        rows = rowSize;
        cols = colSize;
        size = rowSize * colSize;
    }
    else
    {
        throw invalid_argument("Array size must be greater than 0");
    }
    ptr = new int[size]; // create space for pointer-based array

    for (int i = 0; i < size; ++i)
        ptr[i] = 0; // set pointer-based array element
} // end DoubleSubScriptedArray default constructor

// copy constructor for class DoubleSubScriptedArray;
// must receive a reference to prevent infinite recursion
DoubleSubScriptedArray::DoubleSubScriptedArray(const DoubleSubScriptedArray &arrayToCopy)
    : size(arrayToCopy.size)
{
    ptr = new int[size]; // create space for pointer-based array

    for (int i = 0; i < size; ++i)
        ptr[i] = arrayToCopy.ptr[i]; // copy into object
} // end DoubleSubScriptedArray copy constructor

// destructor for class Array
DoubleSubScriptedArray::~DoubleSubScriptedArray()
{
    delete[] ptr; // release pointer-based array space
} // end destructor

// return number of elements of Array
int DoubleSubScriptedArray::getSize() const
{
    return size; // number of elements in Array
} // end function getSize

// overloaded assignment operator;
// const return avoids: (a1 = a2) = a3
const DoubleSubScriptedArray &DoubleSubScriptedArray::operator=(const DoubleSubScriptedArray &right)
{
    if (&right != this) // avoid self-assignment
    {
        // for Arrays of different sizes, deallocate original
        // left-side array, then allocate new left-side array
        if (size != right.size)
        {
            delete[] ptr;        // release space
            size = right.size;   // resize this object
            ptr = new int[size]; // create space for array copy
        }                        // end inner if
        for (int i = 0; i < size; ++i)
            ptr[i] = right.ptr[i]; // copy array into object
        rows = right.rows;
        cols = right.cols;
    }                              // end outer if
    return *this;                  // enables x = y = z, for example
} // end function operator=

// determine if two Arrays are equal and
// return true, otherwise return false
bool DoubleSubScriptedArray::operator==(const DoubleSubScriptedArray &right) const
{
    if (size != right.size)
        return false; // arrays of different number of elements

    for (int i = 0; i < size; ++i)
        if (ptr[i] != right.ptr[i])
            return false; // Array contents are not equal

    return true; // Arrays are equal
} // end function operator==

// overloaded subscript operator for non-const Arrays;
// reference return creates a modifiable lvalue
int &DoubleSubScriptedArray::operator[](int subscript)
{
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size)
        throw out_of_range("Subscript out of range");

    return ptr[subscript]; // reference return
} // end function operator[]

// overloaded subscript operator for const Arrays
// const reference return creates an rvalue
int DoubleSubScriptedArray::operator[](int subscript) const
{
    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= size)
        throw out_of_range("Subscript out of range");

    return ptr[subscript]; // returns copy of this element
} // end function operator[]

int &DoubleSubScriptedArray::operator()(int row, int column)
{
    if (row < 0 || row > rows - 1)
        throw out_of_range("Row out of range");
    else if (column < 0 || column > cols - 1)
        throw out_of_range("Column out of range");
    else
        return ptr[row * cols + column]; // returns reference
}

int DoubleSubScriptedArray::operator()(int row, int column) const
{
    if (row < 0 || row > rows - 1)
        throw out_of_range("Row out of range");
    else if (column < 0 || column > cols - 1)
        throw out_of_range("Column out of range");
    else
        return ptr[row * cols + column]; // returns copy
}

// overloaded input operator for class Array;
// inputs values for entire Array
istream &operator>>(istream &input, DoubleSubScriptedArray &a)
{
    for (int i = 0; i < a.size; ++i)
        input >> a.ptr[i];

    return input; // enables cin >> x >> y
} // end function

// overloaded output operator for class Array
ostream &operator<<(ostream &output, const DoubleSubScriptedArray &a)
{
    int i;
    // output private ptr-based array
    for (i = 0; i < a.size; ++i)
    {
        output << setw(12) << a.ptr[i];
        if ((i + 1) % a.cols == 0) // a.cols columns per row of output
            output << endl;
    } // end for


    return output; // enables cout << x << y;
} // end function operator<<