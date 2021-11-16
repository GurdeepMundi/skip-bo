/**
   test_handModel
   Tests HandModel Class
   Written by Austin Ball
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
    CardModel* c;
    void SetUp() override {
        h = new HandModel();
        c = new CardModel(1);
    }
    void TearDown() override {
        delete h;
        delete c;
        h = NULL;
        c = NULL;
    }
};

TEST_F(HandModelTest, test_Constructor) {
  ASSERT_TRUE(h->getNumberOfCards() == 0);
  ASSERT_TRUE(h->GetHand().size() == 0);
}

TEST_F(HandModelTest, test_GetHand) {
  ASSERT_TRUE(h->GetHand().size() == 0);
  h->addCard(c);
  ASSERT_TRUE(h->GetHand().size() == 1);
  h->removeCard(0);
  ASSERT_TRUE(h->GetHand().size() == 0);
}

TEST_F(HandModelTest, test_addCard) {
  ASSERT_TRUE(h->getNumberOfCards() == 0);
  h->addCard(c);
  ASSERT_TRUE(h->getNumberOfCards() == 1);
  h->addCard(c);
  ASSERT_TRUE(h->getNumberOfCards() == 2);
  h->addCard(c);
  ASSERT_TRUE(h->getNumberOfCards() == 3);
}

TEST_F(HandModelTest, test_removeCard) {
  ASSERT_TRUE(h->getNumberOfCards() == 0);
  h->addCard(c);
  h->addCard(c);
  h->addCard(c);
  ASSERT_TRUE(h->getNumberOfCards() == 3);
  h->removeCard(3);
  ASSERT_TRUE(h->getNumberOfCards() == 2);
  h->removeCard(2);
  ASSERT_TRUE(h->getNumberOfCards() == 1);
  h->removeCard(1);
  ASSERT_TRUE(h->getNumberOfCards() == 0);
}

TEST_F(HandModelTest, test_getNumberOfCards) {

}

TEST_F(HandModelTest, test_useCard) {

}
