// 19.5: BubbleSort.cpp
// Class BubbleSort member-function definition.
#include <iostream>
#include <vector>
#include <cstdlib> // prototypes for functions srand and rand
#include <ctime>   // prototype for function time
#include "BubbleSort.h"
using namespace std;

// constructor fills vector with random integers
BubbleSort::BubbleSort(int vectorSize)
{
    size = (vectorSize > 0 ? vectorSize : 10); // validate vectorSize
    srand(time(0));                            // seed random number generator using current time

    // fill vector with random ints in range 10-99
    for (int i = 0; i < size; ++i)
        data.push_back(10 + rand() % 90);
} // end BubbleSort constructor

// bubble sort algorithm
void BubbleSort::sort()
{
    int passCount = 0;
    vector<int> tempVector(data);
    // outer loop: run through all elements
    for (int i = 0; i < size; ++i)
    {
        // inner loop: run through all elements comparing n to n+1
        for (int j = 0; j < size - 1; ++j)
        {
                if (tempVector[j] > tempVector[j+1])
                {
                    // swap
                    int temp = tempVector[j];
                    tempVector[j] = tempVector[j+1];
                    tempVector[j+1] = temp;
                } // end if
                passCount++;
        } // end inner loop
    } // end outer loop
    cout << "\nTotal passes for original algorithm: " << passCount << endl;
} // end function sort

// bubble sort algorithm
void BubbleSort::enhancedSort()
{
    int passCount = 0;
    // outer loop: run through all elements
    for (int i = 0; i < size; ++i)
    {
        bool swaps = false;
        // inner loop: run through all elements comparing n to n+1
        for (int j = 0; j < size - 1 - i; ++j)
        {
                if (data[j] > data[j+1])
                {
                    // swap
                    int temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                    swaps = true;
                } // end if
                passCount++;
        } // end inner loop
        if (!swaps)
            break;
    } // end outer loop
    cout << "\nTotal passes for improved algorithm: " << passCount << endl;
} // end function sort

// display elements in vector
void BubbleSort::displayElements() const
{
    for (int i = 0; i < size; ++i)
        cout << " " << data[i];
} // end function displayElements
