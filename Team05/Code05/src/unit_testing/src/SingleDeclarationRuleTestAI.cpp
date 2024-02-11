//
// Created by tohzh on 10/2/2024.
//

#include "TNode.h"

#include "catch.hpp"
using namespace std;

#include "catch.hpp"
#include "qps/query_validator/SingleDeclarationRule.h" // Include the header file for SingleDeclarationRule
#include "qps/query_elements/QueryObject.h"
#include "qps/query_elements/constraint_argument/StatementEntity.h"
#include "qps/query_elements/constraint_argument/PrintEntity.h"
#include "qps/query_elements/constraint_argument/AssignEntity.h"

// ai-gen start(gpt, 1, e)
// prompt: https://chat.openai.com/share/dccb94c8-d4d6-4310-b2f1-2306849865cf
TEST_CASE("SingleDeclarationRule_ValidDeclarations_NoError") {
    // Create a QueryObject with valid unique declarations
    QueryObject qo;
    AssignEntity assignEntity("z");
    PrintEntity printEntity("w");
    StatementEntity statementEntity("p");
    qo.addDeclaration(assignEntity);
    qo.addDeclaration(printEntity);
    qo.addDeclaration(statementEntity);

    // Apply the SingleDeclarationRule
    SingleDeclarationRule rule;
    std::string result = rule.validate(qo);

    // Ensure no error message is returned
    REQUIRE(result == "");
}

TEST_CASE("SingleDeclarationRule_DuplicateDeclarations_Error") {
    // Create a QueryObject with duplicate declarations
    QueryObject qo;
    AssignEntity assignEntity1("x");
    AssignEntity assignEntity2("x");
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
    AssignEntity assignEntity1("x");
    PrintEntity printEntity("y");
    AssignEntity assignEntity2("x");

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