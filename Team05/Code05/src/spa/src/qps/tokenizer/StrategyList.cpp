//
// Created by Alex on 15/2/2024.
//

#include "StrategyList.h"

namespace qps {
    StrategyList::StrategyList() {
        strategies.push_back(std::make_shared<SingleCharacterStrategy>());
        strategies.push_back(std::make_shared<MultiCharacterStrategy>());
    }

    std::vector<std::shared_ptr<TokenStrategy>> &StrategyList::getStrategies() {
        return strategies;
    }
}
