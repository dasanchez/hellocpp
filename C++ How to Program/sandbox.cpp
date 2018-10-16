// Fig 7.13
// Passing arrays and individual array elements to functions. 
#include <iostream>
#include <iomanip>
using namespace std;

void modifyArray(int [], int); // appears strange; array and size
void modifyElement(int); // receive array element value

int main()
{
    const int arraySize = 5;
    int a[arraySize] = {0, 1, 2, 3, 4};\

    cout << "Effects of passing entire array by reference:"
        << "\nThe values of the original array are:\n";

    // output original array elements
    for (int i= 0; i < arraySize; ++i)
        cout << setw(3) << a[i];
    
    cout << endl;

    // pass array a to modifyArray by reference
    modifyArray(a, arraySize);
    cout << "The vallues of the modified array are:\n";

    // output modified original array elements
    for (int j = 0; j < arraySize; ++j)
        cout << setw(3) << a[j];

    cout << "\n\nEffects of passing array element by value:"
        << "\na[3] before modifyElement: " << a[3] << endl;

    modifyElement(a[3]); // pass array element a[3] by value
    cout << "a[3] after modifyElement:" << a[3] << endl;
} // end main

// in function modifyArray, "b" points to the original array "a" in memory
void modifyArray(int b[], int sizeOfArray)
{
    // multiply each array element by 2
    for (int k = 0; k < sizeOfArray; ++k)
        b[k] *= 2;
} // end function modifyArray

// in function modifyElement, "e" is a local copy of
// array element a[3] passed from main
void modifyElement(int e)
{
    // multiply parameter by 2
    cout << "Value of element in modifyElement: " << (e *= 2 ) << endl;
  } // end function modifyElement
  