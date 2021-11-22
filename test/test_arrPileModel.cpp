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


class arrPileModelTest: public testing::Test {
 protected:
  void SetUp() override {
    ArrPileModel* myArrPile = new ArrPileModel();
  }
  void TearDown() {
    //delete myArrPile;
  }
};

TEST_F(arrPileModelTest, constructorTest) {
  PileModel* newModel;
  newModel = myArrPile->getPile(4);
  EXPECT_EQ(newModel->getNumberOfCards(), 0);
}
