// Fig 22.31: Standard Library algorithms
// iter_swap, swap, and swap_ranges
#include <iostream>
#include <algorithm> // algorithm definitions
#include <vector>    // vector class-template definition
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Vector v contains: ";
    copy(begin(v), end(v), output);

    // swap elements at locations 0 and 1 of vector v
    swap(v[0], v[1]);

    cout << "\nVector v after swapping v[0] and v[1] using swap:\n   ";
    copy(begin(v), end(v), output);

    // use iterators to swap elements at locations 0 and 1 of vector v
    iter_swap(begin(v), begin(v) + 1);
    cout << "\nVector v after swapping v[1] and v[1] sing iter_swap:\n   ";
    copy(begin(v), end(v), output);

    // swap elements in first five elements of vector v with
    // elements in last five elements of vector v
    swap_ranges(begin(v), begin(v) + 5, begin(v) + 5);

    cout << "\nVector v after swapping the first five elements\n"
         << "with the last five elements:\n   ";
    copy(begin(v), end(v), output);

    cout << endl;
} // end main
