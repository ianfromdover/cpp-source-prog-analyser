//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QUERYEVALUATOR_H
#define SPA_QUERYEVALUATOR_H


#include <memory>
#include "../QueryProjector/Formattable.h"
#include "qps/query_elements/QueryObject.h"

class QueryEvaluator {
public:
    std::shared_ptr<Formattable> evaluate(QueryObject&);
};


#endif //SPA_QUERYEVALUATOR_H
