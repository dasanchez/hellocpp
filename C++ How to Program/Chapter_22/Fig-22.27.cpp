// Fig 22.27: Standard Library functions
// equal, mismatch, and lexicographical_compare
#include <iostream>
#include <algorithm> // algorithm definitions
#include <vector>    // vector class-template definition
#include <iterator>  // ostream_iterator
using namespace std;

int main()
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto v2 = v1;
    vector<int> v3{1, 2, 3, 4, 1000, 6, 7, 8, 9, 10};
    ostream_iterator<int> output(cout, " ");

    cout << "Vector v1 contains:";
    copy(begin(v1), end(v1), output);
    cout << "\nVector v2 contains:";
    copy(begin(v2), end(v2), output);
    cout << "\nVector v3 contains:";
    copy(begin(v3), end(v3), output);    

    // compare vectors v1 and v2 for equality
    bool result = equal(begin(v1), end(v1), begin(v2));
    cout << "\n\nVector 1 " << (result ? "is" : "is not")
        << " equal to vector v2.\n";
    
    // compare vectors v1 and v3 for equality
    result = equal(begin(v1), end(v1), begin(v3));
    cout << "\n\nVector 1 " << (result ? "is" : "is not")
        << " equal to vector v3.\n";

    // check for mismatch between v1 and v3
    auto location = mismatch(begin(v1), end(v1), begin(v3));
    cout << "\nThere is a mismatch between v1 and v3 at location "
        << (location.first - begin(v1)) << "\nwhere v1 contains "
        << *location.first << " and v3 contains " << *location.second
        << "\n\n";

    string s1 = "HELLO";
    string s2 = "BYE BYE";

    // perform lexicographical comparison of c1 and c2
    result = lexicographical_compare(begin(s1), end(s1), begin(s2), end(s2));
    cout << s1 << (result ? " is less than " :
        " is greater than or equal to " ) << s2 << endl;
        
} // end main
