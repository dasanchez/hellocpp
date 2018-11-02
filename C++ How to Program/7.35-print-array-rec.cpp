// 7.35: Print an Array
// Write a recursive function printArray
// that takes an array, a starting subsscript,
// and an ending subscript as arguments, returns
// nothing and prints the array. The function
// should stop processing and return when the
// startig subscript equals the ending subscript.

#include <iostream>
using namespace std;

void printArray(int [], int, int);

int main()
{
    const int arraySize = 5;
    int myArray[arraySize] = {1, 2, 4, 8, 16};

    printArray(myArray, 0, arraySize);
    cout << endl;
}

void printArray(int array[], int start, int end)
{
    cout << array[start++] << " ";
    if (start==end)
        return; 
    else
        printArray(array, start, end);
}
