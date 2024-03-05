//
// Created by Alex on 15/2/2024.
//

#include "QPSStrategyList.h"


QPSStrategyList::QPSStrategyList() {
    strategies.push_back(std::make_shared<QPSSingleCharacterStrategy>());
    strategies.push_back(std::make_shared<QPSMultiCharacterStrategy>());
}

std::vector<std::shared_ptr<QPSTokenStrategy>> &QPSStrategyList::getStrategies() {
    return strategies;
}

