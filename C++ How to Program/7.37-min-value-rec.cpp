/* 
7.37: Find the Minimum Value in an Array (with recursion)
Write a recursive function recursiveMinimum that takes an
integer array, a starting subscript and and ending subscript
as arguments, and returns the smallest element of the array.
The function should stop processing and return when the starting
subscript equals the ending subscript.
*/

#include <iostream>
using namespace std;

int recursiveMinimum(int[], int, int);

int main()
{
    const int arraySize = 5;
    int myArray[arraySize] = {10, 4, 7, 28, 323};
    cout << "Minimum value: " << recursiveMinimum(myArray, 0, arraySize) << endl;
}

int recursiveMinimum(int array[], int start, int end)
{
    // here's the trick: use a static variable
    static int min = array[start]; 
    
    if (array[start] < min)
    {
        min = array[start];
    }

    if (start == end)
    {
        return min;
    }
    else
    {
        return recursiveMinimum(array, start + 1, end);
    }
}
