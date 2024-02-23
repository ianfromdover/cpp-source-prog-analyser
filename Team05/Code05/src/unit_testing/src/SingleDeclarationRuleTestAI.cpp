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
    IntermediateQuery qo;

    auto assignEntity = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");
    auto printEntity = std::make_shared<DeclarationClause>(DeclarationClause());
    printEntity->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::PRINT), "p");
    auto statementEntity = std::make_shared<DeclarationClause>(DeclarationClause());
    statementEntity->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::STMT1), "s");

    qo.addClause(assignEntity);
    qo.addClause(printEntity);
    qo.addClause(statementEntity);

    // Apply the SingleDeclarationRule
    SingleDeclarationRule rule;
    std::string result = rule.validate(qo);

    // Ensure no error message is returned
    REQUIRE(result.empty());
}

TEST_CASE("SingleDeclarationRule_DuplicateDeclarations_Error") {
    // Create a QueryObject with duplicate declarations
    IntermediateQuery qo;
    auto assignEntity1 = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity1->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");
    auto assignEntity2 = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity2->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");

    qo.addClause(assignEntity1);
    qo.addClause(assignEntity2);

    // Apply the SingleDeclarationRule
    SingleDeclarationRule rule;
    std::string result = rule.validate(qo);

    // Ensure error message is returned
    REQUIRE(result == VALIDATION_RULE_SINGLE_DECLARATION);
}

TEST_CASE("SingleDeclarationRule_MixedDeclarations_Error") {
    // Create a QueryObject with a mix of unique and duplicate declarations
    IntermediateQuery qo;

    auto assignEntity1 = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity1->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");
    auto printEntity = std::make_shared<DeclarationClause>(DeclarationClause());
    printEntity->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::PRINT), "y");
    auto assignEntity2 = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity2->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");

    qo.addClause(assignEntity1);
    qo.addClause(printEntity);
    qo.addClause(assignEntity2);

    // Apply the SingleDeclarationRule
    SingleDeclarationRule rule;
    std::string result = rule.validate(qo);

    // Ensure error message is returned as soon as a duplicate is encountered
    REQUIRE(result == VALIDATION_RULE_SINGLE_DECLARATION);
}

TEST_CASE("SingleDeclarationRule_NoDeclarations_NoError") {
    // Create a QueryObject with no declarations
    IntermediateQuery qo;

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