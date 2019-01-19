/*
10.12 Card Shuffling and Dealing
Use the functions from Exercise 10.11 to write a program that deals two five-card
poker hands, evaluates each hand and determines which is the better hand.
8: Straight flush
7: 4 of a kind
6: Full house (pair, 3 of a kind)
5: Flush
4: Straight
3: 3 of a kind
2: Two pairs
1: One pair
0: High card
*/
#include <iostream>
#include "DeckOfCards.h"
using namespace std;

int main()
{

    int rateOne, rateTwo;
    int facesOne[5];
    int facesTwo[5];
    int highestCard;
    // initialize deck object
    DeckOfCards deck;

    cout << "\nShuffling deck...\n\n";
    deck.shuffle();

    cout << "Dealing five cards: " << endl;
    vector<Card> handOne = deck.dealFiveCards();
    vector<Card> handTwo = deck.dealFiveCards();

    cout << "\nHand one:" << endl;
    rateOne = DeckOfCards::rateHand(handOne, facesOne);
    cout << "\nHand two:" << endl;
    rateTwo = DeckOfCards::rateHand(handTwo, facesTwo);

    cout << "\nHand one: " << DeckOfCards::stringRating(rateOne)
         << ", hand two: " << DeckOfCards::stringRating(rateTwo) << endl;

    if (rateOne > rateTwo)
        cout << "Hand one wins." << endl;
    else if (rateOne < rateTwo)
        cout << "Hand two wins." << endl;
    else
    {
        cout << "Use highest card method:" << endl;
        highestCard = DeckOfCards::compareHands(facesOne, facesTwo);
        if (highestCard == 0)
            cout << "It's a tie." << endl;
        else if (highestCard == 1)
            cout << "Hand one wins." << endl;
        else if (highestCard == 2)
            cout << "Hand two wins." << endl;
    }

} // end main


