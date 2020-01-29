// 18.26: Sorting strings
// Write a version of the selection sort routine (Fig 8.20)
// that sorts strings. Use function swap in your solution.

#include <iostream>
#include <string>
using namespace std;

// prototypes
void selectionSort(string[], const int, bool (*)(string, string));
void swap(string *const, string *const);
bool ascending(string, string);
bool descending(string, string);
void printArray(const string[], const int);

int main()
{
    const int arraySize = 10;
    int order;   // 1 = ascending, 2 = descending
    string names[arraySize] = {"Naomi", "James", "Alex", "Amos", "Bobbie",
                               "Ana", "Johnson", "Miller", "Chrisjen", "Drummer"};
    cout << "Enter 1 to sort in ascending order, \n"
         << "Enter 2 to sort in descending order: ";
    cin >> order;
    cout << "\nData items in original order\n";

    // output original array
    printArray(names, arraySize);

    // sort array in ascending order; pass function ascending
    // as an argument to specify ascending sorting order
    if (order == 1)
    {
        selectionSort(names, arraySize, ascending);
        cout << "\nData items in ascending order\n";
    } // end if
    else if (order == 2)
    {
        selectionSort(names, arraySize, descending);
        cout << "\nData items in descending order\n";
    } // end else  part of  if...else

    // output sorted array
    printArray(names, arraySize);
}

void printArray(const string names[], const int arraySize)
{
    for (int i = 0; i < arraySize; ++i)
    {
        cout << names[i];
        if (i < arraySize - 1)
            cout << " -> ";
    }
    cout << endl;
}
// multipurpose selection sort; the parameter compare is a pointer to
// the comparison function that determines the sorting order
void selectionSort(string work[], const int size,
                    bool (*compare)(string, string))
{
    int smallestOrLargest; // index of smalles (or largest) element

    // loop over size-1 elements
    for (int i =0; i< size -1; ++i)
    {
        smallestOrLargest = i; // first index of remaining vector

        // loop to find index of smallest (or largest) element
        for (int index= i + 1; index < size; ++index)
            if (!(*compare)(work[smallestOrLargest], work[index]))
                smallestOrLargest = index;

        swap(&work[smallestOrLargest], &work[i]);
    } // end if
} // end function selectionSort

// swap values at memory locations to which
// element1Ptr and element2Ptr point
void swap(string * const element1Ptr, string * const element2Ptr)
{
    string hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
} // end function swap

// determine whether element a is less than
// element b for an ascending order sort
bool ascending(string a, string b)
{
    return a < b; // returns true if a is less than b
} // end function ascending

// determine whether element a is greater than
// element b for a descending order sort
bool descending(string a, string b)
{
    return a > b; // returns true  if a is greater than b
} // end  function descending