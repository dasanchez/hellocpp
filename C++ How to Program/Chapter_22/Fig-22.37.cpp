// Fig 22.37: Standard Library algorithms
// push_heap, pop_heap, make_heap, and sort_heap
#include <iostream>
#include <algorithm> // algorithm definitions
#include <vector>    // vector class-template definition
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    vector<int> v{3, 100, 52, 77, 22, 31, 1, 98, 13, 40};

    cout << "Vector v contains:\n";
    copy(begin(v), end(v), output);

    make_heap(begin(v), end(v)); // create heap from vector v
    cout << "\nVector v after make_heap:\n";
    copy(begin(v), end(v), output);

    sort_heap(begin(v), end(v)); // sort elements with sort_heap
    cout << "\nVector v after sort_heap:\n";
    copy(begin(v), end(v), output);

    // perform the heapsort with push_heap and pop_heap
    vector<int> v2;
    for (auto i : v)
    {
        v2.push_back(i);
        push_heap(begin(v2), end(v2));
        cout << "\nv2 after push_heap(" << i << "): ";
        copy(begin(v2), end(v2), output);
    }

    cout << endl;

    // remove elements from heap in sorted order
    auto count = v2.size();
    for (size_t i = 0; i<count; ++i)
    {
        cout << "\nv2 after " << *(begin(v2)) << " popped from heap\n";
        pop_heap(begin(v2), end(v2)-i);
        copy(begin(v2), end(v2), output);
    }

    cout << endl;
} // end main
