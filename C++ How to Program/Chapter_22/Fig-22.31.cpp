// Fig 22.31: Standard Library search and sort algorithms.
#include <iostream>
#include <algorithm> // algorithm definitions
#include <vector>    // vector class-template definition
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    vector<int> v{10, 2, 17, 5, 16, 8, 13, 11, 20, 7};

    cout << "Vector v contains: ";
    copy(begin(v), end(v), output);

    // locate first occurrence of 16 in v
    auto location = find(begin(v), end(v), 16);
    if (location != end(v)) // found 16
        cout << "\n\nFound 16 at location " << (location - begin(v));
    else // 16 not found
        cout << "\n\n16 not found";

    // locate first occurrence of 100 in v
    location = find(begin(v), end(v), 100);

    if (location != end(v)) // found 100
        cout << "\nFound 100 at location " << (location - begin(v));
    else // 100 not found
        cout << "\n100 not found";

    // locate first occurrence of value greater than 10 in v
    location = find_if(begin(v), end(v), [](const int i) { return i > 10; });

    if (location != end(v)) // found value greater than 10
        cout << "\n\nThe first value greater than 10 is " << *location
             << "\nfound at location " << (location - begin(v));
    else // value greater than 10 not found
        cout << "\n\nNo values greater than 10 were found";

    // sort elements of v
    sort(begin(v), end(v));
    cout << "\n\nVector v after sort: ";
    copy(begin(v), end(v), output);

    // use binary_search to locate 13 in v
    if (binary_search(begin(v), end(v), 13))
        cout << "\n\n13 was found in v";
    else
        cout << "\n\n13 was not found in v";

    // use binary_search to locate 100 in v
    if (binary_search(begin(v), end(v), 100))
        cout << "\n\n100 was found in v";
    else
        cout << "\n\n100 was not found in v";

    cout << endl;
} // end main
