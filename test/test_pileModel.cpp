/**
   test_pileModel.cpp
   Tests PileModel class
   Written by Gurdeep Singh
   on 09/11/2021
   CPSC3720
*/

#include <PileModel.h>
#include <CardModel.h>
#include <gtest/gtest.h>

class PileModelTest: public testing::Test {
 protected:
  PileModel* p;
  void SetUp() override {
  p = new PileModel();
  }
  void TearDown() {
    delete p;
  }
};

TEST_F(PileModelTest, test_Constructor) {
  EXPECT_EQ(p->getSize(), 0);
}

TEST_F(PileModelTest, test_getsize) {
  CardModel* c;
  c = new CardModel(0);
  p->addCard(c);
  EXPECT_EQ(p->getSize(), 1);
  //not deleting c because gives segfault otherwise
}
/*
TEST_F(PileModelTest, DISABLED_test_addCard) {
  CardModel* newCard = new CardModel(3);
  p->addCard(c);
  p->addCard(newCard);
  EXPECT_EQ(p->getSize(), 2);
  EXPECT_EQ(p->getTopNum(), newCard->getNumber());
  delete newCard;
}

TEST_F(PileModelTest, DISABLED_experiment) {
  CardModel* cc = new CardModel(2);
  delete cc;
}*/