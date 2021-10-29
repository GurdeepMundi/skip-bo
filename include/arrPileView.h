/**
* @author Cody Hodge <@hodc3720>
* @author Brent Hawkings <@hawb3720>
* @author Julie Wojtiw-Quo <@wojj3720>
* @date 2021-10
*/
//Definitions
#ifndef ARRPILEVIEW_H_INCLUDED
#define ARRPILEVIEW_H_INCLUDED

#include "DisplayView.h"
#include "PileModel.h"
#include "ArrPileModel.h"

/**
* arrPileView Class Child Of DisplayView, view class for displaying arrPiles
*/
class arrPileView : public DisplayView {
 public:
    /**
    * Default Constructor
    */
    arrPileView();

    /**
    * Displays an array of piles
    * @param arrPileModel& object, which holds a vector of pilemodel pointers
    * @param int pileType the number of the pile to be displayed
    */
    void DisplayarrPileView(ArrPileModel* pileArray, int pileType);
};
#endif
