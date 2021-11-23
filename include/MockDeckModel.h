/**
   MockDeckModel.h
   Defines MockDeckModel
   Written on 22/11/2021
   by Austin Ball, Gurdeep Singh
   CPSC3720
*/
#ifndef MOCKDECKMODEL_H
#define MOCKDECKMODEL_H

#include <DeckModel.h>
#include <CardModel.h>
#include <vector>
#include <stack>

using std::vector;
using std::stack;

class MockDeckModel : public DeckModel {
 public:
    MOCK_METHOD0(shuffleDeck, void());
    MOCK_METHOD0(getTopCard, CardModel*());
    MOCK_METHOD0(buildDeck, std::vector<CardModel*>());
    MOCK_METHOD0(getDeck, std::vector<CardModel*>());
    MOCK_METHOD0(getGarbage, std::vector<CardModel*>());
    MOCK_METHOD1(removeCardsDup, void(int));
    MOCK_METHOD0(getsize, int());
    MOCK_METHOD0(getFirstCard, CardModel*());
    MOCK_METHOD0(addGarbageToDeck, void());
    MOCK_METHOD0(checkSize, void());
    MOCK_METHOD0(addBuildToGarbage, void(std::stack<CardModel*>));
};
#endif
