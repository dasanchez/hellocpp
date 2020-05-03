// Fig 22.33: Standard Library algorithms
// inplace_merge, unique_copy, and reverse_copy
#include <iostream>
#include <algorithm> // algorithm definitions
#include <vector>    // vector class-template definition
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    vector<int> v1{1, 3, 5, 7, 9, 1, 3, 5, 7, 9};

    cout << "Vector v1 contains: ";
    copy(begin(v1), end(v1), output);

    // merge first half of v1 with second half of v1 such that
    // v1 contains sorted set of elements after merge
    inplace_merge(begin(v1), begin(v1) + 5, end(v1));

    cout << "\nAfter inplace_merge, v1 contains: ";
    copy(begin(v1), end(v1), output);

    vector<int> results1;

    // copy only unique elements of v1 into results1
    unique_copy(begin(v1), end(v1), back_inserter(results1));
    cout << "\nAfter unique_copy results1 contains: ";
    copy(begin(results1), end(results1), output);

    vector<int> results2;

    // copy elements of v1 into results2 in reverse order
    reverse_copy(begin(v1), end(v1), back_inserter(results2));
    cout << "\nAfter reverse_copy, results2 contains: ";
    copy(begin(results2), end(results2), output);
    
    cout << endl;
} // end main
