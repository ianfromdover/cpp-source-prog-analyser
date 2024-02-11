//
// Created by Alex on 7/2/2024.
//

#include "QPS.h"
#include "qps/query_validator/QueryValidator.h"
#include "qps/Exceptions/SyntaxErrorException.h"
#include <iostream>

std::vector<std::string> QPS::evaluate(std::string queryString) {
    std::cout << "QPS Processing query :" << queryString << std::endl;

    QueryPreprocessor preprocessor;
    std::shared_ptr<QueryObject> query;
    try {
        query = preprocessor.processQuery(queryString);
    } catch (SyntaxErrorException e){
        return std::vector<std::string>({"SyntaxError"});
    }

    QueryValidator validator;
    std::vector<std::shared_ptr<Entity>> d = query->getDeclarations();
    std::vector<std::string> errors = validator.validateQuery(*query);
    if (!errors.empty()){
        //throw std::runtime_error("symantic error");
        return std::vector<std::string>({"SemanticError"});
    }

    QueryEvaluator eval(pkb);
    std::shared_ptr<Formattable> results = eval.evaluate(*query);

    return results->format();
}
