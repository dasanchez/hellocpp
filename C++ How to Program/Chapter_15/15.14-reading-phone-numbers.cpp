// Fig 15.14: Reading Phone Numbers with an Overloaded Stream
// Extraction Operator.
// In Fig 11.5, the stream extraction and stream insertion operators
// were overloaded for input and output of objects of the PhoneNumber
// class. Rewrite the stream extracion operator to perform the
// following error checking on input. The operator>> function will
// neeed to be reimplemented.
// a) Input the entire phone number into an array. Test that the proper
// number of characters has been entered. There should be a total
// of 14 characters read for a phone number of the form (800) 555-1212.
// Use ios_base-member function clear to set failbit for improper input.
// b) The area code and exchange do not begin with 0 or 1. Test the first
// digit of the area code and exchange portions of the phone number to
// to be sure  that neither begins with 0 or 1. Use ios_base-member
// function clear to set failbit for improper input.
// c) The  middle digit of an area code used to be limited to 0 or 1.
// Test the middle digit for a value of 0 or 1. Use the ios_base-member
// function clear to set failbit for improper input.
// If none of the above operatios resuls in failbit being set for
// improper input, copy the parts of the telephone number into the
// PhoneNumber object's areaCode, exchange and line members. If failbit
// has been set on the input, have the program print an error message
// and end, rather han print the phone number. 


#include <iostream>
#include "PhoneNumber.h"
using namespace std;

int main()
{
    PhoneNumber phone; // create object phone

    cout << "Enter phone number in the form (123) 456-7890:" << endl;

    cin >> phone;

    // cin >> phone invokes operator>> by implicitly issuing
    // the non-member function call operator>>(cin, phone)
    // cin >> phone;

    // cout << "The phone number entered was: ";

    // cout << phone inokes operator<< by implicitly issuing
    // the non-member function call operator<<(cout, phone)
    cout << "Your phone number is " << phone << endl;
} // end main
