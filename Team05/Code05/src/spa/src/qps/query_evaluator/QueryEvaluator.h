//
// Created by Alex on 7/2/2024.
//

#ifndef SPA_QUERYEVALUATOR_H
#define SPA_QUERYEVALUATOR_H


#include <memory>
#include "qps/query_elements/QueryObject.h"
#include "pkb/apis/QueryPkb.h"
#include "qps/query_evaluator/query_result/QueryResult.h"
#include "qps/query_evaluator/query_result/TupleStringResult.h"
#include "qps/query_projector/Formattable.h"
#include "qps/query_projector/ResultTable.h"

class QueryEvaluator {
public:
    explicit QueryEvaluator(QueryPkbVirtual& stub) : pkb(stub) {} ;
    std::shared_ptr<Formattable> evaluate(QueryObject&);
    void processConstraints(std::shared_ptr<Constraint> c);
private:
    ResultTable results;
    ResultTable select;
    QueryPkbVirtual& pkb;
    shared_ptr<QueryResult> intersect(shared_ptr<QueryResult> r1, shared_ptr<QueryResult> r2);
    std::shared_ptr<Formattable> getEmptyResult();
    void processReturnable(shared_ptr<Returnable> r);
};


#endif //SPA_QUERYEVALUATOR_H
