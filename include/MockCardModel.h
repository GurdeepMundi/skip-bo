/*
 * MockCardModel.h
 *
 *  Created on: Nov. 22, 2021
 *      Author: Jackson Druhan
 */

#ifndef MOCKCARDMODEL_H
#define MOCKCARDMODEL_H

#include "CardModel.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class MockCardModel : public CardModel {
public:
    explicit MockCardModel() : CardModel(2) {}
    virtual ~MockCardModel() {}
    MOCK_METHOD1(setNumber, void(int));
    MOCK_METHOD0(getNumber, int());
    MOCK_METHOD1(isSkipBo, bool(CardModel));
};

#endif //MOCKCARDMODEL_H
