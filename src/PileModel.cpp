#include "PileModel.h"
#include "CardModel.h"
#include <stack>

PileModel::PileModel() {}

PileModel::~PileModel() {
  while (!currentPile.empty()) {
     CardModel* c = currentPile.top();
     currentPile.pop();
     delete c;
  }
}

CardModel* PileModel::getTopCard() {
  return currentPile.top();
}

int PileModel::getTopNum() {
  if (currentPile.size() == 0) {
      return 0;
  } else {
      return getTopCard()->getNumber();
  }
}

void PileModel::addCard(CardModel* c) {
  currentPile.push(c);
  numberOfCards++;
}

void PileModel::removeCard() {
  currentPile.pop();
  numberOfCards--;
}

int PileModel::getNumberOfCards() {
  return currentPile.size();
}

int PileModel::getSize() {
  return currentPile.size();
}

std::stack<CardModel*> PileModel::getPile() {
  return currentPile;
}

void PileModel::clearPile() {
  while (!currentPile.empty()) {
    currentPile.pop();
  }
}
