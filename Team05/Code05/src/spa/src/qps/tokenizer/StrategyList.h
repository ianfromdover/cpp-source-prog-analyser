//
// Created by Alex on 15/2/2024.
//

#ifndef SPA_STRATEGYLIST_H
#define SPA_STRATEGYLIST_H

#include <vector>
#include <memory>
#include "TokenStrategy.h"
#include "SingleCharacterStrategy.h"
#include "MultiCharacterStrategy.h"

namespace qps {
    class StrategyList {
    private:
        std::vector<std::shared_ptr<TokenStrategy>> strategies;
    public:
        StrategyList();

        std::vector<std::shared_ptr<TokenStrategy>> &getStrategies();
    };
}

#endif //SPA_STRATEGYLIST_H
