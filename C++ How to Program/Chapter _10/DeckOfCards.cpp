// DeckOfCards class
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
    for (int i = 0; i < 5; ++i)
    {
        fiveCards.push_back(dealCard());
    }
    return fiveCards;
}

bool DeckOfCards::moreCards() const
{
    return currentCard < 52;
}

// UTILITY STATIC FUNCTIONS:
// sorts array from min to max
void DeckOfCards::sortFaces(int *faces)
{
    for (int pass = 0; pass < 5 - 1; ++pass) // number of passes
    {
        bool swaps = false;
        for (int i = 0; i < 5 - 1 - pass; ++i) // number of comparisons
        {
            int bubble = faces[i + 1];
            if (faces[i] > bubble) // next element is higher
            {
                faces[i + 1] = faces[i];
                faces[i] = bubble;
                swaps = true;
            }
        }
        if (!swaps) // no further passes required
            break;
    }
}

// returns number of adjacent cards in increasing order
int DeckOfCards::countForward(int *faces)
{
    int current = faces[0];
    int count = 1;
    while (current + 1 == faces[count])
    {
        current = faces[count];
        count++;

        if (count == 5)
            break;
    }
    return count;
}

// count number of adjacent cards starting from the last one, which must be 12 (king)
int DeckOfCards::countBackward(int *faces)
{
    int current = faces[4];
    int count = 0;
    if (current == 12)
    {
        count = 1;
        while (current - 1 == faces[4 - count])
        {
            count++;
            if (count == 4)
                break;
        }
    }
    return count;
}

bool DeckOfCards::isStraight(int *faces)
{
    // check for adjacent faces
    int forCount = countForward(faces);
    if (forCount < 5 && faces[0] == 0)
    {
        // first face is an ace, cout backwards from the end of the array
        forCount += countBackward(faces);
    }

    if (forCount == 5)
        return true;
    return false;
}

int DeckOfCards::rateHand(vector<Card> fiveCards, int handFaces[5])
{
    int faceCount[13] = {0};
    int suitCount[4] = {0};
    int pairCount = 0;
    int triadCount = 0;
    int quadCount = 0;
    int faces[5] = {0};
    bool isFlush = false;

    for (size_t i = 0; i < fiveCards.size(); ++i)
    {
        cout << fiveCards.at(i).toString() << endl;
        faceCount[fiveCards.at(i).getFace()]++;
        suitCount[fiveCards.at(i).getSuit()]++;
        faces[i] = fiveCards.at(i).getFace();
    }

    // sort faces array
    sortFaces(faces);

    // count faces
    for (int i = 0; i < 13; ++i)
    {
        // cout << i << ": " << faceCount[i] << endl;
        if (faceCount[i] == 2)
        {
            pairCount++;
        }
        if (faceCount[i] == 3)
        {
            triadCount++;
        }
        if (faceCount[i] == 4)
        {
            quadCount++;
        }
    }

    // cout << "Counting suits..." << endl;
    for (int i = 0; i < 4; ++i)
    {
        if (suitCount[i] == 5)
        {
            isFlush = true;
        }
    }

    // handFaces = faces;
    for (int i = 0; i < 5; ++i)
        handFaces[i] = faces[i];
    // cout << endl;

    if (isStraight(faces))
    {
        // cout << "Hand is straight";
        if (isFlush)
            return 8;
        else
            return 4;
    }
    else if (quadCount == 1)
        return 7;
    else if (pairCount == 1 && triadCount == 1)
        return 6;
    else if (isFlush)
        return 5;
    else if (triadCount == 1)
        return 3;
    else if (pairCount == 2)
        return 2;
    else if (pairCount == 1)
        return 1;

    return 0;
}

// compares highest values of sorted faces
// return 1 if first hand wins,
// 2 if second hand wins,
// 0 if it's a tie
// assumes ace is lowest value card
int DeckOfCards::compareHands(int handOne[5], int handTwo[5])
{
    for (int i = 0; i < 5; ++i)
        cout << handOne[i] << ' ';
    cout << endl;

    for (int i = 0; i < 5; ++i)
        cout << handTwo[i] << ' ';
    cout << endl;

    for (int i = 4; i >= 0; --i)
    {
        if (handOne[i] > handTwo[i])
        {
            return 1;
        }
        else if (handOne[i] < handTwo[i])
            return 2;
    }
    return 0;
}

string DeckOfCards::stringRating(int rating)
{
    string ratings[9] = {"High card", "One pair", "Two pairs",
                         "Three of a kind", "Straight", "Flush",
                         "Full house", "Four of a kind", "Straight flush"};
    return ratings[rating];
}