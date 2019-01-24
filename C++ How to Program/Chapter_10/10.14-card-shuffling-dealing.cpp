/*
10.14 Card Shuffling and Dealing
Modify the program from 10.13 so that it can handles the dealer's hand,
but the player is allowed to decide which cards of the player's hand  to
replace. The program should then evaluate both hands to determine who wins.
Now  use this new program to play 20 games against the computer.
Who wins more games? -> it's rather even :)
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
    int playerWins = 0;
    const int gamesPlayed = 5;

    for (int gameCount = 0; gameCount < gamesPlayed; ++gameCount)
    {
        cout << "\nShuffling deck...\n";
        deck.shuffle();

        // ask dealer to deal
        cout << "Dealing five cards to player and dealer.\n\n";
        dealer.dealHand(deck.dealFiveCards());
        playerHand = deck.dealFiveCards();

        // prompt player for cards to change
        cout << "Which cards would you like to replace? Select 0 to finish:" << endl;
        for (size_t i = 0; i < playerHand.size(); ++i)
        {
            cout << "[" << i + 1 << "] " << playerHand.at(i).toString() << endl;
        }

        // pick cards to remove
        cin >> cardRemove;
        playerRequest = 1;
        while (cardRemove > 0)
        {
            playerHand.erase(playerHand.begin() + (cardRemove - 1));
            for (size_t i = 0; i < playerHand.size(); ++i)
            {
                cout << "[" << i + 1 << "] " << playerHand.at(i).toString() << endl;
            }

            playerRequest++;
            if (playerRequest > 3)
                break;
            cin >> cardRemove;
        }

        cout << "Player has " << playerHand.size() << " cards and wants " << --playerRequest << ", ";

        for (int i = 0; i < playerRequest; ++i)
        {
            playerHand.push_back(deck.dealCard());
        }

        // dealer requests x cards from the deck
        cout << "dealer wants " << dealer.cardsRequested() << " cards." << endl;
        dealer.newCards(deck.dealCards(dealer.cardsRequested()));

        cout << "\nPlayer hand:" << endl;
        for (size_t i = 0; i < playerHand.size(); ++i)
            cout << playerHand.at(i).toString() << endl;
        cout << "\nDealer hand:" << endl;
        for (size_t i = 0; i < dealer.getHand().size(); ++i)
            cout << dealer.getHand().at(i).toString() << endl;

        // rate hands
        playerRating = DeckOfCards::rateHand(playerHand, facesPlayer);
        dealerRating = DeckOfCards::rateHand(dealer.getHand(), facesDealer);

        cout << "\nPlayer has " << DeckOfCards::stringRating(playerRating)
             << ", dealer has " << DeckOfCards::stringRating(dealerRating) << endl;

        if (playerRating > dealerRating)
        {
            cout << "Player wins." << endl;
            playerWins++;
        }
        else if (playerRating < dealerRating)
            cout << "Dealer wins." << endl;
        else
        {
            cout << "Use highest card method:" << endl;
            highestCard = DeckOfCards::compareHands(facesPlayer, facesDealer);
            if (highestCard == 0)
                cout << "It's a tie." << endl;
            else if (highestCard == 1)
            {
                cout << "Player wins." << endl;
                playerWins++;
            }
            else if (highestCard == 2)
                cout << "Dealer wins." << endl;
        }
    } // end 20 games

    cout << "Player wins " << playerWins << " games out of " << gamesPlayed
         << ". (" << 100 * static_cast<double>(playerWins) / gamesPlayed << "%)." << endl;

} // end main
