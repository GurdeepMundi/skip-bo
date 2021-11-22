/**
* @author Cody Hodge <@hodc3720>
* @author Brent Hawkings <@hawb3720>
* @author Julie Wojtiw-Quo <@wojj3720>
* @date 2021-10
*/
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include "PileModel.h"
#include "ArrPileModel.h"
#include "DeckModel.h"
#include "HandModel.h"
#include "CardModel.h"

/**
* A class to implement player information.
*/
class Player {
 public:
      /**
      * Default constructor, defualt name is "Jill".
      * @param name The name of the player.
      */
      Player(std::string name = "Jill");

      /**
      * Destructor
      */
      virtual ~Player();

      /**
      * Returns the player's name
      * @return A string representing the player's name.
      */
      virtual std::string getName();

      // /**
      // * Returns the currentHand
      // * @return the currentHand
      // */
      // HandModel getCurrentHand();
      //
      // /**
      // * Adds a card to the player's hand
      // * @param c a Card* which is to be added to the player's hand
      // */
      // void addCardCurrentHand(CardModel* c);
      //
      // /**
      // * Removes a card from the player's hand
      // * @param c a Card* which is to be removed from the player's hand
      // */
      // void removeCardCurrentHand(int);

      /**
      * Sets a player as computer player status
      */
      virtual void setComputerPlayer();

      /**
      * Checks if a player has computer player status
      */
      virtual bool isComputerPlayer();

      virtual void addToStock(DeckModel*);

      virtual unsigned int handsize();

      virtual int stocksize();

      virtual void addCard(CardModel*);

      virtual CardModel* useCard(int);

      virtual CardModel* usediscard(int);

      virtual CardModel* useStock();

      virtual void usingDiscard(CardModel*, int);

      virtual void removeCard(int);

      virtual void deleteDiscardCard(int);

      virtual void deleteStockCard();

      virtual void displayHand();

      virtual HandModel* returnHand();

      virtual void displayStock();

      virtual PileModel* returnStock();

      virtual void displayDiscard(bool computer);

      // Why on Earth wasn't this called getDiscard?! >:(
      virtual ArrPileModel* returnArrPile();

 private:
     //HandModel currentHand;
     bool computer = false;
     std::string name;
     HandModel* hand = new HandModel;
     PileModel* stock = new PileModel;
     ArrPileModel* discard = new ArrPileModel;
};
#endif //PLAYER_H_INCLUDED
