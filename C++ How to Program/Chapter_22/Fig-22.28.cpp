// Fig 22.28: Standard Library functions
// remove, remove_if, remove_copy, and remove_copy_if
#include <iostream>
#include <algorithm> // algorithm definitions
#include <vector>    // vector class-template definition
#include <iterator>  // ostream_iterator
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    vector<int> v{10, 2, 10, 4, 16, 6, 14, 8, 12, 10};
    auto v2 = v;
    auto v3 = v;
    auto v4 = v;
    vector<int>::iterator newLastElement;

    cout << "Vector v before removing all 10s:\n   ";
    copy(begin(v), end(v), output);

    // remove all 10s from v
    newLastElement = remove(begin(v), end(v), 10);
    cout << "\nVector v after removing all 10s:\n   ";
    copy(begin(v), end(v), output);

    vector<int> c(10);
    cout << "\n\nVector v2 before removing all 10s and copying:\n   ";
    copy(begin(v2), end(v2), output);

    // copy from v2 to c, removing 10s in the process
    remove_copy(begin(v2), end(v2), begin(c), 10);
    cout << "\nVector c after removing all 10s from v2:\n   ";
    copy(begin(c), end(c), output);

    cout << "\n\nVector v3 before removing all elements"
         << "\ngreater than 9:\n";
    copy(begin(v3), end(v3), output);

    // remove elements greater than 9 from v3
    newLastElement = remove_if(begin(v3), end(v3), [](auto i) { return i > 9; });
    cout << "\nVector v3 after removing all elements"
         << "\ngreater than 9:\n";
    copy(begin(v3), newLastElement, output);

    cout << "\n\nVector v4 before removing all elements"
        << "\ngreater than 9 and copying:\n   ";
    copy(begin(v4), end(v4), output);

    // copy elements from v4 to c2, removing elements greater
    // than 9 in the process
    vector<int> c2(10);
    remove_copy_if(begin(v4), end(v4), begin(c2), [] (auto i) {return i > 9;});
    cout << "\nVector c2 after removing all elements"
        << "\ngreater than 9 from v4:\n   ";
    copy(begin(c2), end(c2), output);

    cout << endl;
} // end main
