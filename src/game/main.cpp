/**
* ~~Dummy main to please the makefile :)~~
* The main program to run the card games.
*/

#include "DisplayView.h"
#include "CardModel.h"
#include "HandView.h"
#include "HandModel.h"
#include "PileModel.h"
#include "ArrPileModel.h"
#include "arrPileView.h"
#include "DeckModel.h"
#include "Player.h"
#include "cardGameController.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stack>

int main() {
    // Player* p1 = new Player;
    // Player* p2 = new Player;
    // DeckModel* deck = new DeckModel;
    // ArrPileModel* building = new ArrPileModel;
    CardGameController a(new InputView(), new Player(), new Player(),
                         new DeckModel(), new ArrPileModel());
    a.gameStart();
    char c;
    std::cin >> c;

    return 0;
}
