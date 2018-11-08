/*
 * Fig 8.18: 
 * Using  subscripting and pointer notations with arrays.
*/
#include <iostream>
using namespace std;

int main()
{
    int b[] = { 10, 20, 30, 40}; // create 4-element array b
    int *bPtr = b; // set bPtr to point to array b

    // output array b using array subscript notation
    cout << "Array b printed with:\n\nArray subscript notation\n";

    for (int i = 0; i < 4; ++i)
        cout << "b[" << i << "] = " << b[i] << "\n";

    // output array b using the array name and pointer/offset notation
    cout << "\nPointer/offset notation where "
         << "the pointer is the array name\n";
    
    for ( int offset1 = 0; offset1 < 4; ++offset1)
        cout << "*(b + " << offset1 << ") = " << *(b+offset1) << endl;

    // output array b using bPtr and array subscript notation
    cout << "\nPointer subscript notation\n";

    for ( int j = 0; j < 4; ++j)
        cout << "bPtr[" << j << "] = " << bPtr[j] << '\n';

    cout << "\nPointer/offset notation\n";

    // output array b usinng bPtr and pointer/offset notation
    for (int offset2 = 0; offset2 < 4; ++offset2)
        cout << "*(bPtr + " << offset2 << ") = "
            << *(bPtr + offset2 ) << endl;
} // end main

// return size of ptr
size_t getSize(double *ptr)
{
    return sizeof(ptr);
}