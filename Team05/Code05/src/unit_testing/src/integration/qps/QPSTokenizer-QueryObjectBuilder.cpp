//
// Created by tohzh on 20/2/2024.
//

#include "qps/query_builder/QueryObjectBuilder.h"
#include "qps/parser/IntermediateQuery.h"
#include "catch.hpp"
#include "qps/tokenizer/QPSStrategyList.h"
#include "qps/tokenizer/Tokenizer.h"
#include "qps/parser/QPSParser.h"
#include <iostream>

using namespace std;

// this testHelper takes in a query in string and returns the query object string representation.
std::string testHelper(std::string source) {
    std::shared_ptr<QPSStrategyList> strategies = std::make_shared<QPSStrategyList>();
    std::shared_ptr<QPSTokenList> tokens = std::make_shared<QPSTokenList>();
    Tokenizer tokenizer(source, strategies, tokens);
    tokenizer.tokenize();
    QPSParser parser(*tokens);

    std::shared_ptr<IntermediateQuery> intermediateQuery = parser.parse();
    intermediateQuery->processDeclarations();

    QueryObjectBuilder builder;
    std::shared_ptr<QueryObject> qo = builder.build(intermediateQuery);
    return qo->toString();
}

TEST_CASE("OneDeclaration_TokenizertoQOBuilder_ReturnsOneSelectClause") {
    std::string source = "stmt s;";
    std::cout << testHelper(source);
}