#include "CardModel.h"

CardModel::CardModel(int n) {
    number = n;
}

CardModel::~CardModel() {}

void CardModel::setNumber(int n) {
  number = n;
}

int CardModel::getNumber() {
    return number;
}

bool CardModel::isSkipBo(CardModel c) {
    if (c.number == 0) {
      return true;
    }
    return false;
}
