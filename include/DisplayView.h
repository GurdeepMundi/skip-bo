/**
* @author Cody Hodge <hodc3720>
* @author Brent Hawkings <hawb3720>
* @author Julie Wojtiw-Quo <wojj3720>
* @date 2021-10
*/
#ifndef DISPLAYVIEW_H_INCLUDED
#define DISPLAYVIEW_H_INCLUDED

#include <string>
#include "CardModel.h"

/**
* Display Objects Parent Class
*/
class DisplayView {
 public:
    /**
    * Default Constructor
    */
    DisplayView();

    /**
    * Displays the value of a card
    * @param cardModel object, the card to display
    */
    void DisplayCard(CardModel*);

    /**
    * Displays the top of a card
    * @param cardModel object, adjusts width of top based on size of number on card
    */
    void DisplayTop(CardModel*);

    /**
    * Displays the side of a card
    */
    void DisplaySide();

    /**
    * Displays the bottom of a card
    * @param cardModel object, adjusts width of bottom based on size of number on card
    */
    void DisplayBottom(CardModel*);
};
#endif
