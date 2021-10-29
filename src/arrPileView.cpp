#include <iostream>
#include <string>
//include headers
#include "arrPileView.h"
#include "PileModel.h"
#include "CardModel.h"
#include "ArrPileModel.h"
#include <vector>
#include <stack>

arrPileView::arrPileView() {}

//If pileType is 0 then the ArrPile is the players discard piles
//If pileType is 1 then the ArrPile is the build piles
//If pileType is 2 then the ArrPile is the opponents discard piles
void arrPileView::DisplayarrPileView(ArrPileModel* pileArray, int pileType) {
    //top card temp storage
    CardModel* topOfPile1;
    CardModel* topOfPile2;
    CardModel* topOfPile3;
    CardModel* topOfPile4;
    //are the piles started?
    bool isPile1 = false;
    bool isPile2 = false;
    bool isPile3 = false;
    bool isPile4 = false;

    //logic to assign cards to top card temp storage
    //and detect if piles are started
    if (pileArray->getPile(0)->getNumberOfCards() > 0) {
        PileModel* p1 = pileArray->getPile(0);
        topOfPile1 = p1->getTopCard();
        isPile1 = true;
    }
    if (pileArray->getPile(1)->getNumberOfCards() > 0) {
        PileModel* p2 = pileArray->getPile(1);
        topOfPile2 = p2->getTopCard();
        isPile2 = true;
    }
    if (pileArray->getPile(2)->getNumberOfCards() > 0) {
        PileModel* p3 = pileArray->getPile(2);
        topOfPile3 = p3->getTopCard();
        isPile3 = true;
    }
    if (pileArray->getPile(3)->getNumberOfCards() > 0) {
        PileModel* p4 = pileArray->getPile(3);
        topOfPile4 = p4->getTopCard();
        isPile4 = true;
    }

    //logic to display piles
    //top row of piles
    if (isPile1) {
        std::cout << " ";
        DisplayTop(topOfPile1);
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    if (isPile2) {
        std::cout << " ";
        DisplayTop(topOfPile2);
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    if (isPile3) {
        std::cout << " ";
        DisplayTop(topOfPile3);
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    if (isPile4) {
        std::cout << " ";
        DisplayTop(topOfPile4);
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    std::cout << std::endl;

    //middle row of piles, contains card values
    if (isPile1) {
        std::cout << " ";
        DisplaySide();
        DisplayCard(topOfPile1);
        DisplaySide();
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    if (isPile2) {
        std::cout << " ";
        DisplaySide();
        DisplayCard(topOfPile2);
        DisplaySide();
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    if (isPile3) {
        std::cout << " ";
        DisplaySide();
        DisplayCard(topOfPile3);
        DisplaySide();
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    if (isPile4) {
        std::cout << " ";
        DisplaySide();
        DisplayCard(topOfPile4);
        DisplaySide();
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    std::cout << std::endl;

    //bottom row of piles
    if (isPile1) {
        std::cout << " ";
        DisplayBottom(topOfPile1);
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    if (isPile2) {
        std::cout << " ";
        DisplayBottom(topOfPile2);
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    if (isPile3) {
        std::cout << " ";
        DisplayBottom(topOfPile3);
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    if (isPile4) {
        std::cout << " ";
        DisplayBottom(topOfPile4);
        std::cout << "  ";
    } else {
        std::cout << "|   | ";
    }
    std::cout << std::endl;
    //If pileType is 0 then the ArrPile is the players discard piles
    //If pileType is 1 then the ArrPile is the build piles
    //If pileType is 2 then the ArrPile is the opponents discard piles
    if (pileType == 0) {
        std::cout << " " << " 6 " << "   " << " 7 "
        << "   " << " 8 " << "   " << " 9 ";
    } else if (pileType == 1) {
        std::cout << " " << " 1 " << "   " << " 2 "
        << "   " << " 3 " << "   " << " 4 ";
    }
    std::cout << std::endl;
}
