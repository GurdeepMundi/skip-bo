/**
   MockPlayer.h
   Defines MockPlayer
   Written on 22/11/2021
   by Austin Ball
   CPSC3720
*/

#include "Player.h"
#include "DeckModel.h"
#include "ArrPileModel.h"
#include "HandModel.h"
#include "PileModel.h"
#include "CardModel.h"
#include "gmock/gmock.h"

class MockPlayer : public Player {
 public:
    MOCK_METHOD(setComputerPlayer, void(), (override));
    MOCK_METHOD(isComputerPlayer, bool(), (const override));
    MOCK_METHOD1(addToStock, void(DeckModel*), (override));
    MOCK_METHOD(handsize, unsigned int(), (const override));
    MOCK_METHOD(stocksize, int(), (const override));
    MOCK_METHOD1(addCard, void(CardModel*), (override));
    MOCK_METHOD1(useCard, CardModel*(int), (const override));
    MOCK_METHOD1(usediscard, CardModel*(int), (const override));
    MOCK_METHOD1(useStock, CardModel*(int), (const override));
    MOCK_METHOD2(usingDiscard, void(CardModel*, int), (const override));
    MOCK_METHOD1(removeCard, void(int), (override));
    MOCK_METHOD1(deleteDiscardCard, void(int), (override));
    MOCK_METHOD(deleteStockCard, void(), (override));
    MOCK_METHOD(displayHand, void(), (override));
    MOCK_METHOD(returnHand, HandModel*(), (override));
    MOCK_METHOD(displayStock, void(), (override));
    MOCK_METHOD(returnStock, PileModel*(), (override));
    MOCK_METHOD1(displayDiscard, void(bool), (override));
    MOCK_METHOD(returnArrPile, ArrPileModel*(), (override));
};
