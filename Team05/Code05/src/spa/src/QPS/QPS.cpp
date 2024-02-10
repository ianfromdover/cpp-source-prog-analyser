//
// Created by Alex on 7/2/2024.
//

#include "QPS.h"
#include "qps/query_validator/QueryValidator.h"
#include <iostream>

std::vector<std::string> QPS::evaluate(std::string queryString) {
    std::cout << "QPS Processing query :" << queryString << std::endl;

    QueryPreprocessor preprocessor;
    std::shared_ptr<QueryObject> query = preprocessor.processQuery(queryString);

    QueryValidator validator;
    std::vector<std::shared_ptr<Entity>> d = query->getDeclarations();
    std::vector<std::string> errors = validator.validateQuery(*query);
    if (!errors.empty()){
        throw std::runtime_error("symantic error");
    }

    QueryEvaluator eval;
    std::shared_ptr<Formattable> results = eval.evaluate(*query);

    return results->format();
}
