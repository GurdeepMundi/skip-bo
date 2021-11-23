/*

*/
#ifndef MOCKARRPILEMODEL_H
#define MOCKARRPILEMODEL_H

#include "ArrPileModel.h"
#include <vector>

class MockArrPileModel : public ArrPileModel {
 public:
  MOCK_METHOD(PileModel*, getPile, (), (overide));
  MOCK_METHOD(std::vector<PileModel*>, buildPileArr, (), (overide));
  MOCK_METHOD(bool, insertCard, (CardModel*, int), (overide));
  MOCK_METHOD(CardModel*, usediscard, (int), (overide));
  MOCK_METHOD(void, popTopcard, (int), (overide));
  MOCK_METHOD(void, putCardInDiscard, (CardModel*, int), (overide));
  MOCK_METHOD(void, checkbuildSize, (DeckModel*), (overide));
  MOCK_METHOD(void, clearPile, (int), (overide));
}

#endif //MOCKARRPILEMODEL_H
