/**
* @author Cody Hodge <@hodc3720>
* @author Brent Hawkings <@hawb3720>
* @author Julie Wojtiw-Quo <@wojj3720>
* @date 2021-10
*/
#ifndef DECKMODEL_H
#define DECKMODEL_H

#include "CardModel.h"
#include "PileModel.h"
#include <vector>
#include <stack>

/**
* Maintains a deck of cards for the game
*/
class DeckModel {
 public:
    /**
    * Deck of cards (Constructor)
    */
    DeckModel();
    /**
    * Destructor
    */
    virtual ~DeckModel();

    /**
    * Shuffes a deck
    */
    virtual void shuffleDeck();

    /**
    * Gets the card on top of the pile
    * @return a CardModel*
    */
    virtual CardModel* getTopCard();

    /**
    * Builds a deck of cards
    * @return vector<CardModel*>
    */
    virtual std::vector<CardModel*> buildDeck();

    /**
    * Gets a deck of cards
    * @return vector<CardModel*>
    */
    virtual std::vector<CardModel*> getDeck();

    /**
    * Gets a vector of garbage cards
    * @return vector<CardModel*>
    */
    virtual std::vector<CardModel*> getGarbage();

    /**
    * Removes all cards from the deck.?
    */
    virtual void removeCardsDup(int);

    /**
    * Gets the current size of a deck
    * @return int
    */
    virtual int getsize();

    virtual CardModel* getFirstCard();

    /**
    * Re-adds the garbade pile to the deck
    */
    virtual void addGarbageToDeck();

    /**
    * Checks the size of the deck
    */
    virtual void checkSize();

    virtual void addBuildToGarbage(std::stack<CardModel*>);

 private:
    std::vector<CardModel*> currentDeck;
    std::vector<CardModel*> garbage;
    int numberOfCards;
};
#endif
