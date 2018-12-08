// 7.31: Selection Sort by Recursion
// A selection sort searches an array looking for the smallest element.
// Then, the smallest element is swapped with the first element
// of the array.
// The process is repeated for the subarray beginning with the second
// element of the array.
// Each pass of the array results in one element being placed in
// its proper location.

#include <iostream>
using namespace std;

const int entries = 5;
void selectionSort(int array[], int sizeArray);
void printArray(int array[]);

int main()
{
    int sortArray[entries];

    cout << "Enter " << entries << " integers:" << endl;

    for (int i = 0; i < entries; ++i)
        cin >> sortArray[i];
    cout << "Array before sorting:" << endl;
    printArray(sortArray);

    selectionSort(sortArray, entries);

    cout << "Array after sorting:" << endl;
    printArray(sortArray);
}

void selectionSort(int array[], int sizeArray)
{
    if (sizeArray > 1)
    {
        // find smallest element
        int min = array[0];
        int minIndex = 0;
        for (int index = 1; index < sizeArray; ++index)
        {
            if (array[index] < min)
            {
                min = array[index];
                minIndex = index;
            }
        }
        // swap with first element
        array[minIndex] = array[0];
        array[0] = min;

        // sort remainder of array
        selectionSort(array + 1, sizeArray - 1);
    }
}

void printArray(int array[])
{
    for (int i = 0; i < entries; ++i)
        cout << array[i] << " ";
    cout << endl;
}
