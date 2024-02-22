//
// Created by Alex on 7/2/2024.
//

#include "QPS.h"
#include "qps/query_validator/QueryValidator.h"
#include "qps/Exceptions/SyntaxErrorException.h"
#include "qps/Exceptions/SemanticErrorException.h"
#include <iostream>

std::vector<std::string> QPS::evaluate(std::string queryString) {
    //std::cout << "QPS Processing query :" << queryString << std::endl;

    QueryPreprocessor preprocessor;
    std::shared_ptr<QueryObject> query;
    try {
        query = preprocessor.processQuery(queryString);
    } catch (const SyntaxErrorException& e){
        return std::vector<std::string>({"SyntaxError"});
    } catch (const SemanticErrorException& e1){
        return std::vector<std::string>({"SemanticError"});
    }

    QueryEvaluator eval(pkb);
    std::shared_ptr<Formattable> results = eval.evaluate(*query);

    return results->format();
}
