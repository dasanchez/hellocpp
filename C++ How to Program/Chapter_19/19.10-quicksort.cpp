// 19.10: Quicksort
// The recursive sorting technique called quicksort uses the following basic algorithm
// for a one-dimensional vector of values:
// a) Partitioning step: take the first element of the unsorted vector and determine its
// final location in the sorted vector. We now have one value in its proper location
// and two unsorted subvectors.
// b) Recursion step: Perform the Partitioning step on each unsorted subvector. When a
// subvector consists of one element, that element's value is in its final location.
// Write recursive function quickSortHelper to sort a one-dimensional integer vector.
// The function should receive as arguments a starting index and an ending indeex
// on the original vector being sorted.

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

class QuickSort
{
public:
    QuickSort(int newSize)
    {
        size = newSize;
        srand(time(0));
        // populate vector
        for (int i = 0; i < size; ++i)
        {
            sortVector.push_back(rand() % 100);
        }
    }
    void quickSortHelper(int start, int end)
    {
        // 1. partitioning step:
        // get the first number in the vector
        int partitionIndex = start;
        int partitionNumber = sortVector.at(partitionIndex);
        int pivot = end;
        bool swapped = true;
        bool smaller = true;
        // look for the place to put this number,
        // starting from the highest position
        while (swapped)
        {
            swapped = false;

            // start from the right looking for a smaller number
            if (smaller)
            {
                for (int i = pivot; i > partitionIndex; --i)
                {
                    if (sortVector.at(i) < partitionNumber)
                    {
                        swap(partitionIndex, i);
                        pivot = partitionIndex + 1;
                        partitionIndex = i;
                        smaller = false;
                        swapped = true;
                        break;
                    }
                } // end smaller loop
            }     // end if smaller
            else
            {
                for (int i = pivot; i < partitionIndex; ++i)
                {
                    if (sortVector.at(i) > partitionNumber)
                    {
                        swap(partitionIndex, i);
                        pivot = partitionIndex - 1;
                        partitionIndex = i;
                        smaller = true;
                        swapped = true;
                        break;
                    }
                } // end if larger loop
            }     // end if larger
        }

        // 2. recursive stage
        // is there only one value left?
        if (partitionIndex - start > 1)
            quickSortHelper(start, partitionIndex - 1);
        if (end - partitionIndex > 1)
            quickSortHelper(partitionIndex + 1, end);
    }

    void sort()
    {
        quickSortHelper(0, sortVector.size() - 1);
    }

    void swap(int a, int b)
    {
        int temp = sortVector.at(a);
        sortVector[a] = sortVector.at(b);
        sortVector[b] = temp;
    }

    void displayElements() const
    {
        for (int i = 0; i < size; ++i)
            cout << setw(3) << sortVector.at(i);
        cout << endl;
    }

private:
    int size;
    vector<int> sortVector;
};

int main()
{
    QuickSort qSort(10);
    qSort.displayElements();
    qSort.sort();
    qSort.displayElements();
}
