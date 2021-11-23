/**
   mockTest_cardGameController
   Mock tests cardGameController using MockPlayer, MockDeckModel,
   MockArrPile.
   Written on 19/11/2021
   by Austin Ball
   CPSC3720
*/

//#include "MockCardGameController.h"
//#include "MockPlayer.h"
#include "MockDeckModel.h"
#include "Player.h"
#include "DeckModel.h"
#include "ArrPileModel.h"
#include "HandModel.h"
#include "PileModel.h"
#include "CardModel.h"
#include "cardGameController.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Expectation;
using ::testing::AtLeast;

class GameControllerTest : public testing::Test {
 protected:
    InputView* iv;
    Player* p1;
    Player* p2;
    DeckModel* d;
    ArrPileModel* arr;
    void SetUp() override {
        iv = new InputView();
        p1 = new Player("User");
        p2 = new Player("AI");
        d = new DeckModel();
        arr = new ArrPileModel();
    }
    void TearDown() override {
        delete iv, p1, p2, d, arr;
    }
};

/*TEST_F(GameControllerTest, constructorTest) {
  EXPECT_NO_THROW(CardModelController myGame(iv, p1, p2, d, arr));
}*/

TEST(GameControllerTest, DISABLED_gameStart) {
    //MockPlayer* p1;
    //MockPlayer* p2;// Mock Players
    MockDeckModel d;// Mock Deck
//    MockArrPileModel b;// Mock Build Piles
//    Expectation deckBuilt =
    EXPECT_CALL(d, buildDeck()).Times(AtLeast(1));
//    Expectation deckShuffled =
    EXPECT_CALL(d, shuffleDeck()).Times(AtLeast(1));
//    Expectation p1GetsCards =
    //EXPECT_CALL(p1, addToStock()).Times(AtLeast(1));
//    Expectation p2GetsCards =
    //EXPECT_CALL(p2, addToStock()).Times(AtLeast(1));

    CardGameController cont(new InputView(), new Player(), new Player(), &d,
     new ArrPileModel());
    cont.gameStart();
}
