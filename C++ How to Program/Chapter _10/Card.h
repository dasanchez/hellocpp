// Ex 10.10 Card.h
#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card
{
  public:
    static const int faceCount = 13;
    static const int suitCount = 4;

    Card(int cardFace, int cardSuit);

    static string faces[13];
    static string suits[4];
    string toString() const;
    int getFace() const;
    int getSuit() const;

  private:
    int face;
    int suit;
}; // end class Card

#endif