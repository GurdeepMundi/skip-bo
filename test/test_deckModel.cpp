/**
   test_deckModel.cpp
   Tests DeckModel class
   Written by Austin Ball
   on 11/11/2021
   CPSC3720
*/

#include "DeckModel.h"
#include "CardModel.h"
#include <vector>
#include "gtest/gtest.h"

using std::vector;

class DeckModelTest : public testing::Test {
 protected:
    DeckModel * d;
    void SetUp() override {
        d = new DeckModel();
        d->buildDeck();
    }
    void TearDown() {
        delete d;
    }
};

TEST_F(DeckModelTest, test_getDeck) {
    vector<CardModel*> test;

    // copy contents in order to verify after
    for (int i = 0; i < d->getDeck().size(); i++) {
        test.push_back(d->getDeck()[i]);
    }
    // verify while checking inverse of assignment
    for (int i = 0; i < test.size(); i++) {
        ASSERT_TRUE(test[i]->getNumber() == d->getDeck()[i]->getNumber());
    }
}

TEST_F(DeckModelTest, test_shuffleDeck) {
    // assign cards to preserve initial order
    vector<CardModel*> test = d->getDeck();

    // verify equality
    ASSERT_TRUE(test == d->getDeck());

    // shuffle deck
    d->shuffleDeck();

    // verify new order after shuffle
    ASSERT_FALSE(test == d->getDeck());
}

TEST_F(DeckModelTest, test_getFirstCard) {
    CardModel* test = d->getDeck()[0];

    ASSERT_TRUE(test->getNumber() == d->getFirstCard()->getNumber());
}
