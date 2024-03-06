//
// Created by sjh_9 on 25/2/2024.
//

#include "IntColumn.h"

void IntColumn::addInt(int val) {
    intVector.push_back(val);
}

int IntColumn::getIntByIndex(int index) {
    return intVector[index];
}

std::vector<int> IntColumn::getIntVector() {
    return intVector;
}