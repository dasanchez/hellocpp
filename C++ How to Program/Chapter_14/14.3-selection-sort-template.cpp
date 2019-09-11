// Ex 14.3: Selection Sort Function Template
// Write a function template selectionSort based on Fig 8.13.
// Write a driver program that inputs, sorts, and outputs
// an int array and a float array.

#include <iostream>
#include <iomanip>
#include <typeinfo>

using namespace std;

template<typename T> void selectionSort(T * const array, const int count); // prototype
template<typename T> void swap(T * ptr1, T * ptr2);        // prototype
template<typename T> void printArray(const T *, const int); // prototype

int main()
{
    // array of integers:
    int intArray[] = { 5, 9, 2, 8, 0};
    selectionSort(intArray, sizeof(intArray) / sizeof(intArray[0]));
    printArray(intArray, sizeof(intArray) / sizeof(intArray[0]));   

    float floatArray[] = {4.23, 3320, 0.02, -232.99, 0.0};
    selectionSort(floatArray, sizeof(floatArray) / sizeof(floatArray[0]));
    printArray(floatArray, sizeof(floatArray) / sizeof(floatArray[0]));  

    double doubleArray[] = {11346972364.123, 0.000001, -22.123, 50, 25.555555}; 
    selectionSort(doubleArray, sizeof(doubleArray) / sizeof(doubleArray[0]));
    printArray(doubleArray, sizeof(doubleArray) / sizeof(doubleArray[0]));  
} // end main

// function to sort an array
template<typename T>
void selectionSort(T * const array, const int count)
{
    int smallest; // index of smallest element

    cout << "Selection Sort function called on " << typeid(array[0]).name() << ":\n";

    // loop over size - 1 elements
    for (int i = 0; i < count - 1; ++i)
    {
        smallest = i; // first index of remaining array
        // loop to find index of smallest element
        for (int index = i + 1; index < count; ++index)
            if (array[index] < array[smallest])
                smallest = index;

        swap(&array[i], &array[smallest]);
    } // end if
} // end function selectionSort

// swap values at memory locations to which element1Ptr and elment2Ptr point
template<typename T>
void swap(T * element1Ptr, T * element2Ptr)
{
    T hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
} // end function swap

// print contents of the array
template<typename T>
void printArray(const T * array, const int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
        cout << array[i] << " ";
    cout << endl;
}