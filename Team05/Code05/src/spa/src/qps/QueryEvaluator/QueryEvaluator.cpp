//
// Created by Alex on 7/2/2024.
//

#include "QueryEvaluator.h"
#include <algorithm>
#include "qps/QueryEvaluator/QueryResult/StringResult.h"
#include "PKBStub.h"
#include "qps/QueryEvaluator/QueryResult/IntResult.h"
#include "qps/Exceptions/QPSException.h"


std::shared_ptr<Formattable> QueryEvaluator::evaluate(QueryObject & query) {
    std::shared_ptr<Returnable> returnable = query.getReturnType();
    std::vector<std::shared_ptr<Constraint>> constraints = query.getConstraints();

    std::vector<shared_ptr<QueryResult>> listOfResults;
    listOfResults.reserve(constraints.size());

    if (constraints.empty()) {
//        return pkb.getResult(*r, nullptr);
    }

    //query pkb and store all results into a listOfResults
    for (std::shared_ptr<Constraint> c : constraints) {
        processConstraints(c);
    }

    // Store select clause result into select
    processReturnable(returnable);


    std::string s= query.getReturnType()->getArgumentValue();
    // Might still return index 0 of the table even if there is no common column
    std::vector<string> sk = this->results.getDistinctColumn(s);
    // Do another check here
    // If there are no common headers between returnable and constraint arguments
    /**
    if (ResultTable::findCommonHeaders(results.getTable(), select.getTable()).empty()) {
        // Check if table empty
        if (sk.empty()) {
            // Check None
            std::vector<std::string> empty = {};
            std::shared_ptr<StringResult> sd = std::make_shared<StringResult>(empty);
            return sd;
        } else {
            // Get the return type column that we want
            std::string column = returnable->getReturnType();
            std::vector<string> val = this->select.getDistinctColumn(column);
            std::shared_ptr<StringResult> sd = std::make_shared<StringResult>(val);
            return sd;
        };
    };
     **/
    std::shared_ptr<StringResult> sd = std::make_shared<StringResult>(sk);
    return sd;


//    std::shared_ptr<QueryResult> intersection = listOfResults[0];
//
//    if (listOfResults.size() > 1) {
//        for (int i = 1; i < listOfResults.size(); i++) {
//            intersection = intersect(intersection, listOfResults[i]);
//        }
//    }
//
//    return intersection;

}

bool isQueryable(std::string type){
    std::vector<std::string> invalidTypes = {TYPE_INTEGER, TYPE_WILDCARD, TYPE_EXPRESSION, TYPE_EXPRESSION_W_WILDCARD, TYPE_QUOTED_IDENT};
    return (std::find(invalidTypes.begin(), invalidTypes.end(), type)) == invalidTypes.end();
}

void QueryEvaluator::processConstraints(std::shared_ptr<Constraint> c){
     results.add(c->getRelationshipTable(pkb));
     std::vector<std::shared_ptr<ConstraintArgument>> args = c->getConstraintArguments();

}

void QueryEvaluator::processReturnable(std::shared_ptr<Returnable> r) {
     select.add(r->getEntityTable(pkb));
}
//
//std::shared_ptr<Formattable> QueryEvaluator::evaluate(QueryObject & query) {
//    std::shared_ptr<Returnable> r = query.getReturnType();
//    std::vector<std::shared_ptr<Constraint>> constraints = query.getConstraints();
//
//    std::vector<shared_ptr<QueryResult>> listOfResults;
//    listOfResults.reserve(constraints.size());
//
//    if (constraints.empty()) {
//        return pkb.getResult(*r, nullptr);
//    }
//
//    //query pkb and store all results into a listOfResults
//    for (std::shared_ptr<Constraint> c : constraints) {
//            listOfResults.push_back(pkb.getResult(*r, c));
//    }
//
//    // Intersect all results
//    if (listOfResults.empty()) {
//        return getEmptyResult();
//    }
//
//    std::shared_ptr<QueryResult> intersection = listOfResults[0];
//
//    if (listOfResults.size() > 1) {
//        for (int i = 1; i < listOfResults.size(); i++) {
//            intersection = intersect(intersection, listOfResults[i]);
//        }
//    }
//
//    return intersection;
//
//}

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

