#include <iostream>
#include <string>
//include headers
#include "StockView.h"
#include "CardModel.h"
#include "PileModel.h"

StockView::StockView() {}

//displays the top of the stock card pile and
//the number of cards remaining in the pile
void StockView::DisplayStock(PileModel* pile) {
    CardModel* card = pile->getTopCard();
    DisplayTop(card);
    std::cout << "    Cards Remaining:";
    std::cout << std::endl;
    DisplaySide();
    DisplayCard(card);
    DisplaySide();
    std::cout << "    ";
    std::cout << pile->getSize();
    std::cout << std::endl;
    DisplayBottom(card);
    std::cout << std::endl;
}
