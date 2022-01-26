/**
   test_playerModel
   Tests Player class
   Written by Austin Ball, Gurdeep Singh
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

using std::vector;

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

TEST_F(PlayerTest, test_addToStock) {
    ASSERT_EQ(p1->stocksize(), 0);
    p1->addToStock(d);
    ASSERT_EQ(p1->stocksize(), 30);
}

TEST_F(PlayerTest, test_handsize) {
    ASSERT_EQ(p1->handsize(), 0);
}

TEST_F(PlayerTest, test_stocksize) {
    ASSERT_EQ(p1->stocksize(), 0);
}

TEST_F(PlayerTest, test_returnHand) {
    HandModel* h = p1->returnHand();
    ASSERT_EQ(h->getNumberOfCards(), p1->handsize());
    ASSERT_NE(p1->returnHand(), p2->returnHand());
}

TEST_F(PlayerTest, test_addCard) {
    CardModel* c = d->getTopCard();
    ASSERT_EQ(p1->returnHand()->getNumberOfCards(), 0);
    p1->addCard(c);
    ASSERT_EQ(p1->returnHand()->getNumberOfCards(), 1);
}

TEST_F(PlayerTest, test_removeCard) {
    p1->addCard(d->getTopCard());
    ASSERT_EQ(p1->returnHand()->getNumberOfCards(), 1);
    p1->removeCard(0);
    ASSERT_EQ(p1->returnHand()->getNumberOfCards(), 0);
}

TEST_F(PlayerTest, test_useCard) {
    p1->addCard(d->getTopCard());
    ASSERT_EQ(p1->handsize(), 1);
    CardModel* c = p1->useCard(0);
    ASSERT_EQ(c->getNumber(), 1);
}

TEST_F(PlayerTest, test_usingDiscard) {
    ASSERT_EQ(p1->returnArrPile()->getPile(0)->getSize(), 0);
    ASSERT_EQ(p1->returnArrPile()->getPile(0)->getSize(), 0);
    ASSERT_EQ(p1->returnArrPile()->getPile(0)->getSize(), 0);
    ASSERT_EQ(p1->returnArrPile()->getPile(0)->getSize(), 0);
    p1->usingDiscard(d->getTopCard(), 0);
    p1->usingDiscard(d->getTopCard(), 1);
    p1->usingDiscard(d->getTopCard(), 2);
    p1->usingDiscard(d->getTopCard(), 3);
    ASSERT_NE(p1->returnArrPile()->getPile(0)->getSize(), 0);
    ASSERT_NE(p1->returnArrPile()->getPile(0)->getSize(), 0);
    ASSERT_NE(p1->returnArrPile()->getPile(0)->getSize(), 0);
    ASSERT_NE(p1->returnArrPile()->getPile(0)->getSize(), 0);
}

TEST_F(PlayerTest, test_usediscard) {
    p1->usingDiscard(d->getTopCard(), 0);
    ASSERT_EQ(p1->returnArrPile()->getPile(0)->getSize(), 1);
    CardModel* c = p1->usediscard(0);
    ASSERT_EQ(c->getNumber(), 1);
}

TEST_F(PlayerTest, test_deleteDiscardCard) {
    p1->usingDiscard(d->getTopCard(), 0);
    ASSERT_EQ(p1->returnArrPile()->getPile(0)->getSize(), 1);
    p1->deleteDiscardCard(0);
    ASSERT_EQ(p1->returnArrPile()->getPile(0)->getSize(), 0);
}

TEST_F(PlayerTest, test_useStock) {
    p1->addToStock(d);
    ASSERT_EQ(p1->stocksize(), 30);
    CardModel* c = p1->useStock();
    ASSERT_EQ(c->getNumber(), 3);
}

TEST_F(PlayerTest, test_deleteStockCard) {
    p1->addToStock(d);
    p1->deleteStockCard();
    ASSERT_EQ(p1->stocksize(), 29);
    p1->deleteStockCard();
    ASSERT_EQ(p1->stocksize(), 28);
}

TEST_F(PlayerTest, test_returnStock) {
    ASSERT_NE(p1->returnStock(), p2->returnStock());
    p1->addToStock(d);
    ASSERT_GT(p1->returnStock()->getNumberOfCards(),
              p2->returnStock()->getNumberOfCards());
}

TEST_F(PlayerTest, test_returnArrPile) {
    ASSERT_NE(p1->returnArrPile(), p2->returnArrPile());
    ArrPileModel* x = p1->returnArrPile();
    ArrPileModel* y = p2->returnArrPile();
    ASSERT_EQ(p1->returnArrPile(), x);
    ASSERT_EQ(p2->returnArrPile(), y);
}
