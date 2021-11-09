/**
   test_cardModel.cpp
   Tests cardModel class
   Written by Austin Ball
   on 05/11/2021
   CPSC3720
*/

#include "CardModel.h"
#include "gtest/gtest.h"

class CardModelTest : public testing::Test {
 protected:
  CardModel* c;
  void SetUp() override {
    c = new CardModel(1);
  }
  void TearDown() {
    delete c;
  }
};

TEST_F(CardModelTest, test_setNumber) {
  int testInt = 2;
  c->setNumber(testInt);
  ASSERT_TRUE(c->getNumber() == testInt);
  ASSERT_FALSE(c->getNumber() != testInt);
  // Verify inverse after changing test value
  c->setNumber(testInt + 1);
  ASSERT_FALSE(c->getNumber() == testInt);
  ASSERT_TRUE(c->getNumber() != testInt);
}

TEST_F(CardModelTest, test_isSkipBo) {
  c->setNumber(0);
  ASSERT_TRUE(c->isSkipBo(*c));
  c->setNumber(1);
  ASSERT_FALSE(c->isSkipBo(*c));
}
