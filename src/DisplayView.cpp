#include <iostream>
#include <string>
#include "DisplayView.h"
#include "CardModel.h"

DisplayView::DisplayView() {}

//displays the value of a card
void DisplayView::DisplayCard(CardModel* c) {
    if (c->getNumber() == 0) {
      std::cout << "S";
    } else {
        std::cout << c->getNumber();
    }
}

//displays the top of a card
//needs to make the card wider based on it's value
void DisplayView::DisplayTop(CardModel* c) {
    if (c->getNumber() >= 10) {
        std::cout << "/" << "-" << "-" << "\\";
    } else {
        std::cout << "/" << "-" << "\\";
    }
}

//displays the sides of the card
void DisplayView::DisplaySide() {
    std::cout << "|";
}

//displays the bottom of a card
//needs to make the card wider based on it's value
void DisplayView::DisplayBottom(CardModel* c) {
    if (c->getNumber() >= 10) {
        std::cout << "\\" << "__" << "/";
    } else {
        std::cout << "\\" << "_" << "/";
    }
}
