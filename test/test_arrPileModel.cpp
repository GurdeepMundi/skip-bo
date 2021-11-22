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

TEST_F(arrPileModelTest, getPile) {

}
