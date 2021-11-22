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
    MOCK_METHOD(void, setComputerPlayer, (), (override));
    MOCK_METHOD(bool, isComputerPlayer, (), (const override));
    MOCK_METHOD(void, addToStock, (DeckModel*), (override));
    MOCK_METHOD(unsigned int, handsize, (), (const override));
    MOCK_METHOD(int, stocksize, (), (const override));
    MOCK_METHOD(void, addCard, (CardModel*), (override));
    MOCK_METHOD(CardModel*, useCard, (int), (const override));
    MOCK_METHOD(CardModel*, usediscard, (int), (const override));
    MOCK_METHOD(CardModel*, useStock, (int), (const override));
    MOCK_METHOD(void, usingDiscard, (CardModel*, int), (const override));
    MOCK_METHOD(void, removeCard, (int), (override));
    MOCK_METHOD(void, deleteDiscardCard, (int), (override));
    MOCK_METHOD(void, deleteStockCard, (), (override));
    MOCK_METHOD(void, displayHand, (), (override));
    MOCK_METHOD(HandModel*, returnHand, (), (override));
    MOCK_METHOD(void, displayStock, (), (override));
    MOCK_METHOD(PileModel*, returnStock, (), (override));
    MOCK_METHOD(void, displayDiscard, (bool), (override));
    MOCK_METHOD(ArrPileModel*, returnArrPile, (), (override));
};
