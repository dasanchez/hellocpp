// Fig 22.30: Standard Library functions
// Mathematical algorithms of the Standard Library
#include <iostream>
#include <algorithm> // algorithm definitions
#include <numeric>   // accumulate is defined here
#include <vector>    // vector class-template definition
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Vector v before random_shuffle: ";
    copy(begin(v), end(v), output);

    random_shuffle(begin(v), end(v)); // shuffle elements of v
    cout << "\nVector v after random_shuffle: ";
    copy(begin(v), end(v), output);

    vector<int> v2{100, 2, 8, 1, 50, 3, 8, 8, 9, 10};
    cout << "\n\nVector v2 contains: ";
    copy(begin(v2), end(v2), output);

    // count number  of elements in v2 with value 8
    int result = count(begin(v2), end(v2), 8);
    cout << "\nNUmber of elements matcching 8: " << result;

    // count number of elements in v2 that are greater than 9
    result = count_if(begin(v2), end(v2), [](const auto number) { return number > 9; });
    cout << "\nNumber of elements greater than 9: " << result;

    // locate the minimum element in v2
    cout << "\n\nMinimum element in Vector v2 is: "
         << *(min_element(begin(v2), end(v2)));

    // locate the maximum element in v2
    cout << "\n\nMaximum element in Vector v2 is: "
         << *(max_element(begin(v2), end(v2)));

    // calculate sum of elements in vv
    cout << "\n\nThe total of the elements in Vector v is "
         << accumulate(begin(v), end(v), 0);

    // output square of every element in v
    cout << "\n\nThe square of every integer in Vector v is:\n";
    for_each(begin(v), end(v), [](const int i) { cout << i * i << ' '; });

    vector<int> cubes(10);
    // calculate cube of each element in v; place results in cubes
    transform(begin(v), end(v), begin(cubes),
              [](const auto number) { return number * number * number; });
    cout << "\n\nThe cube of every integer in Vector v is:\n";
    copy(begin(cubes), end(cubes), output);

    cout << endl;
} // end main
