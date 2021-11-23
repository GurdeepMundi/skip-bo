/**
   MockCardGameController.h
   Defines MockCardGameController
   Written on 22/11/2021
   by Austin Ball
   CPSC3720
*/

#include "cardGameController.h"
#include "Player.h"
#include "DeckModel.h"
#include "ArrPileModel.h"
#include "HandModel.h"
#include "PileModel.h"
#include "CardModel.h"
#include "gmock/gmock.h"

class MockCardGameController : public CardGameController {
 public:
    MOCK_METHOD(gameStart, void(), (override));
    MOCK_METHOD1(deckSetup, void(DeckModel*), (override));
    MOCK_METHOD2(playerSetup, void(Player*, DeckModel*), (override));
    MOCK_METHOD4(displayBoard, void(Player*, Player*, DeckModel*,
                                     ArrPileModel*), (override));
    MOCK_METHOD4(opponentTurn, void(Player*, Player*, DeckModel*,
                                     ArrPileModel*), (override));
    MOCK_METHOD4(playCards, void(Player*, Player*, DeckModel*, ArrPileModel*),
                (override));
    MOCK_METHOD2(dealHand, void(Player*, DeckModel*), (override));
    MOCK_METHOD3(handPlay, void(Player*, ArrPileModel*, int), (override));
    MOCK_METHOD3(discardPlay, void(Player*, ArrPileModel*, int), (override));
    MOCK_METHOD3(stockPlay, void(Player*, ArrPileModel*, int), (override));
    MOCK_METHOD2(discardingCard, bool(Player*, int), (override));
    /* MOCK_METHOD4(addingToDiscard, bool, addingToDiscard, (Player*, Player*, CardModel*, int),
       (override)); */
    MOCK_METHOD3(addingToPiles, bool(ArrPileModel*, CardModel*, int),
                (override));
    MOCK_METHOD3(discardPilesPick, void(Player*, CardModel*, int),
                (override));
    MOCK_METHOD2(checkBuildSize, void(ArrPileModel*, DeckModel*),
                (override));
    MOCK_METHOD1(help, void(int), (override));
    MOCK_METHOD1(leave, void(int), (override));
};
