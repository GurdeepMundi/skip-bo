#include "DeckModel.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <stack>

DeckModel::DeckModel() {}
DeckModel::~DeckModel() {
  for (CardModel* c : currentDeck)
    delete c;
}

void DeckModel::shuffleDeck() {
  int n = currentDeck.size();
  for (int i = 0; i < n; i++) {
    srand(time(NULL));
    int r = i + (std::rand() % (n - i));
    CardModel* temp = currentDeck[r];
    currentDeck[r] = currentDeck[i];
    currentDeck[i] = temp;
  }
}

CardModel* DeckModel::getTopCard() {
  CardModel* temp = currentDeck[0];
  currentDeck.erase(currentDeck.begin());
  return temp;
}

std::vector<CardModel*> DeckModel::buildDeck() {
  std::vector<CardModel*> d;
  for (int i=1; i < 13; i++) {
    for (int j=1; j < 13; j++) {
      d.push_back(new CardModel(i));
    }
  }
  for (int i=0; i < 18; i++) {
    d.push_back(new CardModel(0));
  }
  currentDeck = d;
  return d;
}

std::vector<CardModel*> DeckModel::getDeck() {
  return currentDeck;
}

void DeckModel::removeCardsDup(int num) {
  for (int i = 0; i < num; i++) {
    currentDeck.erase(currentDeck.begin());
  }
}

int DeckModel::getsize() {
  return currentDeck.size();
}
CardModel* DeckModel::getFirstCard() {
  return currentDeck[0];
}
void DeckModel::addGarbageToDeck() {
  for (int i = 0; i < garbage.size(); i++) {
    currentDeck.push_back(garbage[i]);
  }
  garbage.clear();
}

void DeckModel::checkSize() {
  if (getsize() < 10) {
    addGarbageToDeck();
    shuffleDeck();
  }
}

void DeckModel::addBuildToGarbage(std::stack<CardModel*> p) {
  for (int i = 0; i < p.size(); i++) {
    garbage.push_back(p.top());
    p.pop();
  }
}
