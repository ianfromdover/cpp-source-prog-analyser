//
// Created by sjh_9 on 25/2/2024.
//

#include "StringColumn.h"

void StringColumn::addString(const std::string& str) {
    stringVector.push_back(str);
}

std::string StringColumn::getStringByIndex(int index) {
    return stringVector[index];
}

std::vector<std::string> StringColumn::getStringVector() {
    return stringVector;
}


