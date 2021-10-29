#include "ArrPileModel.h"
#include "CardModel.h"
#include "PileModel.h"
#include "DeckModel.h"
#include <stack>
#include <iostream>
#include <vector>

ArrPileModel::ArrPileModel() {
  for (int i = 0; i < 4; i++) {
    piles.push_back(new PileModel);
  }
}

ArrPileModel::~ArrPileModel() {}

PileModel* ArrPileModel::getPile(int pileNum) {
  return piles[pileNum];
}

std::vector<PileModel*> ArrPileModel::buildPileArr() {
  std::vector<PileModel*> p(4, new PileModel());
  return p;
}

bool ArrPileModel::insertCard(CardModel* card, int num) {
  num = num - 1;
  if ((piles[num]->getTopNum() + 1) == card->getNumber()) {
    piles[num]->addCard(card);
    return true;
  } else if (card->getNumber() == 0) {
    card->setNumber(piles[num]->getTopNum() + 1);
    piles[num]->addCard(card);
    return true;
  } else {
    std::cout << "pick a card that works" << std::endl;
  }
  return false;
}

CardModel* ArrPileModel::usediscard(int num) {
  CardModel* c = new CardModel(20);
  if (piles[num]->getNumberOfCards() == 0) {
    std::cout << "there is no card in discard pile " << num << std::endl;
    return c;
  } else {
    return piles[num]->getTopCard();
    popTopcard(num);
  }
}

void ArrPileModel::popTopcard(int num) {
  piles[num]->removeCard();
}

void ArrPileModel::putCardInDiscard(CardModel* card, int num) {
    piles[num]->addCard(card);
}

void ArrPileModel::checkBuildSize(DeckModel* deck) {
  PileModel* p = new PileModel;
  std::stack<CardModel*> b;
  for (int i = 0; i < 4; i++) {
    p = getPile(i);
    if (p->getSize() >= 12) {
      b = p->getPile();
      deck->addBuildToGarbage(b);
      clearPile(i);
    }
  }
}

void ArrPileModel::clearPile(int num) {
  piles[num]->clearPile();
}
