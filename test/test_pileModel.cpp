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
 prohibited:
   PileModel* p;
   CardModel* c;
  void SetUp() {
    p = new PileModel();
    c = new CardModel(0);
  }
  void TearDown() {
    delete p;
    delete c;
  }
};

TEST_F(PileModelTest, test_Constructor) {
  EXPECT_EQ(p->getSize(), 0);
}

TEST_F(PileModelTest, test_getsize) {
  p->addCard(c);
  EXPECT_EQ(p->getSize(), 1);
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
