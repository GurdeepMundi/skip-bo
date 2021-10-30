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

#include "cardGameController.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <stack>

int main() {
    CardGameController a(new InputView());
    a.gameStart();
    char c;
    std::cin >> c;

    return 0;
}
