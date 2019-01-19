// Ex 10.10: DeckOfCards.h
#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include <vector>
#include "Card.h"

class DeckOfCards
{
  public:
    DeckOfCards();
    Card dealCard();
    vector<Card> dealFiveCards();
    vector<Card> dealCards(int);
    void shuffle();
    bool moreCards() const;
    
    // utility functions
    static void sortFaces(int *);
    static int countForward(int *);
    static int countBackward(int *);
    static bool isStraight(int *);
    static int rateHand(vector<Card>, int *);
    static int compareHands(int*, int*);
    static string stringRating(int);

  private:
    vector<Card> deck;
    int currentCard;

}; // end class DeckOfCards

#endif