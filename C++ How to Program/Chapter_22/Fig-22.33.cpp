// Fig 22.33: Standard Library functions
// copy_backward, merge, unique, and reverse
#include <iostream>
#include <algorithm> // algorithm definitions
#include <vector>    // vector class-template definition
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    vector<int> v1{1, 3, 5, 7, 9};
    vector<int> v2{2, 4, 5, 7, 9};

    cout << "Vector v1 contains: ";
    copy(begin(v1), end(v1), output);
    cout << "\nVector v2 contains: ";
    copy(begin(v2), end(v2), output);

    vector<int> results(v1.size());

    // place elements of v1 into results in reverse order
    copy_backward(begin(v1), end(v1), end(results));
    cout << "\n\nAfter copy_backward, results contains: ";
    copy(begin(results), end(results), output);

    vector<int> results2;

    // merge elements of v1 and v2 into results2 in sorted order
    merge(begin(v1), end(v1), begin(v2), end(v2), back_inserter(results2));

    cout << "\n\nAfter merge of v1 and v2 results2 contains:\n";
    copy(begin(results2), end(results2), output);

    // eliminate duplicate values from results2
    // auto endLocation = unique(begin(results2), end(results2));
    results2.erase(unique(begin(results2), end(results2)), end(results2));

    cout << "\n\nAfter unique and erase, results2 contains:\n";
    copy(begin(results2), end(results2), output);

    cout << "\n\nVector v1 after reverse: ";
    reverse(begin(v1), end(v1)); // reverse elements of v1
    copy(begin(v1), end(v1), output);

    cout << endl;
} // end main
