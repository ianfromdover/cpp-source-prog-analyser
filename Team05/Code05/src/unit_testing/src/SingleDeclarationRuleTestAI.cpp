//
// Created by tohzh on 10/2/2024.
//

#include "catch.hpp"
using namespace std;

#include "catch.hpp"
#include "qps/query_validator/SingleDeclarationRule.h" // Include the header file for SingleDeclarationRule
#include "qps/query_elements/QueryObject.h"
#include "qps/query_elements/constraint_argument/statement_reference/StatementEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/PrintEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/AssignEntity.h"

// ai-gen start(gpt, 1, e)
// prompt: https://chat.openai.com/share/dccb94c8-d4d6-4310-b2f1-2306849865cf
TEST_CASE("SingleDeclarationRule_ValidDeclarations_NoError") {
    // Create a QueryObject with valid unique declarations
    QueryObject qo;

    auto assignEntity = std::make_shared<AssignEntity>(AssignEntity("z"));
    auto printEntity = std::make_shared<PrintEntity>(PrintEntity("w"));
    auto statementEntity = std::make_shared<StatementEntity>(StatementEntity("p"));

    qo.addDeclaration(assignEntity);
    qo.addDeclaration(printEntity);
    qo.addDeclaration(statementEntity);

    // Apply the SingleDeclarationRule
    SingleDeclarationRule rule;
    std::string result = rule.validate(qo);

    // Ensure no error message is returned
    REQUIRE(result.empty());
}

TEST_CASE("SingleDeclarationRule_DuplicateDeclarations_Error") {
    // Create a QueryObject with duplicate declarations
    QueryObject qo;
    auto assignEntity1 = std::make_shared<AssignEntity>(AssignEntity("x"));
    auto assignEntity2 = std::make_shared<AssignEntity>(AssignEntity("x"));
    qo.addDeclaration(assignEntity1);
    qo.addDeclaration(assignEntity2);

    // Apply the SingleDeclarationRule
    SingleDeclarationRule rule;
    std::string result = rule.validate(qo);

    // Ensure error message is returned
    REQUIRE(result == VALIDATION_RULE_SINGLE_DECLARATION);
}

TEST_CASE("SingleDeclarationRule_MixedDeclarations_Error") {
    // Create a QueryObject with a mix of unique and duplicate declarations
    QueryObject qo;

    auto assignEntity1 = std::make_shared<AssignEntity>(AssignEntity("x"));
    auto printEntity = std::make_shared<PrintEntity>(PrintEntity("y"));
    auto assignEntity2 = std::make_shared<AssignEntity>(AssignEntity("x"));

    qo.addDeclaration(assignEntity1);
    qo.addDeclaration(printEntity);
    qo.addDeclaration(assignEntity2);

    // Apply the SingleDeclarationRule
    SingleDeclarationRule rule;
    std::string result = rule.validate(qo);

    // Ensure error message is returned as soon as a duplicate is encountered
    REQUIRE(result == VALIDATION_RULE_SINGLE_DECLARATION);
}

TEST_CASE("SingleDeclarationRule_NoDeclarations_NoError") {
    // Create a QueryObject with no declarations
    QueryObject qo;

    // Apply the SingleDeclarationRule
    SingleDeclarationRule rule;
    std::string result = rule.validate(qo);

    // Ensure no error message is returned
    REQUIRE(result.empty());
}

// ai-gen end

TEST_CASE("scratch pad single declaration"){
    IntermediateQuery query;

    SingleDeclarationRule rule;
    std::string result = rule.validate(query);

    REQUIRE(result.empty());
}