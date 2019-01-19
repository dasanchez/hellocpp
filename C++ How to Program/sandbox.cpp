/*
10.12 Card Shuffling and Dealing
Use the functions from Exercise 10.11 to write a program that deals two five-card
poker hands, evaluates each hand and determines which is the better hand.
*/
#include <iostream>
#include "DeckOfCards.h"
using namespace std;

int main()
{
     // initialize deck object
     DeckOfCards deck;

     cout << "Dealing deck before shuffling:";
     int count = 1;
     while (deck.moreCards())
     {
          cout << "Card # " << count++ << ": " << deck.dealCard().toString() << endl;
     }

     cout << "\nShuffling deck...\n\n";
     deck.shuffle();

     cout << "Dealing deck after shuffling: " << endl;
     count = 1;
     while (deck.moreCards())
     {
          cout << "Card # " << count++ << ": " << deck.dealCard().toString() << endl;
     }
} // end main