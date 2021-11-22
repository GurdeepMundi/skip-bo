/**
   test_pileModel.cpp
   Tests PileModel class
   Written by Gurdeep Singh
   on 09/22/2021
   CPSC3720
*/
#include <gtest/gtest.h>
#include <ArrPileModel.h>
#include <PileModel.h>
#include <vector>
#include <CardModel.h>


class arrPileModelTest: public testing::Test {
 protected:
  ArrPileModel* myArray;
  void SetUp() override {
    myArray = new ArrPileModel();
  }
  void TearDown() {
    delete myArray;
  }
};

// tests the constructor and getPile
TEST_F(arrPileModelTest, constructorTest) {
  PileModel* newModel;
  newModel = myArray->getPile(3);
  EXPECT_EQ(newModel->getNumberOfCards(), 0);
}

TEST_F(arrPileModelTest, buildPileArr) {
  std::vector<PileModel* > v;
  v = myArray->buildPileArr();
  EXPECT_EQ(v.size(), 4);
}

TEST_F(arrPileModelTest, insertCard) {
  CardModel* c = new CardModel(3);
  EXPECT_FALSE(myArray->insertCard(c, 1));
  c->setNumber(1);
  EXPECT_TRUE(myArray->insertCard(c, 1));
  c->setNumber(2);
  EXPECT_TRUE(myArray->insertCard(c, 1));
  c->setNumber(0);
  EXPECT_TRUE(myArray->insertCard(c, 1));
  c->setNumber(1);
  EXPECT_FALSE(myArray->insertCard(c, 1));
}
