//
// Created by sjh_9 on 9/2/2024.
//

#ifndef SPA_STRATEGYLIST_H
#define SPA_STRATEGYLIST_H

#include <iostream>
#include <vector>
#include "TokenStrategy.h"
#include "SingleCharacterStrategy.h"
#include "DoubleCharacterStrategy.h"
#include "MultiCharacterStrategy.h"

class StrategyList {
private:
    std::vector<std::shared_ptr<TokenStrategy>> strategies;
public:
    StrategyList();
    std::vector<std::shared_ptr<TokenStrategy>>& getStrategies();
};


#endif //SPA_STRATEGYLIST_H
