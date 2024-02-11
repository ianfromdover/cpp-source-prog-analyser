//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QUERYEVALUATOR_H
#define SPA_QUERYEVALUATOR_H


#include <memory>
#include "../QueryProjector/Formattable.h"
#include "qps/query_elements/QueryObject.h"
#include "PKBStub.h"

class QueryEvaluator {
public:
    explicit QueryEvaluator(PKBStub& stub) : pkb(stub) {} ;
    std::shared_ptr<Formattable> evaluate(QueryObject&);
private:
    PKBStub& pkb;
};


#endif //SPA_QUERYEVALUATOR_H
