/*
10.14 Card Shuffling and Dealing
Modify the program from 10.13 so that it can handles the dealer's hand,
but the player is allowed to decide which cards of the player's hand  to
replace. The program should then evaluate both hands to determine who wins.
Now  use this new program to play 20 games against the computer.
Who wins more games?
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
    vector<Card> playerHand;
    int playerRequest = 0;
    int cardRemove;
    int facesDealer[5];
    int facesPlayer[5];
    int dealerRating, playerRating;
    int highestCard;

    cout << "\nShuffling deck...\n";
    deck.shuffle();

    // ask dealer to deal
    cout << "Dealing five cards.\n\n";
    dealer.dealHand(deck.dealFiveCards());
    playerHand = deck.dealFiveCards();

    // prompt player for cards to change
    cout << "Which cards would you like to replace? Select 0 to finish:" << endl;
    for (size_t i = 0; i < playerHand.size(); ++i)
    {
        cout << "[" << i + 1 << "] " << playerHand.at(i).toString() << endl;
    }
    cin >> cardRemove;
    playerRequest = 1;
    while (cardRemove > 0 && playerRequest < 3)
    {
        playerRequest++;
        playerHand.erase(playerHand.begin() + (cardRemove - 1));
        for (size_t i = 0; i < playerHand.size(); ++i)
        {
            cout << "[" << i + 1 << "] " << playerHand.at(i).toString() << endl;
        }
        cin >> cardRemove;
    }

    cout << "Player wants " << playerRequest << " cards, ";

    for (int i=0; i<playerRequest;++i)
    {
        playerHand.push_back(deck.dealCard());
    }

    // dealer requests x cards from the deck
    cout << "dealer wants " << dealer.cardsRequested() << " cards." << endl;
    dealer.newCards(deck.dealCards(dealer.cardsRequested()));

    cout << "Player hand:" << endl;
    for (int i = 0; i<5; ++i)
        cout << playerHand.at(i).toString() << endl;
    cout << "\nDealer hand:" << endl;
    for (int i = 0; i<5; ++i)
        cout << dealer.getHand().at(i).toString() << endl;

    playerRating = DeckOfCards::rateHand(playerHand, facesPlayer);
    dealerRating = DeckOfCards::rateHand(dealer.getHand(), facesDealer);

    cout << "Player has " << DeckOfCards::stringRating(playerRating)
         << ", dealer has " << DeckOfCards::stringRating(dealerRating) << endl;

    if (playerRating > dealerRating)
        cout << "Player wins." << endl;
    else if (playerRating < dealerRating)
        cout << "Dealer wins." << endl;
    else
    {
        cout << "Use highest card method:" << endl;
        highestCard = DeckOfCards::compareHands(facesPlayer, facesDealer);
        if (highestCard == 0)
            cout << "It's a tie." << endl;
        else if (highestCard == 1)
            cout << "Player wins." << endl;
        else if (highestCard == 2)
            cout << "Dealer wins." << endl;
    }


} // end main
