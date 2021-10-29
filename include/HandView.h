/**
* @author Cody Hodge <@hodc3720>
* @author Brent Hawkings <@hawb3720>
* @author Julie Wojtiw-Quo <@wojj3720>
* @date 2021-10
*/
#ifndef HANDVIEW_H_INCLUDED
#define HANDVIEW_H_INCLUDED

#include "DisplayView.h"
#include "HandModel.h"

/**
* HandView Class Child Of DisplayView
*/
class HandView : public DisplayView {
 public:
    /**
    * Default Constructor
    */
    HandView();

    /**
    * Displays a hand
    * @param cardModel object
    */
    void DisplayHand(HandModel* h);
};
#endif
