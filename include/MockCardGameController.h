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
    MOCK_METHOD(void, gameStart, (), (override));
    MOCK_METHOD(void, deckSetup, (DeckModel*), (override));
    MOCK_METHOD(void, playerSetup, (Player*, DeckModel*), (override));
    MOCK_METHOD(void, displayBoard, (Player*, Player*, DeckModel*,
                                     ArrPileModel*), (override));
    MOCK_METHOD(void, opponentTurn, (Player*, Player*, DeckModel*,
                                     ArrPileModel*), (override));
    MOCK_METHOD(void, playCards, (Player*, Player*, DeckModel*, ArrPileModel*),
                (override));
    MOCK_METHOD(void, dealHand, (Player*, DeckModel*), (override));
    MOCK_METHOD(void, handPlay, (Player*, ArrPileModel*, int), (override));
    MOCK_METHOD(void, discardPlay, (Player*, ArrPileModel*, int), (override));
    MOCK_METHOD(void, stockPlay, (Player*, ArrPileModel*, int), (override));
    MOCK_METHOD(bool, discardingCard, (Player*, int), (override));
    /* MOCK_METHOD(bool, addingToDiscard, (Player*, Player*, CardModel*, int),
       (override)); */
    MOCK_METHOD(bool, addingToPiles, (ArrPileModel*, CardModel*, int),
                (override));
    MOCK_METHOD(void, discardPilesPick, (Player*, CardModel*, int),
                (override));
    MOCK_METHOD(void, checkBuildSize, (ArrPileModel*, DeckModel*),
                (override));
    MOCK_METHOD(void, help, (int), (override));
    MOCK_METHOD(void, leave, (int), (override));
};
