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
    MOCK_METHOD(shuffleDeck, void(), (override));
    MOCK_METHOD(getTopCard, CardModel*(), (override));
    MOCK_METHOD(buildDeck, vector<CardModel*>(), (override));
    MOCK_METHOD(getGarbage, vector<CardModel*>(), (override));
    MOCK_METHOD1(removeCardsDup, void(int), (override));
    MOCK_METHOD(getsize, int(), (override));
    MOCK_METHOD(getFirstCard, CardModel*(), (override));
    MOCK_METHOD(addGarbageToDeck, void(), (override));
    MOCK_METHOD(checksize, void(), (override));
    MOCK_METHOD1(addBuildToGarbage, void(stack<CardModel*>), ());
};
#endif
