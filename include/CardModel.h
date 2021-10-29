/**
* @author Cody Hodge <@hodc3720>
* @author Brent Hawkings <@hawb3720>
* @author Julie Wojtiw-Quo <@wojj3720>
* @date 2021-10
*/
#ifndef CARDMODEL_H
#define CARDMODEL_H

/**
* Maintains each card for the game
*/
class CardModel {
 public:
    /**
    * A card (Constructor)
    */
    CardModel(int); //CardModel(int, char, bool);

    /**
    * Destructor
    */
    ~CardModel();

    /**
    * Sets the number of a card
    * @param integer value on the card
    * @return an integer
    */
    void setNumber(int);

    /**
    * Gets the card number
    * @return an integer, the card number.
    */
    int getNumber();

    /**
    * Checks if card is Skip-Bo card (int == 0)
    * @return a boolean, true if skip-bo, false if not
    */
    bool isSkipBo(CardModel);


 private:
    //bool skipbo;
    int number;
};
#endif
