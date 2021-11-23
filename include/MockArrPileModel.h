/**
   MockArrPileModel.h
   Defines MockArrPileModel
   Written on 22/11/2021
   by Muhammad Saleh
   CPSC3720
*/

#ifndef MOCKARRPILEMODEL_H
#define MOCKARRPILEMODEL_H

#include "CardModel.h"
#include "PileModel.h"
#include "DeckModel.h"
#include <vector>

class MockArrPileModel : public ArrPileModel {
 public:
  MOCK_METHOD(PileModel*, getPile, (int), (override));
  MOCK_METHOD(std::vector<PileModel*>, buildPileArr, (), (override));
  MOCK_METHOD(bool, insertCard, (CardModel*, int), (override));
  MOCK_METHOD(CardModel*, usediscard, (int), (override));
  MOCK_METHOD(void, popTopcard, (int), (override));
  MOCK_METHOD(void, putCardInDiscard, (CardModel*, int), (override));
  MOCK_METHOD(void, checkBuildSize, (DeckModel*), (override));
  MOCK_METHOD(void, clearPile, (int), (override));
};
#endif
