/**
   test_handModel
   Tests HandModel Class
   Written by Muhammad Saleh
   on 11/11/2021
   CPSC3720
*/

#include "HandModel.h"
#include "CardModel.h"
#include <vector>
#include "gtest/gtest.h"

class HandModelTest : public testing::Test {
 protected:
    HandModel* h;
    CardModel* c1;
    CardModel* c2;
    CardModel* c3;
    void SetUp() override {
        h = new HandModel();
        c1 = new CardModel(1);
        c2 = new CardModel(2);
        c3 = new CardModel(3);
    }
    void TearDown() override {
        delete h;
        delete c1;
        delete c2;
        delete c3;
        h = NULL;
        c1 = NULL;
        c2 = NULL;
        c3 = NULL;
    }
};

TEST_F(HandModelTest, test_Constructor) {
  ASSERT_TRUE(h->getNumberOfCards() == 0);
  ASSERT_TRUE(h->GetHand().size() == 0);
}

TEST_F(HandModelTest, test_GetHand) {
  ASSERT_TRUE(h->GetHand().size() == 0);
  h->addCard(c1);
  ASSERT_TRUE(h->GetHand().size() == 1);
  h->removeCard(0);
  ASSERT_TRUE(h->GetHand().size() == 0);
}

TEST_F(HandModelTest, test_addCard) {
  ASSERT_TRUE(h->getNumberOfCards() == 0);
  h->addCard(c1);
  ASSERT_TRUE(h->getNumberOfCards() == 1);
  h->addCard(c2);
  ASSERT_TRUE(h->getNumberOfCards() == 2);
  h->addCard(c3);
  ASSERT_TRUE(h->getNumberOfCards() == 3);
  h->removeCard(0);
  h->removeCard(0);
  h->removeCard(0);
  ASSERT_TRUE(h->getNumberOfCards() == 0);
}

TEST_F(HandModelTest, test_removeCard) {
  ASSERT_TRUE(h->getNumberOfCards() == 0);
  h->addCard(c1);
  h->addCard(c2);
  h->addCard(c3);
  ASSERT_TRUE(h->getNumberOfCards() == 3);
  h->removeCard(2);
  ASSERT_TRUE(h->getNumberOfCards() == 2);
  h->removeCard(1);
  ASSERT_TRUE(h->getNumberOfCards() == 1);
  h->removeCard(0);
  ASSERT_TRUE(h->getNumberOfCards() == 0);
}

TEST_F(HandModelTest, test_getNumberOfCards) {
  ASSERT_TRUE(h->getNumberOfCards() == 0);
  h->addCard(c1);
  ASSERT_TRUE(h->getNumberOfCards() == 1);
  h->addCard(c2);
  ASSERT_TRUE(h->getNumberOfCards() == 2);
  h->addCard(c3);
  ASSERT_TRUE(h->getNumberOfCards() == 3);
  h->removeCard(1);
  ASSERT_TRUE(h->getNumberOfCards() == 2);
  h->removeCard(0);
  ASSERT_TRUE(h->getNumberOfCards() == 1);
  h->removeCard(0);
  ASSERT_TRUE(h->getNumberOfCards() == 0);
}

TEST_F(HandModelTest, test_useCard) {
  ASSERT_TRUE(h->getNumberOfCards() == 0);
  h->addCard(c1);
  h->addCard(c2);
  h->addCard(c3);
  ASSERT_TRUE(h->useCard(0) == c1);
  ASSERT_TRUE(h->useCard(1) == c2);
  ASSERT_TRUE(h->useCard(2) == c3);
  h->removeCard(0);
  h->removeCard(0);
  h->removeCard(0);
}
