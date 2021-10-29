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
      std::string getName();

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
      void setComputerPlayer();

      /**
      * Checks if a player has computer player status
      */
      bool isComputerPlayer();

      void addToStock(DeckModel*);

      int handsize();

      int stocksize();

      void addCard(CardModel*);

      CardModel* useCard(int);

      CardModel* usediscard(int);

      CardModel* useStock();

      void usingDiscard(CardModel*, int);

      void removeCard(int);

      void deleteDiscardCard(int);

      void deleteStockCard();

      void displayHand();

      HandModel* returnHand();

      void displayStock();

      PileModel* returnStock();

      void displayDiscard(bool computer);

      ArrPileModel* returnArrPile();

 protected:
     //HandModel currentHand;
     bool computer = false;

 private:
      std::string name;
      HandModel* hand = new HandModel;
      PileModel* stock = new PileModel;
      ArrPileModel* discard = new ArrPileModel;
};
#endif //PLAYER_H_INCLUDED
