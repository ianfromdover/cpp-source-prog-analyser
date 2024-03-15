//
// Created by Alex on 7/2/2024.
//

#include "QueryEvaluator.h"
#include <algorithm>
#include "qps/QueryEvaluator/QueryResult/StringResult.h"
#include "PkbStub.h"
#include "qps/QueryEvaluator/QueryResult/IntResult.h"
#include "qps/Exceptions/QPSException.h"


std::shared_ptr<Formattable> QueryEvaluator::evaluate(QueryObject & query) {
    std::shared_ptr<Returnable> returnable = query.getReturnType();
    std::vector<std::shared_ptr<Constraint>> constraints = query.getConstraints();

    std::vector<shared_ptr<QueryResult>> listOfResults;
    listOfResults.reserve(constraints.size());

    //query pkb and store all results into a listOfResults
    for (std::shared_ptr<Constraint> c : constraints) {
        processConstraints(c);
    }

    // Store select clause result into select
    processReturnable(returnable);

    if (results.hasEntries() && ResultTable::findCommonHeaders(results.getTable(), select.getTable()).empty()) {
        // Get the return type column that we want
        std::string column = returnable->getArgumentValue();
        std::vector<string> val = this->select.getDistinctColumn(column);
        std::shared_ptr<StringResult> sd = std::make_shared<StringResult>(val);
        return sd;
    } else {
        if (!results.isEmpty() && !results.hasEntries()) {
            return getEmptyResult();
        }
        this->results.add(select.getTable());
        std::string column = returnable->getArgumentValue();
        std::vector<string> val = this->results.getDistinctColumn(column);
        std::shared_ptr<StringResult> sd = std::make_shared<StringResult>(val);
        return sd;
    }
}

bool isQueryable(std::string type){
    std::vector<std::string> invalidTypes = {TYPE_INTEGER, TYPE_WILDCARD, TYPE_EXPRESSION, TYPE_EXPRESSION_W_WILDCARD, TYPE_QUOTED_IDENT};
    return (std::find(invalidTypes.begin(), invalidTypes.end(), type)) == invalidTypes.end();
}

void QueryEvaluator::processConstraints(std::shared_ptr<Constraint> c){
    table t = c->getRelationshipTable(pkb);
    results.add(t);
}

void QueryEvaluator::processReturnable(std::shared_ptr<Returnable> r) {
     select.add(r->getEntityTable(pkb));
}

std::shared_ptr<Formattable> QueryEvaluator::getEmptyResult() {
    vector<std::string> s;
    return std::make_shared<StringResult>(s);
}


std::shared_ptr<QueryResult> QueryEvaluator::intersect(std::shared_ptr<QueryResult> r1, std::shared_ptr<QueryResult> r2) {
    if (r1->getType() != r2->getType()) {
        throw QPSException("mismatch return type for return queries");
    }
    if (r1->getType() == QueryResultEnum::INTEGER) {
        std::shared_ptr<IntResult> int1 = dynamic_pointer_cast<IntResult>(r1);
        std::shared_ptr<IntResult> int2 = dynamic_pointer_cast<IntResult>(r2);
        vector<int> results = int1->intersect(int2);
        return std::make_shared<IntResult>(results);
    } else {
        std::shared_ptr<StringResult> str1 = dynamic_pointer_cast<StringResult>(r1);
        std::shared_ptr<StringResult> str2 = dynamic_pointer_cast<StringResult>(r2);
        vector<std::string> result = str1->intersect(str2);
        return std::make_shared<StringResult>(result);
    }
}

