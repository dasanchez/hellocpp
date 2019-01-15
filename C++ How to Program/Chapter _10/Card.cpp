// Ex 10.10: Card.cpp
#include <iostream>
#include "Card.h"
using namespace std;

string Card::suits[4] = {"clubs", "diamonds", "hearts", "spades"};
string Card::faces[13] = {"ace", "two", "three", "four", "five", "six", "seven",
                          "eight", "nine", "ten", "jack", "queen", "king"};
// constructor
Card::Card(int fa, int su)
    : face(fa), // initializer for non-const member
      suit(su)  // required initializer for const member
{
    // empty body
} // end constructor Increment

string Card::toString() const
{
    return (string(faces[face] + " of " + suits[suit]));
}
