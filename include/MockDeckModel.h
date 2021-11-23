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
   explicit MockDeckModel();
   virtual ~MockDeckModel();

    MOCK_METHOD0(shuffleDeck, void(), (override));
    MOCK_METHOD0(getTopCard, CardModel*(), (override));
    MOCK_METHOD0(buildDeck, vector<CardModel*>(), (override));
    MOCK_METHOD0(getGarbage, vector<CardModel*>(), (override));
    MOCK_METHOD1(removeCardsDup, void(int), (override));
    MOCK_METHOD0(getsize, int(), (override));
    MOCK_METHOD0(getFirstCard, CardModel*(), (override));
    MOCK_METHOD0(addGarbageToDeck, void(), (override));
    MOCK_METHOD0(checksize, void(), (override));
    MOCK_METHOD1(addBuildToGarbage, void(stack<CardModel*>), ());
};
#endif
