//
// Created by yewme on 26/3/2024.
//

#ifndef SPA_QUERYOPTIMIZER_H
#define SPA_QUERYOPTIMIZER_H

#include "common/SpaTypes.h"
#include "qps/query_elements/QueryObject.h"

class QueryOptimizer {
public:
    virtual ~QueryOptimizer() = default;
    virtual void optimize(QueryObject& qo) = 0;
};

#endif //SPA_QUERYOPTIMIZER_H
