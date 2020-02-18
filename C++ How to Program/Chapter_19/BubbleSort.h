// 19.5: BubbleSort.h
// Class that creates a vector filled with random integers.
// Provides a function to sort the vector with bubble sort.
#include <vector>
using namespace std;

// BubbleSort class definition
class BubbleSort
{
public:
    BubbleSort(int);               // constructor initializes vector
    void sort();                  // sort vector using bubble sort
    void displayElements() const; // display vector elements

private:
    int size;                              // vector size
    vector<int> data;                      // vector of ints
};                                         // end class BubbleSort