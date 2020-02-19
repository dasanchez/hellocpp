// 19.7: BucketSort.cpp
// Class BucketSort member-function definition.
#include <iostream>
#include <vector>
#include <cstdlib> // prototypes for functions srand and rand
#include <ctime>   // prototype for function time
#include <cmath>
#include "BucketSort.h"
using namespace std;

// constructor fills vector with random integers
BucketSort::BucketSort(int vectorSize)
{
    size = (vectorSize > 0 ? vectorSize : 10); // validate vectorSize
    srand(time(0));                            // seed random number generator using current time

    // fill vector with random ints in range 10-99
    for (int i = 0; i < size; ++i)
        data.push_back(10 + rand() % 90);
} // end BucketSort constructor

// bucket sort algorithm
void BucketSort::sort()
{
    int passCount = 0;
    vector<vector<int>> bucket;
    // loop through each decade
    for (int decade = 0; decade < 2; ++decade)
    {
        bucket.clear();
        bucket.reserve(10);

        for (int i = 0; i < size; ++i)
            bucket[i].clear();

        // 1: distribution pass
        for (int i = 0; i < size; ++i)
        {
            int digit = static_cast<int>(data[i] / pow(10, decade)) % 10;
            bucket[digit].push_back(data[i]);
            passCount++;
        } // end distribution loop

        // 2: gathering pass
        data.clear();
        for (int row = 0; row < 10; ++row)
        {
            for (size_t i = 0; i < bucket[row].size(); ++i)
            {
                data.push_back(bucket[row][i]);
            }
            passCount++;
        } // end gathering loop
    }     // end decade loop
    cout << "Total passes: " << passCount << endl;
} // end function sort

// display elements in vector
void BucketSort::displayElements() const
{
    for (int i = 0; i < size; ++i)
        cout << " " << data[i];
    cout << endl;
} // end function displayElements
