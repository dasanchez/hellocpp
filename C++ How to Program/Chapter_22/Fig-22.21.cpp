// Fig 22.21: Standard Library class multimap test program.
#include <iostream>
#include <map> // multimap class-template definition
using namespace std;

// define short name for multimap type used in this program
typedef multimap<int, double, less<int>> Mmid;

int main()
{
    Mmid pairs; // declare the multimap pairs

    cout << "There are currently " << pairs.count(15)
         << " pairs with key 15 in the multimap\n";

    // insert two value_type objects in pairs
    pairs.insert(Mmid::value_type(15, 2.7));
    pairs.insert(Mmid::value_type(15, 99.3));

    cout << "After inserts, there are " << pairs.count(15)
         << " pairs with key 15\n\n";

    // insert five value_type objects in pairs
    pairs.insert(Mmid::value_type(30, 111.11));
    pairs.insert(Mmid::value_type(10, 22.22));
    pairs.insert(Mmid::value_type(25, 33.333));
    pairs.insert(Mmid::value_type(20, 9.345));
    pairs.insert(Mmid::value_type(5, 77.54));

    cout << "Multimap pairs contains:\nKey\tValue\n";

    // use const_iterator to walk through elements of pairs
    for (Mmid::const_iterator iter = begin(pairs);
         iter != end(pairs); iter++)
    {
        cout << iter->first << '\t' << iter->second << '\n';
    }

    cout << endl;

} // end main
