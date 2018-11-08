/*
 * Fig 8.14: 
 * Sizeof operator when used on an array name
 * returns the number of bytes in the array.
*/
#include <iostream>
using namespace std;

size_t getSize(double *); // prototype

int main()
{
    double array[20]; // 20 doubles
    
    cout << "The number of bytes in the array is " << sizeof(array);
    cout << "\nThe number of bytes returned by getSize is "
         << getSize(array) << endl;

} // end main

// return size of ptr
size_t getSize(double *ptr)
{
    return sizeof(ptr);
}