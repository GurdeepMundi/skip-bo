#include "HandModel.h"
#include "CardModel.h"
#include <vector>

HandModel::HandModel() {
  numberOfCards = 0;
}

HandModel::~HandModel() {}

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
  CardModel* c = new CardModel (0);
  c = gameHand[num];
  return c;
}
