/**
   test_pileModel.cpp
   Tests PileModel class
   Written by Gurdeep Singh
   on 09/11/2021
   CPSC3720
*/

#include <PileModel.h>
#include <gtest/gtest.h>

class PileModelTest: public ::testing::Test {
 public:
  void SetUp() {
    p = new PileModel();
  }
  void TearDown() {
    delete p;
  }
  PileModel* p;
};

TEST_F (PileModelTest, test_Constructor) {
  EXPECT_EQ(p->getSize(), 0);
}
