// Fig 22.17: Standard library list class template test program.
#include <iostream>
#include <list>      // list class-template definition
#include <algorithm> // copy algorithm
#include <iterator>  // ostream_iterator iterator
using namespace std;

// prototype for function template printList
template <typename T>
void printList(const list<T> &listRef);

int main()
{
    const int SIZE = 4;             // define array size
    int array[SIZE] = {2, 6, 4, 8}; // create list of ints
    list<int> values;               // create list of ints
    list<int> otherValues;          // create list of ints

    // insert itesm in values
    values.push_front(1);
    values.push_front(2);
    values.push_back(4);
    values.push_back(3);

    cout << "values contains: ";
    printList(values);

    values.sort(); // sort values
    cout << "\nvalues after sorting contains: ";
    printList(values);

    // insert elements of array into otherValues
    otherValues.insert(begin(otherValues), array, array + SIZE);
    cout << "\nAfter insert, otherValues contains: ";
    printList(otherValues);

    // remove otherValues elements and insert at end of values
    values.splice(end(values), otherValues);
    cout << "\nAfter splice, values contains: ";
    printList(values);

    values.sort(); // sort values
    cout << "\nAfter sort, values contains: ";
    printList(values);

    // insert elements of array into otherValues
    otherValues.insert(begin(otherValues), array, array + SIZE);
    otherValues.sort();
    cout << "\nAfter insert and sort, otherValues contains: ";
    printList(otherValues);

    // remove otherValues elements and insert into values in sorted order
    values.merge(otherValues);
    cout << "\nAfter merge:\n    values contains: ";
    printList(values);
    cout << "\n   otherValues  contains: ";
    printList(otherValues);

    values.pop_front(); // remove element from front
    values.pop_back(); // remove element from back
    cout << "\nAfer pop_front and pop_back:\n   values contains: ";
    printList(values);

    values.unique(); // remove duplicate elements
    cout << "\nAfter unique, values contains: ";
    printList(values);

    // swap elements of values and otherValues
    values.swap(otherValues);
    cout << "\nAfter swap: \n   values contains: ";
    printList(values);
    cout << "\n   otherValues contains: ";
    printList(otherValues);
    
    // replace contents of values with elements of otherValues
    values.assign(begin(otherValues), end(otherValues));
    cout << "\nAfter assign, values contains: ";
    printList(values);

    // remove otherValues elements and insert into values in sorted order
    values.merge(otherValues);
    cout << "\nAfter merge, values contains: ";
    printList(values);

    values.remove(4); // remove all 4s
    cout << "\nAfter remove( 4 ), values contains: ";
    printList(values);
    
    cout << endl;
} // end main

//printList function template definition: uses
// ostream_iterator and copy algorithm to output list elements
template <typename T>
void printList(const list<T> &listRef)
{
    if (listRef.empty()) // list is empty
    {
        cout << "List is empty";
    }
    else
    {
        ostream_iterator<T> output(cout, " ");
        copy(begin(listRef), end(listRef), output);
    } // end else
} // end function printList