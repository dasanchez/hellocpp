// Ex 10.13: Dealer.cpp
#include <iostream>
#include "Dealer.h"
using namespace std;

// constructor
Dealer::Dealer()
{
    for (int i = 0; i < 5; ++i)
        changeMask[i] = false;
} // end constructor Dealer

void Dealer::dealHand(vector<Card> hand)
{
    int rating = 0;
    this->hand = hand;
    cout << "[Dealer] Hand:" << endl;
    for (size_t i = 0; i < this->hand.size(); ++i)
    {
        cout << this->hand.at(i).toString() << endl;
    }
    rating = DeckOfCards::rateHand(this->hand, faces);
    cout << "Dealer hand has "
         << DeckOfCards::stringRating(rating) << endl;

    // decide how many cards we want
    if (rating >= 4) // straight (flush or not), flush, 2+3, 4 of a kind
        changeCount = 0;
    else if (rating == 3) // three of a kind
        changeCount = 2;
    else if (rating == 2) // two pairs
        changeCount = 1;
    else // one pair or high card
        changeCount = 3;

    // mark which cards we want to don't want to replace
    markRepeatedCards();

    // cout << "[Dealer] Will keep the following cards:" << endl;
    // for (int i = 0; i < 5; ++i)
    // {
    //     if (changeMask[i])
    //         cout << hand.at(i).toString() << endl;
    // }
}

void Dealer::newCards(vector<Card> newCards)
{
    // only replace hands if new ones match the amount requested
    if (changeCount == static_cast<int>(newCards.size()))
    {
        for (int i = 0; i < 5; ++i)
        {
            if (!changeMask[i] && changeCount > 0)
            {
                // replace unwanted cards
                hand.erase(hand.begin() + i);
                changeCount--;
                hand.insert(hand.begin() + i, newCards.at(newCards.size() - 1));
                newCards.pop_back();
            }
        }

        cout << "[Dealer] Hand is now:" << endl;
        for (size_t i = 0; i < hand.size(); ++i)
        {
            cout << hand.at(i).toString() << endl;
        }

        cout << "Dealer hand now has "
             << DeckOfCards::stringRating(DeckOfCards::rateHand(hand, faces)) << endl;
    }
    else
    {
        cout << "Mismatch between new cards and those requested." << endl;
    }
}

int Dealer::cardsRequested() const
{
    return changeCount;
}

void Dealer::markRepeatedCards()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = i + 1; j < 5; ++j)
        {
            if (hand.at(i).getFace() == hand.at(j).getFace())
            {
                // cout << hand.at(i).getFace() << " equals " << hand.at(j).getFace() << endl;
                if (!changeMask[i])
                    changeMask[i] = true;
                if (!changeMask[j])
                    changeMask[j] = true;
            }
        }
    }
}
