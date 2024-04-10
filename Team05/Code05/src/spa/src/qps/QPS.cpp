//
// Created by Alex on 7/2/2024.
//

#include "QPS.h"
#include "qps/query_validator/QueryValidator.h"
#include "qps/exceptions/SyntaxErrorException.h"
#include "qps/exceptions/SemanticErrorException.h"
#include "qps/exceptions/QPSException.h"
#include "qps/query_optimizer/QueryOptimizerChain.h"
#include "qps/query_optimizer/concrete_optimizers/DuplicateRemovalOptimizer.h"
#include <iostream>

std::vector<std::string> QPS::evaluate(std::string queryString) {

    QueryPreprocessor preprocessor;
    QueryOptimizerChain chain;
    std::shared_ptr<QueryObject> query;
    try {
        query = preprocessor.processQuery(queryString);
    } catch (const SyntaxErrorException& e){
        return std::vector<std::string>({"SyntaxError"});
    } catch (const SemanticErrorException& e1){
        return std::vector<std::string>({"SemanticError"});
    } catch (const QPSException& e2){
        return std::vector<std::string>({"SemanticError??"});
    }

    // Add desired optimizers to the optimizer chain
    DuplicateRemovalOptimizer removeDuplicates;
    chain.addOptimizer(make_unique<DuplicateRemovalOptimizer>(removeDuplicates));
    chain.optimize(*query);

    QueryEvaluator eval(*pkb);
    std::shared_ptr<Formattable> results = eval.evaluate(*query);

    pkb->resetAffects();
    pkb->resetNextT();

    return results->format();

}
