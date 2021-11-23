/**
   MockPlayer.h
   Defines MockPlayer
   Written on 22/11/2021
   by Austin Ball
   CPSC3720
*/
/*
#include "Player.h"
#include "DeckModel.h"
#include "ArrPileModel.h"
#include "HandModel.h"
#include "PileModel.h"
#include "CardModel.h"
#include <string>
#include "gmock/gmock.h"

class MockPlayer : public Player {
 public:
    explicit MockPlayer(std::string) {}
    virtual ~MockPlayer() {}

    MOCK_METHOD0(setComputerPlayer, void(), (override));
    MOCK_METHOD0(isComputerPlayer, bool(), (const override));
    MOCK_METHOD1(addToStock, void(DeckModel*), (override));
    MOCK_METHOD0(handsize, unsigned int(), (const override));
    MOCK_METHOD0(stocksize, int(), (const override));
    MOCK_METHOD1(addCard, void(CardModel*), (override));
    MOCK_METHOD1(useCard, CardModel*(int), (const override));
    MOCK_METHOD1(usediscard, CardModel*(int), (const override));
    MOCK_METHOD1(useStock, CardModel*(int), (const override));
    MOCK_METHOD2(usingDiscard, void(CardModel*, int), (const override));
    MOCK_METHOD1(removeCard, void(int), (override));
    MOCK_METHOD1(deleteDiscardCard, void(int), (override));
    MOCK_METHOD0(deleteStockCard, void(), (override));
    MOCK_METHOD0(displayHand, void(), (override));
    MOCK_METHOD0(returnHand, HandModel*(), (override));
    MOCK_METHOD0(displayStock, void(), (override));
    MOCK_METHOD0(returnStock, PileModel*(), (override));
    MOCK_METHOD1(displayDiscard, void(bool), (override));
    MOCK_METHOD0(returnArrPile, ArrPileModel*(), (override));
};
*/
