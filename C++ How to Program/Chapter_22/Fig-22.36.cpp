// Fig 22.36: Standard Library functions
// lower_bound, upper_bound, and equal_range
// for a sorted sequence of values.
#include <iostream>
#include <algorithm> // algorithm definitions
#include <vector>       // vector class-template definition
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    vector<int> v{2, 2, 4, 4, 4, 6, 6, 6, 6, 8};

    cout << "Vector v contains:\n";
    copy(begin(v), end(v), output);

    // determine lower-bound insertion point for 6 in v
    auto lower = lower_bound(begin(v), end(v), 6);
    cout << "\n\nLower bound of 6 is element "
        << (lower - begin(v)) << " of vector v";

    // determine upper-bound insertion point for 6 in v
    auto upper = upper_bound(begin(v), end(v), 6);
    cout << "\n\nUpper bound of 6 is element "
        << (upper - begin(v)) << " of vector v";

    // use equal_range to determine both the lower- and
    // upper-bound insertion points for 6
    auto eq = equal_range(begin(v), end(v), 6);
    cout << "\nUsing equal_range:\n   Lower bound of 6 is element "
        << (eq.first - begin(v)) << " of vector v";
    cout << "\nUsing equal_range:\n   Upper bound of 6 is element "
        << (eq.second - begin(v)) << " of vector v";

    // determine lower-bound insertion point for 5 in v
    lower = lower_bound(begin(v), end(v), 5);
    cout << "\n\nLower bound of 5 is element "
        << (lower - begin(v)) << " of vector v";

    // determine upper-bound insertion point for 7 in v
    upper = upper_bound(begin(v), end(v), 7);
    cout << "\n\nUpper bound of 7 is element "
        << (upper - begin(v)) << " of vector v";

    // use equal_range to determine both the lower- and
    // upper-bound insertion points for 5
    eq = equal_range(begin(v), end(v), 5);
    cout << "\nUsing equal_range:\n   Lower bound of 5 is element "
        << (eq.first - begin(v)) << " of vector v";
    cout << "\nUsing equal_range:\n   Upper bound of 5 is element "
        << (eq.second - begin(v)) << " of vector v";

    cout << endl;
} // end main
