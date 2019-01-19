/*
10.13 Card Shuffling and Dealing
Modify the program from 10.12 so that it can simulate the dealer.
The dealer's five-card hand is dealt "face down" so the player cannot see
it. The program should then evaluaate the dealer's hand, and based on
the quality of the hand, the dealer should draw one, two, or three cards to
replace the corresponding number of unneeded cards in the original hand.
The program should then reevaluate the dealer's hand.
*/
#include <iostream>
#include "DeckOfCards.h"
#include "Dealer.h"
using namespace std;

int main()
{
     // initialize deck and dealer objects
    DeckOfCards deck;
    Dealer dealer;

    cout << "\nShuffling deck...\n";
    deck.shuffle();

    // ask dealer to deal
    cout << "Dealing five cards.\n\n";
    dealer.dealHand(deck.dealFiveCards());
    
    // dealer requests x cards from the deck
    cout << "Dealer wants " << dealer.cardsRequested() << " cards." <<endl;
    dealer.newCards(deck.dealCards(dealer.cardsRequested()));

} // end main


