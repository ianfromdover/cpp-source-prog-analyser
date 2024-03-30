//
// Created by yewme on 29/3/2024.
//

#ifndef SPA_QUERYOPTIMIZERCHAIN_H
#define SPA_QUERYOPTIMIZERCHAIN_H

#include "common/SpaTypes.h"
#include "qps/query_elements/QueryObject.h"
#include "qps/query_optimizer/QueryOptimizer.h"

class QueryOptimizerChain {

private:
    std::vector<std::unique_ptr<QueryOptimizer>> optimizers;

public:
    QueryOptimizerChain() = default;

    void addOptimizer(std::unique_ptr<QueryOptimizer> optimizer) {
        optimizers.push_back(std::move(optimizer));
    }

    void removeOptimizer() {
        // TODO: how to remove the optimizer from the list?
    }

    void clearOptimizers() {
        optimizers.clear();
    }

    void sortOptimizers() {
        // TODO: how to determine which to do first?
    }

    void optimize(QueryObject& qo)  {
        for (const auto& optimizer : optimizers) {
            optimizer->optimize(qo);
        }
    }
};

#endif //SPA_QUERYOPTIMIZERCHAIN_H
