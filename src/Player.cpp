#include "Player.h"
#include "CardModel.h"
#include "DisplayView.h"
#include "ArrPileModel.h"
#include "HandView.h"
#include "StockView.h"
#include "arrPileView.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
//#include "Exceptions.h"

Player::Player(std::string name) : name{name} {}

Player::~Player() {}

std::string Player::getName() {
  return name;
}

void Player::setComputerPlayer() {
  this->computer = true;
}

bool Player::isComputerPlayer() {
  return this->computer;
}

void Player::addToStock(DeckModel* deck) {
  for (int i = 0; i < 30; i++) {
    stock->addCard(deck->getFirstCard());
    deck->removeCardsDup(1);
  }
}

unsigned int Player::handsize() {
  return hand->getNumberOfCards();
}

int Player::stocksize() {
  return stock->getNumberOfCards();
}

void Player::addCard(CardModel* c) {
  hand->addCard(c);
}

CardModel* Player::useCard(int num) {
  return hand->useCard(num);
}

CardModel* Player::usediscard(int num) {
  return discard->usediscard(num);
}

CardModel* Player::useStock() {
  return stock->getTopCard();
}

void Player::usingDiscard(CardModel* card, int num) {
  discard->putCardInDiscard(card, num);
}

void Player::removeCard(int num) {
    hand->removeCard(num);
}

void Player::deleteDiscardCard(int num) {
  discard->popTopcard(num);
}

void Player::deleteStockCard() {
  stock->removeCard();
}

void Player::displayHand() {
  HandView a;
  a.DisplayHand(returnHand());
}

HandModel* Player::returnHand() {
  return hand;
}

void Player::displayStock() {
  StockView a;
  std::cout << "\n Stock" << std::endl;
  a.DisplayStock(returnStock());
}

PileModel* Player::returnStock() {
  return stock;
}
//bool computer specifies whose discard pile is
//shown, false for the player, true for computer
void Player::displayDiscard(bool computer) {
  arrPileView a;
  //If pileType is 0 then the ArrPile is the players discard piles
//If pileType is 1 then the ArrPile is the build piles
//If pileType is 2 then the ArrPile is the opponents discard piles
    if (computer) {
        a.DisplayarrPileView(returnArrPile(), 2);
    } else {
        a.DisplayarrPileView(returnArrPile(), 0);
    }
}

ArrPileModel* Player::returnArrPile() {
  return discard;
}
