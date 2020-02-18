// 19.5: Bubble Sort
// Make the following modifications to iprove the performance of the bubble sort developed
// in Exercise 19.5:
// a. After the first pass, the largest value is guaranteed to be in the highest-numbered
// element of the vector; after the second pass, the two highest values are "in place";
// and so on. Instead of making nine comparisons for a 10-element vector on every pass,
// modify the bubble sort to make only eight comparisons on the second pass, seven on the
// third pass, and so on.
// b. The data in the vector may already be in the proper order or near-proper order, so why
// make nine passes of a 10-element vector if fewer will suffice? Modify the ort to check
// at the end of each pass whether any swaps have been made. If none have been made, the data
// must already be in the proper order, so the program should terminate. If swaps have
// been made, at least one more pass is needed.
// -> The improved algorithm will cut the number of passes in half.

#include <iostream>
#include "BubbleSort.h" // class BubbleSort definition
using namespace std;

int main()
{
    // create object to perform bubble sort
    BubbleSort sortVector(10);

    cout << "Unsorted vector:" << endl;
    sortVector.displayElements(); // print unsorted vector
    cout << endl;

    sortVector.sort();         // sort vector
    sortVector.enhancedSort(); // sort vector with improved algorithm

    cout << "\nSorted vector:" << endl;
    sortVector.displayElements(); // print sorted vector
    cout << endl;
}