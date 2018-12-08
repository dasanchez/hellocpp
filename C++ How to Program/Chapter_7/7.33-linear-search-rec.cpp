// 7.33: Linear Search by Recursion
// Use recursive function linearSearch to perform
// a linear search of the array.
// The function should receive an integer array and
// the size of the array as arguments.
// If the search key is found, return the array subscript;
// otherwise, return -1.

#include <iostream>
using namespace std;

const int elements = 6;
int linearSearch(const int array[], int arraySize, int key, int index);

int main()
{
    int searchArray[elements] = {1, 2, 4, 8, 16, 32};
    int key;

    cout << "Enter the key (a power of 2 lower than 50): ";
    cin >> key;

    int result = linearSearch(searchArray, elements, key, 0);
    if (result >= 0)
        cout << "The key is at subscript " << result << "." << endl;
    else
        cout << "The key was not found." << endl;
}

int linearSearch(const int array[], int arraySize, int key, int index)
{
    // cout << "Array size: " << arraySize << ", index: " << index << endl;
    if (array[0] == key)
        return index;
    else if (arraySize == 1)
        return -1;
    else
    {
        index++;
        return linearSearch(array + 1, arraySize - 1, key, index);
    }
}
