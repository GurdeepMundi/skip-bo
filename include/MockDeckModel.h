/**
   MockDeckModel.h
   Defines MockDeckModel
   Written on 22/11/2021
   by Austin Ball
   CPSC3720
*/
#ifndef MOCKDECKMODEL_H
#define MOCKDECKMODEL_H

#include "DeckModel.h"
#include <vector>
#include <stack>

using std::vector;
using std::stack;

class MockDeckModel : public DeckModel {
 public:
    MOCK_METHOD(void, shuffleDeck, (), (override));
    MOCK_METHOD(CardModel*, getTopCard, (), (override));
    MOCK_METHOD(vector<CardModel*>, buildDeck, (), (override));
    MOCK_METHOD(vector<CardModel*>, getGarbage, (), (override));
    MOCK_METHOD(void, removeCardsDup, (int), (override));
    MOCK_METHOD(int, getsize, (), (override));
    MOCK_METHOD(CardModel*, getFirstCard, (), (override));
    MOCK_METHOD(void, addGarbageToDeck, (), (override));
    MOCK_METHOD(void, checksize, (), (override));
    MOCK_METHOD(void, addBuildToGarbage, (stack<CardModel*>), ());
};
#endif
