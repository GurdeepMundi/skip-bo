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
#include "gtest/gtest.h"

using ::testing::Expectation;
using ::testing::Return;

class MockCardGameController : public CardGameController {
 public:
  explicit MockCardGameController() {}
  virtual ~MockCardGameController() {}
  MOCK_METHOD0(gameStart, void());
  MOCK_METHOD1(deckSetup, void());
  MOCK_METHOD2(playerSetup, void());
  MOCK_METHOD4(displayBoard, void());
  MOCK_METHOD4(opponentTurn, void());
  MOCK_METHOD4(playCards, void());
  MOCK_METHOD2(dealHand, void());
  MOCK_METHOD3(handPlay, void());
  MOCK_METHOD3(discardPlay, void());
  MOCK_METHOD3(stockPlay, void());
  MOCK_METHOD2(discardingCard, bool());
    /* MOCK_METHOD(bool, addingToDiscard, (Player*, Player*, CardModel*, int),
       (override)); */

  MOCK_METHOD3(addingToPiles, bool());
  MOCK_METHOD3(discardPilesPick, void());
  MOCK_METHOD2(checkBuildSize, void());
  MOCK_METHOD1(help, void());
  MOCK_METHOD1(leave, void());
};
