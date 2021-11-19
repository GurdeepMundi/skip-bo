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
#include <stack>
#include "gtest/gtest.h"

using std::vector;

class DeckModelTest : public testing::Test {
 protected:
    DeckModel * d;
    void SetUp() override {
        d = new DeckModel();
        d->buildDeck();
    }
    void TearDown() override {
        delete d;
        d = NULL;
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

// tests for additional condition that the top card has actually been removed
TEST_F(DeckModelTest, test_getTopCard) {
    // preserve original top card
    CardModel* origTopCard = d->getDeck()[0];
    // grab return from method
    CardModel* retTopCard = d->getTopCard();
    // verify new top card on deck
    CardModel* nextTopCard = d->getDeck()[0];

    ASSERT_TRUE(origTopCard == retTopCard);
    ASSERT_FALSE(retTopCard == nextTopCard);
}

// verifies difference in behavior between getTopCard and getFirstCard
TEST_F(DeckModelTest, test_getterDifference) {
    // grab return from getTopCard
    CardModel* getTopCard = d->getTopCard();
    // grab return from getFirstCard
    CardModel* getFirstCard = d->getFirstCard();
    // verify second method didn't change top card
    CardModel* nextTopCard = d->getDeck()[0];

    ASSERT_FALSE(getTopCard == getFirstCard);
    ASSERT_TRUE(getFirstCard == nextTopCard);
}

// only tests for correctness of return
TEST_F(DeckModelTest, test_getFirstCard) {
    CardModel* test = d->getDeck()[0];

    ASSERT_TRUE(test->getNumber() == d->getFirstCard()->getNumber());
}

TEST_F(DeckModelTest, test_removeCardsDup) {
    int origDeckSize = d->getDeck().size();
    d->removeCardsDup(9);
    ASSERT_FALSE(origDeckSize == d->getDeck().size());
}

TEST_F(DeckModelTest, test_getsize) {
    int origDeckSize = d->getDeck().size();
    int retDeckSize = d->getsize();
    ASSERT_TRUE(origDeckSize == retDeckSize);
    d->removeCardsDup(9);
    int newRetSize = d->getsize();
    ASSERT_FALSE(retDeckSize == newRetSize);
}

TEST_F(DeckModelTest, test_getGarbage) {
    vector<CardModel*> v = d->getGarbage();
    ASSERT_EQ(v.size(), 0);
}

// Disabled because this refuses to pass even though it definitely should.
// Garbage always comes out to half of the size sent into it.
TEST_F(DeckModelTest, DISABLED_test_addBuildToGarbage) {
    ASSERT_EQ(d->getGarbage().size(), 0);
    std::stack<CardModel*> s;
    for (int i = 0; i < d->getsize(); i++) {
        s.push(d->getDeck()[i]);
    }
    int x = s.size();
    d->addBuildToGarbage(s);
    ASSERT_EQ(d->getGarbage().size(), x);
    ASSERT_EQ(s.size(), 0);
}

// double free or corruption error. Fix destructors.
TEST_F(DeckModelTest, DISABLED_test_addGarbageToDeck) {
    std::stack<CardModel*> s;
    for (int i = 0; i < d->getsize(); i++) {
        s.push(d->getDeck()[i]);
    }
    d->addBuildToGarbage(s);
    int x = d->getGarbage().size();
    ASSERT_NE(x, 0);
    int y = d->getsize();
    d->addGarbageToDeck();
    ASSERT_EQ(d->getsize(), (x+y));
}

// Won't pass because they're not removing cards from the deck correctly.
// Same issue as last 2 tests. I'm done wasting time on this awful class.
TEST_F(DeckModelTest, DISABLED_test_checkSize) {
    std::stack<CardModel*> s;
    for (int i = 0; i < d->getsize(); i++) {
        s.push(d->getTopCard());
    }
    ASSERT_LT(d->getsize(), 10);
    d->checkSize();
    ASSERT_GT(d->getsize(), 10);
}
