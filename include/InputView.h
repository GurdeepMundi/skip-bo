/**
* @author Dr. Anvik
* @date 2021-10
*/
#ifndef INPUTVIEW_H_INCLUDED
#define INPUTVIEW_H_INCLUDED

#include "DisplayView.h"
#include "CardModel.h"

/**
* Class to handle input from user
*/
class InputView {
 public:
    /**
    * Default Constructor
    */
    InputView() {}

    /**
    * Choose card to discard
    */
    unsigned int discardChoice(unsigned int);

    /**
    * Choose a discard pile
    */
    unsigned int discardPile();

    /**
    * Prompt to exit the game
    */
    void exitGame();

    /**
    * Prompt for play option
    */
    unsigned int options(unsigned int handSize);

    /**
    * Prompt for card to play from hand
    */
    unsigned int selectBuildPile();
};
#endif
