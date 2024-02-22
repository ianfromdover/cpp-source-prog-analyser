//
// Created by Alex on 7/2/2024.
//

#include "QueryPreprocessor.h"
#include "qps/tokenizer/QPSStrategyList.h"
#include "qps/tokenizer/Tokenizer.h"
#include "qps/parser/QPSParser.h"
#include "qps/query_builder/QueryObjectBuilder.h"
#include "qps/query_validator/QueryValidator.h"
#include "qps/Exceptions/SyntaxErrorException.h"
#include "qps/Exceptions/SemanticErrorException.h"
#include "qps/Exceptions/QPSParseException.h"
#include "qps/Exceptions/QPSTokenizeException.h"
#include "qps/Exceptions/QPSException.h"


std::shared_ptr<QueryObject> QueryPreprocessor::processQuery(std::string & queryStr) {
    std::shared_ptr<IntermediateQuery> intermediateQuery;

    try {
        std::shared_ptr<QPSStrategyList> strategies = std::make_shared<QPSStrategyList>();
        std::shared_ptr<QPSTokenList> tokens = std::make_shared<QPSTokenList>();
        Tokenizer tokenizer(queryStr, strategies, tokens);
        tokenizer.tokenize();
        QPSParser parser(*tokens);
        intermediateQuery = parser.parse();
    } catch (QPSParseException& e) {
        throw SyntaxErrorException(e.what());
    } catch (QPSTokenizeException& e) {
        throw SyntaxErrorException(e.what());
    }

    QueryValidator validator;

    auto validataionResults = validator.validateQuery(*intermediateQuery);
    if (!validataionResults.empty()){
        std::string msg;
        for(auto& result : validataionResults){
            msg+=result;
        }
        throw SemanticErrorException(msg);
    }

    QueryObjectBuilderTest builder;
    std::shared_ptr<QueryObject> qo = builder.build(intermediateQuery);

    return qo;
}
