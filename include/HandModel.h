/**
* @author Cody Hodge <@hodc3720>
* @author Brent Hawkings <@hawb3720>
* @author Julie Wojtiw-Quo <@wojj3720>
* @date 2021-10
*/
#ifndef HANDMODEL_H
#define HANDMODEL_H

#include "CardModel.h"
#include <vector>

/**
* Maintains a hand of cards for the game
*/
class HandModel {
 public:
    /**
    * Hand of cards (Constructor)
    */
    HandModel();
    /**
    * Destructor
    */
    ~HandModel();
    /**
    * Returns a hand of cards
    * @return std::vector<CardModel*>
    */
    std::vector<CardModel*> GetHand();

    /**
    * Used to add a card to the hand
    * @param c the CardModel* to be put into the player's hand
    */
    void addCard(CardModel* c);

    /**
    * Used to a remove a card from the hand
    * @param cardNumber the CardModel location to be removed from the player's hand
    */
    void removeCard(int cardNumber);

    /**
    * Returns the number of cards in a player's hand
    * @return an integer the number of cards in a hand
    */
    int getNumberOfCards();

    /**
    * Uses/plays a card from hand
    * @param int the position of the card to be played
    * @return CardModel* the card to be used
    */
    CardModel* useCard(int);

 private:
    int numberOfCards;
    std::vector<CardModel*> gameHand;
};
#endif
