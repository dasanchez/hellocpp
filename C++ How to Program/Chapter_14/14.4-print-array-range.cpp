// Ex 14.4: Print Array Range
// Overload function template printArray of Fig 14.1 so that it takes
// two additional integer arguments, namely int lowSubscript and
// int highSubscript. A call to this function will print only the
// designated portion of the array. Validate lowSubscript and highSubscript;
// if either is out of range or if highSubscript is less than or equal to
// lowSubscript, the overloaded printArray should return 0; otherwise,
// printArray should return the number of elements printed. Then modify
// main to exercise both versions of printArray on arrays a, b and c.
// Test all capabilities of both versions of printArray.

#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;

// function template printArray definition
template <typename T>
void printArray(const T *const array, int count)
{
    for (int i = 0; i < count; ++i)
        cout << array[i] << ' ' ;
    cout << endl;
} // end function template printArray

// overladed template printArray definition
template <typename T>
int printArray(const T *const array, const int count, const int lowSubscript, const int highSubscript)
{
    // validation:
    // 1. are subscripts in range?
    if (lowSubscript < 0 || highSubscript >= count)
        return 0;
    // 2. is highSubscript larger than lowSubscript? 
    if (highSubscript - lowSubscript <= 0)
        return 0;
    
    for (int i=lowSubscript; i < highSubscript; ++i)
        cout << array[i] << ' ';
    cout << endl;

    return highSubscript - lowSubscript;
    
}

int main()
{
    // array of integers
    int intArray[] = {5, 9, 2, 8, 0};
    
    // array of floats
    float floatArray[] = {4.23, 3320, 0.02, -232.99, 0.0};

    // array of doubles
    double doubleArray[] = {11346972364.123, 0.000001, -22.123, 50, 25.555555};

    // standard  printArray function
    printArray(intArray, 5);
    
    // overloaded printArray function
    int itemsPrinted = printArray(floatArray, 5, 2, 4);
    cout << "Printed " << itemsPrinted << " items only" << endl;

    itemsPrinted = printArray(doubleArray, 5, 0, 3);
    cout << "Printed " << itemsPrinted << " items only" << endl;

} // end main
