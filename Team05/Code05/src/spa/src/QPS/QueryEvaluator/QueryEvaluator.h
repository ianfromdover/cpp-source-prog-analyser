//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QUERYEVALUATOR_H
#define SPA_QUERYEVALUATOR_H


#include <memory>
#include "../QueryProjector/Formattable.h"
#include "qps/query_elements/QueryObject.h"

#include "pkb/QueryPKB.h"

class QueryEvaluator {
public:
    explicit QueryEvaluator(QueryPKB& stub) : pkb(stub) {} ;
    std::shared_ptr<Formattable> evaluate(QueryObject&);
private:
    QueryPKB& pkb;
};


#endif //SPA_QUERYEVALUATOR_H
