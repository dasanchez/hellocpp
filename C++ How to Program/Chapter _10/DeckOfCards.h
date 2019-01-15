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
    void shuffle();
    bool moreCards() const;

  private:
    vector<Card> deck;
    int currentCard;

}; // end class DeckOfCards

#endif