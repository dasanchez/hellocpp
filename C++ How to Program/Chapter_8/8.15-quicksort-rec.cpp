/*
 * Ex. 8.15: Quicksort
 * The basic algorithm for a single-subscripted array of values
 * is as follows:
 * a) Partitioning step: Take the first element of the unsorted
 * array and determine its final location in the sorted array
 * (i.e., all values to the left are less than the element, and
 * all values to the right are greater than the element). We now
 * have one lement in its proper location and two unsorted subarrays.
 * b) Recursive step: Perform Step 1 on each unsorted subarray.
 * Write recursive function quickSort to sort a single-subscripted
 * integer array. The function should receive as arguments an
 * integer array, a starting subscript, and an ending subscript.
 * Function partition should be called by quickSort to perform
 * the partitioning step. 
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void printArray(const int[], int);
void quickSort(int[], int, int);
void swapElements(int[], int, int);
int partitionArray(int[], int, int);

int main()
{
    const int arraySize = 10;
    int numberArray[arraySize];

    cout << "Enter " << arraySize << " numbers: ";
    for (int i =0; i< arraySize; ++i)
        cin >>  numberArray[i];
    
    cout << "Before sorting:" << endl;
    printArray(numberArray, sizeof(numberArray) / sizeof(int));
    quickSort(numberArray, 0, sizeof(numberArray) / sizeof(int));
    cout << "After sorting:" << endl;
    printArray(numberArray, sizeof(numberArray) / sizeof(int));
}

void quickSort(int array[], int start, int end)
{
    int pivot = partitionArray(array, start, end);
    if (pivot - start > 1) {
        quickSort(array, start, pivot);
    }
    if (end - (pivot + 1) > 1) {
        quickSort(array, pivot + 1, end);
    }
}

int partitionArray(int array[], int start, int end)
{
    // find the right location the first element of the array
    // by swapping elements left and right, and return
    // the index of the new location
    bool swap = true;
    int leftLimit = start;
    int rightLimit = end - 1;
    int pivotIndex = start;

    while (swap)
    {
        // keep running until no swaps occur
        swap = false;
        // look for a smaller item starting from the rightLimit
        for (int i = rightLimit; i > pivotIndex; --i)
        {
            if (array[i] < array[pivotIndex])
            {
                // swap elements
                swapElements(array, i, pivotIndex);
                leftLimit = pivotIndex + 1;
                pivotIndex = i;
                swap = true;
            }
        }
        // look for a larger item starting from the leftLimit
        for (int j = leftLimit; j < pivotIndex; ++j)
        {
            if (array[j] > array[pivotIndex])
            {
                // swap elements
                swapElements(array, j, pivotIndex);
                rightLimit = pivotIndex - 1;
                pivotIndex = j;
                swap = true;
            }
        }
    }
    return pivotIndex;
}

void swapElements(int array[], int first, int second)
{
    int temp = array[first];
    array[first] = array[second];
    array[second] = temp;
}

void printArray(const int array[], int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
        cout << array[i] << " ";
    cout << endl;
}