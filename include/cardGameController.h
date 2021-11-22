/**
* @author Cody Hodge <hodc3720>
* @author Brent Hawkings <hawb3720>
* @author Julie Wojtiw-Quo <wojj3720>
* @date 2021-10
*/
#ifndef CARDGAMECONTROLLER_H
#define CARDGAMECONTROLLER_H

#include "DeckModel.h"
#include "CardModel.h"
#include "ArrPileModel.h"
#include "Player.h"
#include "InputView.h"

/**
* Runs and controlls the entire card game
*/
class CardGameController {
 public:
    /**
    * A card game (Constructor)
    */
    CardGameController(InputView*);
    /**
    * Destructor
    */
    virtual ~CardGameController();

    virtual void gameStart();

    virtual void deckSetup(DeckModel*);

    virtual void playerSetup(Player*, DeckModel*);

    virtual void displayBoard(Player*, Player*, DeckModel*, ArrPileModel*);

    virtual void opponentTurn(Player*, Player*, DeckModel*, ArrPileModel*);

    virtual void playCards(Player*, Player*, DeckModel*, ArrPileModel*);

    virtual void dealHand(Player*, DeckModel*);

    virtual void handPlay(Player*, ArrPileModel*, int);

    virtual void discardPlay(Player*, ArrPileModel*, int);

    virtual void stockPlay(Player*, ArrPileModel*, int);

    virtual bool discardingCard(Player*, int);

    // This method was never defined
    //virtual bool addingToDiscard(Player*, Player*, CardModel*, int);

    virtual bool addingToPiles(ArrPileModel*, CardModel*, int);

    virtual void discardPilesPick(Player*, CardModel*, int);

    virtual void checkBuildSize(ArrPileModel*, DeckModel*);

    virtual void help(int);

    virtual void leave(int);

 private:
    InputView* userInput;
};
#endif
