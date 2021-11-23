/**
   MockArrPileModel.h
   Defines MockArrPileModel
   Written on 22/11/2021
   by Muhammad Saleh
   CPSC3720
*/

#ifndef MOCKARRPILEMODEL_H
#define MOCKARRPILEMODEL_H

#include "ArrPileModel.h"
#include "CardModel.h"
#include "PileModel.h"
#include "DeckModel.h"
#include <vector>

class MockArrPileModel : public ArrPileModel {
 public:
  explicit MockArrPileModel() {}
  virtual ~MockArrPileModel() {}

  MOCK_METHOD1(getPile, PileModel*(int), (override));
  MOCK_METHOD0(buildPileArr, std::vector<PileModel*>(), (override));
  MOCK_METHOD2(insertCard, bool(CardModel*, int), (override));
  MOCK_METHOD1(usediscard, CardModel*(int), (override));
  MOCK_METHOD1(popTopcard, void(int), (override));
  MOCK_METHOD2(putCardInDiscard, void(CardModel*, int), (override));
  MOCK_METHOD1(checkBuildSize, void(DeckModel*), (override));
  MOCK_METHOD1(clearPile, void(int), (override));
};
#endif
