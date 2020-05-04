// Fig 22.35: Standard Library algorithms includes, set_difference,
// set_symmetric_difference, and set_union
#include <iostream>
#include <algorithm> // algorithm definitions
#include <set>       // set class-template definition
#include <iterator>
using namespace std;

int main()
{
    ostream_iterator<int> output(cout, " ");
    set<int> s1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    set<int> s2{4, 5, 6, 7, 8};
    set<int> s3{4, 5, 6, 11, 15};

    cout << "s1 contains: ";
    copy(begin(s1), end(s1), output);
    cout << "\ns2 contains: ";
    copy(begin(s2), end(s2), output);
    cout << "\ns3 contains: ";
    copy(begin(s3), end(s3), output);

    // determine whether set s2 is completely contained in s1
    if (includes(begin(s1), end(s1), begin(s2), end(s2)))
        cout << "\n\ns1 includes s2";
    else
        cout << "\ns2 does not include s2";

    // determine whether set s3 is completely contained in s1
    if (includes(begin(s1), end(s1), begin(s3), end(s3)))
        cout << "\n\ns1 includes s3";
    else
        cout << "\ns1 does not include s3";

    // determine elements of s1 not in s2
    set<int> diff;
    set_difference(begin(s1), end(s1), begin(s2), end(s2), inserter(diff, begin(diff)));
    cout << "\n\nset_difference of s1 and s3 is: ";
    copy(begin(diff), end(diff), output);

    // determine elements in both s1 and s3
    set<int> intersect;
    set_intersection(begin(s1), end(s1), begin(s2), end(s2),
                     inserter(intersect, begin(intersect)));
    cout << "\n\nset_intersection of s1 and s2 is: ";
    copy(begin(intersect), end(intersect), output);

    // determine elements of s1 that are not in s3 and
    // elements of s3 that are not in s1
    set<int> sym_diff;
    set_symmetric_difference(begin(s1), end(s1), begin(s3), end(s3),
                             inserter(sym_diff, begin(sym_diff)));
    cout << "\n\nset_symmetric_difference of s1 and s3 is: ";
    copy(begin(sym_diff), end(sym_diff), output);

    // determine elements that  are in either or both sets
    set<int> union_set;
    set_union(begin(s1), end(s1), begin(s3), end(s3),
              inserter(union_set, begin(union_set)));
    cout << "\n\nset_union of s1 and s3 is: ";
    copy(begin(union_set), end(union_set), output);

    cout << endl;
} // end main
