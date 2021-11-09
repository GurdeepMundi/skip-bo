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

class PileModelTest: public ::testing::Test {
 public:
  void SetUp() {
    p = new PileModel();
    c = new CardModel();
  }
  void TearDown() {
    delete p;
  }
  PileModel* p;
  CardModel* c;
};

TEST_F(PileModelTest, test_Constructor) {
  EXPECT_EQ(p->getSize(), 0);
}

TEST_F(PileModelTest, test_getsize) {
  p->addCard(c);
  EXPECT_EQ(p->getSize(), 1);
}
