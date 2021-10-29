/**
* @author Cody Hodge <@hodc3720>
* @author Brent Hawkings <@hawb3720>
* @author Julie Wojtiw-Quo <@wojj3720>
* @date 2021-10
*/
//Definitions
#ifndef STOCKVIEW_H_INCLUDED
#define STOCKVIEW_H_INCLUDED
//include headers
#include "DisplayView.h"
#include "PileModel.h"

/**
* StockView Class Child Of DisplayView
*/
class StockView : public DisplayView {
 public:
    /**
    * Default Constructor
    */
    StockView();

    /**
    * Displays a stock pile
    * @param PileModel* object, the pile to display
    */
    void DisplayStock(PileModel* pile);
};
#endif
