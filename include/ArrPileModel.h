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
    ~ArrPileModel();

    /**
    * Gets the correct pile
    * @return PileModel*
    */
    PileModel* getPile(int pileNum);

    /**
    * Builds the layout of piles of cards
    * @return vector<PileModel*>
    */
    std::vector<PileModel*> buildPileArr();

    /**
    * Inserts a card into the build piles
    * @param CardModel* the card we are adding
    * @param int the number of the pile we are adding to
    * @return bool
    */
    bool insertCard(CardModel*, int);

    /**
    * Plays a card from the discard piles
    * @param int the number of the pile we are adding to
    * @return CardModel*
    */
    CardModel* usediscard(int);

    /**
    * removes a card from the discard piles
    * @param int the number of the pile we are taking from
    */
    void popTopcard(int);

    /**
    * Puts a card in a discard pile
    * @param CardModel* the card to be placed
    * @param int the number of the pile
    */
    void putCardInDiscard(CardModel*, int);

    /**
    * Checks the size
    * @param DeckModel* the deck to be checked
    */
    void checkBuildSize(DeckModel*);

    /**
    * Clears the pile
    * @param int the number of the pile to be cleared
    */
    void clearPile(int);

 private:
    std::vector<PileModel*> piles;
};
#endif
