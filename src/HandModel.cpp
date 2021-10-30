#include "HandModel.h"
#include "CardModel.h"
#include <vector>

HandModel::HandModel() {
  numberOfCards = 0;
}

HandModel::~HandModel() {
  for (CardModel* c : gameHand)
    delete c;
}

std::vector<CardModel*> HandModel::GetHand() {
  return gameHand;
}

void HandModel::addCard(CardModel* c) {
  gameHand.push_back(c);
  numberOfCards++;
}

void HandModel::removeCard(int cardNumber) {
  gameHand.erase(gameHand.begin() + cardNumber);
  numberOfCards--;
}

int HandModel::getNumberOfCards() {
  return numberOfCards;
}

CardModel* HandModel::useCard(int num) {
  return gameHand[num];
}
