// 19.5: Bubble Sort
// Implement bubble sort. It's called bubble sort or sinking sort because smaller
// values gradually "bubble" their way to the top of the vector like air bubbles
// rising in water, while the larger values sink to the bottom otf the vector.
// The technique uses nested loops to make several passes through the vector.
// Each pass compares successive pairs of elements. If a pair is in increasing
// order (or the values are equal), the bubble sort leaves the values as they are.
// If a pair is in decreasing order, the bubble sort swaps their values in the vector.
// After one pass, the largest value will be in the last element. After two passes, 
// the largest two values will be in the last two elements. Explain why bubble sort
// is an O(n^2) algorithm.
// -> As the vector size grows very large, the number of passes the algorithm needs
// needs to make on it approaches the size of the vector times itself.


#include <iostream>
#include "BubbleSort.h" // class BubbleSort definition
using namespace std;

int main()
{
    // create object to perform bubble sort
    BubbleSort sortVector(10);

    cout << "Unsorted vector:" << endl;
    sortVector.displayElements(); // print unsorted vector
    cout << endl
         << endl;

    sortVector.sort(); // sort vector

    cout << "Sorted vector:" << endl;
    sortVector.displayElements(); // print sorted vector
    cout << endl;
}