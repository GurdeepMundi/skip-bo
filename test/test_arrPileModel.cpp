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
  CardModel* c2 = new CardModel(3);
  CardModel* c3 = new CardModel(3);
  CardModel* c4 = new CardModel(3);
  EXPECT_FALSE(myArray->insertCard(c, 1));
  c->setNumber(1);
  EXPECT_TRUE(myArray->insertCard(c, 1));
  c2->setNumber(2);
  EXPECT_TRUE(myArray->insertCard(c2, 1));
  c3->setNumber(0);
  EXPECT_TRUE(myArray->insertCard(c3, 1));
  c4->setNumber(1);
  EXPECT_FALSE(myArray->insertCard(c4, 1));
  delete c, c2, c3, c4;
}

TEST_F(arrPileModelTest, useDiscard) {
  CardModel* c = new CardModel(1);
  CardModel* c2 = new CardModel(2);
  EXPECT_EQ(myArray->usediscard(1)->getNumber(),20);
  myArray->insertCard(c, 2);
  myArray->insertCard(c2, 2);
  EXPECT_EQ(myArray->usediscard(2)->getNumber(), c2->getNumber());
  delete c, c2;
}

TEST_F(arrPileModelTest, popTopCard) {
  CardModel* c = new CardModel(1);
  CardModel* c2 = new CardModel(2);
  myArray->insertCard(c, 2);
  myArray->insertCard(c2, 2);
  myArray->popTopcard(2);
  EXPECT_EQ(myArray->getPile(2)->currentPile.size(), 1);
  myArray->popTopcard(2);
  EXPECT_EQ(myArray->getPile(2)->currentPile.size(), 0);
  delete c, c2;
}

TEST_F(arrPileModelTest, putCardInDiscard) {
  CardModel* c = new CardModel(3);
  myArray->putCardInDiscard(c, 1);
  EXPECT_EQ(myArray->getPile(1)->getTopNum(), 3);
  delete c;
}
