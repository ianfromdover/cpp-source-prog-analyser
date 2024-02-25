//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QUERYEVALUATOR_H
#define SPA_QUERYEVALUATOR_H


#include <memory>
#include "../QueryProjector/Formattable.h"
#include "qps/query_elements/QueryObject.h"
#include "pkb/apis/QueryPKB.h"
#include "qps/QueryEvaluator/QueryResult/QueryResult.h"

class QueryEvaluator {
public:
    explicit QueryEvaluator(QueryPKBVirtual& stub) : pkb(stub) {} ;
    std::shared_ptr<Formattable> evaluate(QueryObject&);
private:
    QueryPKBVirtual& pkb;
    shared_ptr<QueryResult> intersect(shared_ptr<QueryResult> r1, shared_ptr<QueryResult> r2);
    std::shared_ptr<Formattable> getEmptyResult();
};


#endif //SPA_QUERYEVALUATOR_H
