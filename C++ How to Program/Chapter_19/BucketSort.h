// 19.7: BucketSort.h
// Class that creates a vector filled with random integers.
// Provides a function to sort the vector with bucket sort.
#include <vector>
using namespace std;

// BucketSort class definition
class BucketSort
{
public:
    BucketSort(int);              // constructor initializes vector
    void sort();                  // sort vector using bubble sort
    void displayElements() const; // display vector elements

private:
    int size;         // vector size
    vector<int> data; // vector of ints
};                    // end class BucketSort