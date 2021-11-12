/**
   test_playerModel
   Tests Player class
   Written by Austin Ball
   on 12/11/2021
   CPSC3720
*/

#include "Player.h"
#include "ArrPileModel.h"
#include "DeckModel.h"
#include "HandModel.h"
#include "CardModel.h"
#include <cstddef>
#include <string>
#include <vector>
#include "gtest/gtest.h"

class PlayerTest : public testing::Test {
 protected:
    Player* p1;
    Player* p2;
    DeckModel* d;

  void SetUp() override {
      p1 = new Player();
      p2 = new Player("Llij");
      p2->setComputerPlayer();
      d = new DeckModel();
      d->buildDeck();
  }
    void TearDown() override {
        delete p1;
        p1 = NULL;
        delete p2;
        p2 = NULL;
        delete d;
        d = NULL;
  }
};

TEST_F(PlayerTest, test_constructor) {
    ASSERT_FALSE(p1->getName() == p2->getName());
}

TEST_F(PlayerTest, test_getName) {
    ASSERT_EQ(p1->getName(), "Jill");
}

TEST_F(PlayerTest, test_isComputerPlayer) {
    ASSERT_FALSE(p1->isComputerPlayer() == p2->isComputerPlayer());
}

TEST_F(PlayerTest, test_setComputerPlayer) {
    ASSERT_FALSE(p1->isComputerPlayer());
    p1->setComputerPlayer();
    ASSERT_TRUE(p1->isComputerPlayer());
}

/*TEST_F(PlayerTest, test_addToStock) {
    p1->addToStock(d);
    }*/
