// Fig 22.29: Standard Library functions
// replace, replace_if, replace_copy, and replace_copy_if
#include <iostream>
#include <algorithm> // algorithm definitions
#include <vector>    // vector class-template definition
#include <iterator>  // ostream_iterator
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    vector<int> v1{10, 2, 10, 4, 16, 6, 14, 8, 12, 10};
    vector<int> c1(10);
    vector<int> c2(10);
    auto v2 = v1;
    auto v3 = v1;
    auto v4 = v1;

    cout << "Vector v1 before replacing all 10s:\n   ";
    copy(begin(v1), end(v1), output);

    // replace all 10s in v1 with 100
    replace(begin(v1), end(v1), 10, 100);
    cout << "\nVector v after replacing 10s with 100s:\n   ";
    copy(begin(v1), end(v1), output);

    cout << "\n\nVector v2 before replacing all 10s and copying:\n   ";
    copy(begin(v2), end(v2), output);

    // copy from v2 to c1, replaceing 10s with 100s
    replace_copy(begin(v2), end(v2), begin(c1), 10, 100);
    cout << "\nVector c1 after replacing all 10 in v2:\n   ";
    copy(begin(c1), end(c1), output);

    cout << "\n\nVector v3 before replacing values greater than 9:\n   ";
    copy(begin(v3), end(v3), output);
    replace_if(
        begin(v3), end(v3), [](const auto i) { return i > 9; }, 100);
    cout << "\nVector v3 after replacing all values greater"
         << "\nthan 9 with 100s:\n   ";
    copy(begin(v3), end(v3), output);

    cout << "\n\nVector v4 before replacing values all values greater "
         << "than 9 and copying:\n   ";
    copy(begin(v4), end(v4), output);

    // copy v4 to c2, replacing elements greater than 9 with 100
    replace_copy_if(
        begin(v4), end(v4), begin(c2), [](const auto i) { return i > 9; }, 100);
    cout << "\nVector c2 after replacing all values greater "
         << "than 9 in v4:\n   ";
    copy(begin(c2), end(c2), output);

    cout << endl;
} // end main
