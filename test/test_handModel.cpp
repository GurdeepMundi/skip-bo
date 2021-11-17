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
  EXPECT_EQ(h->getNumberOfCards(), 0);
  EXPECT_EQ(h->GetHand().size(), 0);
}

TEST_F(HandModelTest, test_GetHand) {
  EXPECT_EQ(h->GetHand().size(), 0);
  h->addCard(c1);
  EXPECT_EQ(h->GetHand().size(), 1);
  h->removeCard(0);
  EXPECT_EQ(h->GetHand().size(), 0);
}

TEST_F(HandModelTest, test_addCard) {
  EXPECT_EQ(h->getNumberOfCards(), 0);
  h->addCard(c1);
  EXPECT_EQ(h->getNumberOfCards(), 1);
  h->addCard(c2);
  EXPECT_EQ(h->getNumberOfCards(), 2);
  h->addCard(c3);
  EXPECT_EQ(h->getNumberOfCards(), 3);
  h->removeCard(0);
  h->removeCard(0);
  h->removeCard(0);
  EXPECT_EQ(h->getNumberOfCards(), 0);
}

TEST_F(HandModelTest, test_removeCard) {
  EXPECT_EQ(h->getNumberOfCards(), 0);
  h->addCard(c1);
  h->addCard(c2);
  h->addCard(c3);
  EXPECT_EQ(h->getNumberOfCards(), 3);
  h->removeCard(2);
  EXPECT_EQ(h->getNumberOfCards(), 2);
  h->removeCard(1);
  EXPECT_EQ(h->getNumberOfCards(), 1);
  h->removeCard(0);
  EXPECT_EQ(h->getNumberOfCards(), 0);
}

TEST_F(HandModelTest, test_getNumberOfCards) {
  EXPECT_EQ(h->getNumberOfCards(), 0);
  h->addCard(c1);
  EXPECT_EQ(h->getNumberOfCards(), 1);
  h->addCard(c2);
  EXPECT_EQ(h->getNumberOfCards(), 2);
  h->addCard(c3);
  EXPECT_EQ(h->getNumberOfCards(), 3);
  h->removeCard(1);
  EXPECT_EQ(h->getNumberOfCards(), 2);
  h->removeCard(0);
  EXPECT_EQ(h->getNumberOfCards(), 1);
  h->removeCard(0);
  EXPECT_EQ(h->getNumberOfCards(), 0);
}

TEST_F(HandModelTest, test_useCard) {
  EXPECT_EQ(h->getNumberOfCards(), 0);
  h->addCard(c1);
  h->addCard(c2);
  h->addCard(c3);
  EXPECT_EQ(h->useCard(0), c1);
  EXPECT_EQ(h->useCard(1), c2);
  EXPECT_EQ(h->useCard(2), c3);
  h->removeCard(0);
  h->removeCard(0);
  h->removeCard(0);
}
