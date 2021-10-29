/**
* @author Cody Hodge <@hodc3720>
* @author Brent Hawkings <@hawb3720>
* @author Julie Wojtiw-Quo <@wojj3720>
* @date 2021-10
*/
#ifndef PILEMODEL_H
#define PILEMODEL_H

#include "CardModel.h"
#include "HandModel.h"
#include <vector>
#include <stack>

/**
* Maintains a pile of cards for the game
*/
class PileModel {
 public:
    /**
    * Pile of cards (Constructor)
    */
    PileModel();
    /**
    * Destructor
    */
    ~PileModel();

    /**
    * Gets the card on top of the pile
    * @return a CardModel*
    */
    CardModel* getTopCard();

    int getTopNum();

    /**
    * Adds a card to a pile of cards
    * @param CardModel* The card that will be added to a pile.
    */
    void addCard(CardModel* c);

    /**
    * Removes top card from a pile of cards
    * @param CardModel* The top card that will be removed from a pile.
    */
    void removeCard();

    /**
    * Returns the number of cards in a pile
    * @return an integer, the number of cards in a pile
    */
    int getNumberOfCards();

    int getSize();

    std::stack<CardModel*> getPile();

    void clearPile();

 private:
    std::stack<CardModel*> currentPile;
    int numberOfCards;
};
#endif
