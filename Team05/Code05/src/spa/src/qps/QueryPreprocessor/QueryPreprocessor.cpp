//
// Created by Alex on 7/2/2024.
//

#include "QueryPreprocessor.h"
#include "HandlerChain.h"
#include "qps/tokenizer/QPSStrategyList.h"
#include "qps/tokenizer/Tokenizer.h"
#include "qps/parser/QPSParser.h"
#include "qps/query_validator/RuleSet.h"
#include "qps/query_builder/QueryObjectBuilder.h"


std::shared_ptr<QueryObject> QueryPreprocessor::processQuery(std::string & queryStr) {

    std::shared_ptr<QPSStrategyList> strategies = std::make_shared<QPSStrategyList>();
    std::shared_ptr<QPSTokenList> tokens = std::make_shared<QPSTokenList>();
    Tokenizer tokenizer(queryStr, strategies, tokens);
    tokenizer.tokenize();
    QPSParser parser(*tokens);
    std::shared_ptr<IntermediateQuery> intermediateQuery = parser.parse();

    RuleSet ruleSet;
    std::string validationResults;
    for (auto& rule : ruleSet.getRules()){
         std::string result = rule->validate(*intermediateQuery);
         validationResults.append(result.empty()? "" : result + ", ");
    }

    if (!validationResults.empty()){
        std::string msg = "semantic error: " + validationResults;
        throw std::exception(msg.c_str());
    }

    QueryObjectBuilderTest builder;
    std::shared_ptr<QueryObject> qo = builder.build(intermediateQuery);

    return qo;



}
