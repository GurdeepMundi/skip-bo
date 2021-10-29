#include <iostream>
#include <string>
#include "HandView.h"
#include "HandModel.h"

HandView::HandView() {}

//displays a hand by printing tops of
//cards then the left side, value, and right side,
//then the bottom, then the input number for each card to play
//loops through hand to find its length for each step
void HandView::DisplayHand(HandModel* h) {
    //gets number of cards in hand to display
    int num = h->getNumberOfCards();
    //displays top
    for (int i = 0; i < num; i++) {
        DisplayTop(h->GetHand()[i]);
        std::cout << " ";
    }
    std::cout << std::endl;
    //displays left side, value, and right side
    for (int i = 0; i < num; i++) {
        DisplaySide();
        DisplayCard(h->GetHand()[i]);
        DisplaySide();
        std::cout << " ";
    }
    std::cout << std::endl;
    //displays the bottom
    for (int i = 0; i < num; i++) {
        DisplayBottom(h->GetHand()[i]);
        std::cout << " ";
    }
    std::cout << std::endl;
    //displays the input number for each card to play
    for (int i = 0; i < num; i++) {
        int index = i + 1;
        std::cout << " " << index << "  ";
    }
    std::cout << std::endl;
}
