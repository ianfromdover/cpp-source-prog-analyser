//
// Created by Alex on 7/2/2024.
//

#include "QueryEvaluator.h"
#include "qps/QueryEvaluator/QueryResult/StringResult.h"
#include "PKBStub.h"
#include "qps/QueryEvaluator/QueryResult/IntResult.h"

std::shared_ptr<Formattable> QueryEvaluator::evaluate(QueryObject & query) {

    std::shared_ptr<Returnable> r = query.getReturnType();
    std::vector<std::shared_ptr<Constraint>> constraints = query.getConstraints();


    std::shared_ptr<QueryResult> result = pkb.getResult(*r,*constraints[0]);

    std::vector<int> results;
    IntResult res(results);
    std::shared_ptr<QueryResult> result1 = std::make_shared<IntResult>(res);

    // end stub
    return result;
}
