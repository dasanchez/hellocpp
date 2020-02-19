// 19.7: Bucket Sort
// A bucket sort begins with a one-dimensional vector of positive integers to be sorted
// and a two-dimensional vector of integers with rows indexed from 0 to 9 and columns
// indexed from 0 to n-1, where n is the number of value to be sorted. Each row of the
// two-dimensional vector is referred to as a bucket. Write a class named BucketSort
// containing a function called sort that operates as follows:
// a. Place each value of the one-dimensional vector in a row of the bucket vector, based
// on the value's "ones" (rightmost) digit. For example, 97 is placed in row 7, 3 is placed
// in row 3 and 100 is placed in row 0. This procedure is aclled a distribution pass.
// b. Loop through the bucket vector row by row, and copy the values back to the original
// vector. This procedure is called a gathering pass. The new order of the preceding values
// in the one-dimensional vector is 100, 3, and 97.
// c. Repeat this process for each subsequent digit position (tens, hundreds, thousands,
// etc.).  After the last gathering pass, the original vector is in sorted order.
// The two-dimensional vector of buckets is 10 times the length of the integer vector
// being sorted. This sorting technique provides better performance than a bubble sort,
// but requires much more memory.

#include <iostream>
#include "BucketSort.h" // class BubbleSort definition
using namespace std;

int main()
{
    // create object to perform bubble sort
    BucketSort sortVector(10);

    cout << "Unsorted vector:" << endl;
    sortVector.displayElements(); // print unsorted vector
    cout << endl;

    sortVector.sort(); // sort vector

    cout << "\nSorted vector:" << endl;
    sortVector.displayElements(); // print sorted vector
    cout << endl;
}