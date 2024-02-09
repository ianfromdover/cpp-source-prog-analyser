//
// Created by sjh_9 on 9/2/2024.
//

#include "StrategyList.h"
StrategyList::StrategyList() {
    strategies.push_back(std::make_shared<SingleCharacterStrategy>());
    strategies.push_back(std::make_shared<DoubleCharacterStrategy>());
    strategies.push_back(std::make_shared<MultiCharacterStrategy>());
}

std::vector<std::shared_ptr<TokenStrategy>>& StrategyList::getStrategies() {
    return strategies;
}