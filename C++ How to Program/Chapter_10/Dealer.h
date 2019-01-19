// Ex 10.13 Dealer.h
#ifndef DEALER_H
#define DEALER_H

#include "DeckOfCards.h"
using namespace std;

class Dealer
{
  public:
    Dealer();
    void dealHand(vector<Card>);
    void newCards(vector<Card>);
    int cardsRequested() const;

  private:
    vector<Card> hand;
    int faces[5];
    int changeCount;
    bool changeMask[5];
    void markRepeatedCards();
}; // end class Dealer

#endif