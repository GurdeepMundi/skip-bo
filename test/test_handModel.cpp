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
