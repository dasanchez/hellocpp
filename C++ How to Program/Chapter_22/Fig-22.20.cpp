// Fig 22.20: Standard Library class set test program.
#include <iostream>
#include <set>
#include <algorithm>
#include <iterator> // ostream_iterator
using namespace std;

// define short name for multiset type used in this program
typedef set<double, less<double>> DoubleSet;

int main()
{
    const int SIZE = 5;
    double a[SIZE] = {2.1, 4.2, 9.5, 2.1, 3.7};
    DoubleSet doubleSet(a, a + SIZE);
    ostream_iterator<double> output(cout, " ");

    cout << "doubleSet contains: ";
    copy(begin(doubleSet), end(doubleSet), output);

    // p represents pair containing const_iterator and bool
    pair<DoubleSet::const_iterator, bool> p;

    // inser 13.8 in doubleSeet; insert returns pair in which
    // p.first represents location of 13.8 in doubleSet and
    // p.second represents whether 13.8 was inserted
    p = doubleSet.insert(13.8); // value not in set
    cout << "\n\n" << *(p.first)
        << (p.second ? " was" : " was not " ) << " inserted";

    cout << "\ndoubleSet contains: ";
    copy(begin(doubleSet), end(doubleSet), output);

    // insert 9.5 in doubleSet
    p = doubleSet.insert(9.5); // value already in use
    cout << "\n\n" << *(p.first)
        << (p.second ? " was" : " was not" ) << "inserted";
    cout << "\ndoubleSet contains: ";
    copy(begin(doubleSet), end(doubleSet), output);
    cout << endl;
} // end main
