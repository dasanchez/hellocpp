// Fig 10.5: Increment.cpp
// Using a member initializer to initialize  a constant
// of a built-in data type.
#include <iostream>
#include <cstdlib>
#include "DeckOfCards.h"
using namespace std;

// constructor that initializes the Cards in the deck
DeckOfCards::DeckOfCards()
{
    currentCard = 0;
    srand(time(0));
    // initialize cards
    for (int suit = 0; suit < Card::suitCount; suit++)
    {
        for (int face = 0; face < Card::faceCount; face++)
        {
            Card newCard(face, suit);
            deck.push_back(newCard);
        }
    }
} // end constructor

void DeckOfCards::shuffle()
{
    for (size_t i = 0; i < deck.size(); ++i)
    {
        int cardLocation = rand() % 53;
        Card temp = deck[i];
        deck[i] = deck[cardLocation];
        deck[cardLocation] = temp;
    }
    currentCard = 0;
}

Card DeckOfCards::dealCard()
{
    return deck[currentCard++];
}

vector<Card> DeckOfCards::dealFiveCards()
{
    vector<Card> fiveCards; 
    for (int i = 0; i<5; ++i)
    {
        fiveCards.push_back(dealCard());
    }
    return fiveCards;
}

bool DeckOfCards::moreCards() const
{
    return currentCard < 52;
}