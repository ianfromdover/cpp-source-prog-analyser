//
// Created by Alex on 7/2/2024.
//

#include "QueryEvaluator.h"
#include <algorithm>
#include <utility>
#include "PkbStub.h"
#include "qps/query_evaluator/query_result/StringResult.h"
#include "qps/query_evaluator/query_result/IntResult.h"
#include "qps/exceptions/QPSException.h"


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
        return returnable->getSelectResults(pkb, make_shared<ResultTable>(select), make_shared<ResultTable>(results));
    } else {
        if (!results.isEmpty() && !results.hasEntries()) {
            if (returnable->getReturnType() == RETURN_BOOL_RESULT) {
                std::vector<std::string> val = {"FALSE"};
                return std::make_shared<StringResult>(val);
            }
            return getEmptyResult();
        }
        this->results.add(select.getTable());
        return returnable->getSelectResults(pkb, make_shared<ResultTable>(results), make_shared<ResultTable>(results));
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
  table t = r->getEntityTable(pkb);
  ResultTable tabl = ResultTable(t);
  tabl.removeColumnByHeader(HEADER_ENT_WITH_TOMERGE);
  select.add(tabl.getTable());
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

