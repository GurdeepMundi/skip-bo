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

/**
* Runs and controlls the entire card game
*/
class CardGameController {
 public:
    /**
    * A card game (Constructor)
    */
    CardGameController();
    /**
    * Destructor
    */
    ~CardGameController();

    void gameStart();

    void deckSetup(DeckModel*);

    void playerSetup(Player*, DeckModel*);

    void displayBoard(Player*, Player*, DeckModel*, ArrPileModel*);

    void opponentTurn(Player*, Player*, DeckModel*, ArrPileModel*);

    void playCards(Player*, Player*, DeckModel*, ArrPileModel*);

    void dealHand(Player*, DeckModel*);

    void handPlay(Player*, ArrPileModel*, int);

    void discardPlay(Player*, ArrPileModel*, int);

    void stockPlay(Player*, ArrPileModel*, int);

    bool discardingCard(Player*, int);

    bool addingToDiscard(Player*, Player*, CardModel*, int);

    bool addingToPiles(ArrPileModel*, CardModel*, int);

    void discardPilesPick(Player*, CardModel*, int);

    void checkBuildSize(ArrPileModel*, DeckModel*);

    void help(int);

    void leave(int);
};
#endif
