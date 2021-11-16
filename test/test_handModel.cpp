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
    void SetUp() override {
        h = new HandModel();
    }
    void TearDown() override {
        delete h;
        h = NULL;
    }
};

TEST_F(HandModelTest, test_Constructor) {
  ASSERT_TRUE(h->getNumberOfCards() == 0);
  ASSERT_TRUE(h->GetHand().size() == 0);
}

TEST_F(HandModelTest, test_GetHand) {
  ASSERT_TRUE(h->GetHand().size() == 0);
  CardModel* c;
  c = new Cardmodel(5);
  h->addCard(c);
  ASSERT_TRUE(h->GetHand().size() == 1);
  h->removeCard(1);
  ASSERT_TRUE(h->GetHand().size() == 0);
  delete c;
  c = NULL;
}

TEST_F(HandModelTest, test_addCard) {

}

TEST_F(HandModelTest, test_removeCard) {

}

TEST_F(HandModelTest, test_getNumberOfCards) {

}

TEST_F(HandModelTest, test_useCard) {

}
