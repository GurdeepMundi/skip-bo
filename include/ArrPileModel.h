/**
* @author Cody Hodge <@hodc3720>
* @author Brent Hawkings <@hawb3720>
* @author Julie Wojtiw-Quo <@wojj3720>
* @date 2021-10
*/
#ifndef ARRPILEMODEL_H
#define ARRPILEMODEL_H

#include "CardModel.h"
#include "PileModel.h"
#include "DeckModel.h"
#include <vector>

/**
* Maintains an arrangement of piles
*/
class ArrPileModel {
 public:
    /**
    * Arrangement of Piles (Constructor)
    */
    ArrPileModel();

    /**
    * Destructor
    */
    virtual ~ArrPileModel();

    /**
    * Gets the correct pile
    * @return PileModel*
    */
    virtual PileModel* getPile(int pileNum);

    /**
    * Builds the layout of piles of cards
    * @return vector<PileModel*>
    */
    virtual std::vector<PileModel*> buildPileArr();

    /**
    * Inserts a card into the build piles
    * @param CardModel* the card we are adding
    * @param int the number of the pile we are adding to
    * @return bool
    */
    virtual bool insertCard(CardModel*, int);

    /**
    * Plays a card from the discard piles
    * @param int the number of the pile we are adding to
    * @return CardModel*
    */
    virtual CardModel* usediscard(int);

    /**
    * removes a card from the discard piles
    * @param int the number of the pile we are taking from
    */
    virtual void popTopcard(int);

    /**
    * Puts a card in a discard pile
    * @param CardModel* the card to be placed
    * @param int the number of the pile
    */
    virtual void putCardInDiscard(CardModel*, int);

    /**
    * Checks the size
    * @param DeckModel* the deck to be checked
    */
    virtual void checkBuildSize(DeckModel*);

    /**
    * Clears the pile
    * @param int the number of the pile to be cleared
    */
    virtual void clearPile(int);

 protected:
    std::vector<PileModel*> piles;
};
#endif
