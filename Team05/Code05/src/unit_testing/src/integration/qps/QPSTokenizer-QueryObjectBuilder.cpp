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

    QueryObjectBuilderTest builder;
    std::shared_ptr<QueryObject> qo = builder.build(intermediateQuery);
    return qo->toString();
}

TEST_CASE("OneDeclaration_TokenizertoQOBuilder_ReturnsOneSelectClause") {
    std::string source = "stmt s;"
                         "Select s";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: s [STMT]\n{DECLARATIONS}: s [STMT]";
    REQUIRE(processed == output);
}

TEST_CASE("MultipleDeclaration_TokenizertoQOBuilder_ReturnsAllDeclaration") {
    std::string source = "stmt s;"
                         "variable v; "
                         "call cal; "
                         "read r; "
                         "print pr; "
                         "while w; "
                         "if ifs; "
                         "assign a; "
                         "constant c; "
                         "procedure p; "
                         "Select pr";
    std::string processed = testHelper(source);
    std::string output = "{RETURN} pr [PRINT]\n{DECLARATIONS}: s [STMT], v [VARIABLE], cal [CALL], r [READ], pr [PRINT], w [WHILE], ifs [IF], a [ASSIGN], c [CONSTANT], p [PROCEDURE]";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("commasInDeclaration_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read v, v1, v2, v3;"
                         "read v4; "
                         "Select v1";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}



TEST_CASE("singleFollowsConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "if f;"
                         "while w;"
                         "Select w "
                         "such that Parent(f, w)";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleFollowsTConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read v, v1, v2, v3;"
                         "read v4; "
                         "Select v1";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleParentConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read v, v1, v2, v3;"
                         "read v4; "
                         "Select v1";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleParentTConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read v, v1, v2, v3;"
                         "read v4; "
                         "Select v1";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleUsesSConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read v, v1, v2, v3;"
                         "read v4; "
                         "Select v1";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleUsesPConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read v, v1, v2, v3;"
                         "read v4; "
                         "Select v1";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleModifiesSConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read v, v1, v2, v3;"
                         "read v4; "
                         "Select v1";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}

TEST_CASE("singleModifiesPConstraint_TokenizertoQOBuilder_returnsCorrect") {
    std::string source = "read v, v1, v2, v3;"
                         "read v4; "
                         "Select v1";
    std::string processed = testHelper(source);
    std::string output = "{RETURN}: v1 [READ]\n{DECLARATIONS}: v [READ], v1 [READ], v2 [READ], v3 [READ], v4 [READ]";
    REQUIRE(processed == output);
    cout << processed;
}