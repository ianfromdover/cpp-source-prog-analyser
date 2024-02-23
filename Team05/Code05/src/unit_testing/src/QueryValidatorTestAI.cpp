//
// Created by tohzh on 11/2/2024.
//

#include "catch.hpp"
using namespace std;

#include "qps/query_elements/constraint/Constraint.h"
#include "qps/query_elements/constraint/ParentConstraint.h"

#include "qps/query_elements/constraint_argument/statement_reference/AssignEntity.h"
#include "qps/query_elements/constraint_argument/statement_reference/PrintEntity.h"
#include "qps/query_validator/QueryValidator.h"
#include "qps/query_elements/QueryObject.h"


// ai-gen start(gpt, 1, e)
// prompt: https://chat.openai.com/share/b79012a9-d6db-4272-a8f5-d4e4e167dd91
TEST_CASE("QueryValidator_ValidateQuery_NoErrors") {
    // Create a QueryObject with valid unique declarations and no constraint violations
    IntermediateQuery qo;
    auto assignEntity = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");
    auto printEntity = std::make_shared<DeclarationClause>(DeclarationClause());
    printEntity->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::PRINT), "y");

    qo.addClause(assignEntity);
    qo.addClause(printEntity);

    auto t1 = QPSToken(QPSTokenType(QPSTokenType::QPSTypeInfo::SYNONYM), "x");
    auto t2 = QPSToken(QPSTokenType(QPSTokenType::QPSTypeInfo::SYNONYM), "y");
    auto parentConstraint = std::make_shared<RelationshipClause>(QPSTokenType::QPSTypeInfo::PARENT, t1, QPSTokenType::QPSTypeInfo::STMT_REF, t2, QPSTokenType::QPSTypeInfo::STMT_REF);

    qo.addClause(parentConstraint);

    // Apply QueryValidator to validate the QueryObject
    QueryValidator validator;
    std::vector<std::string> failedRules = validator.validateQuery(qo);

    // Ensure no failed rules are returned
    REQUIRE(failedRules.empty());
}

TEST_CASE("QueryValidator_ValidateQuery_SingleDeclarationRuleViolation") {
    // Create a QueryObject violating the SingleDeclarationRule
    IntermediateQuery qo;

    auto assignEntity1 = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity1->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");
    auto assignEntity2 = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity2->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");

    qo.addClause(assignEntity1);
    qo.addClause(assignEntity2);

    // Apply QueryValidator to validate the QueryObject
    QueryValidator validator;
    std::vector<std::string> failedRules = validator.validateQuery(qo);

    // Ensure SingleDeclarationRule violation is detected
    REQUIRE(failedRules.size() == 1);
    REQUIRE(failedRules[0] == VALIDATION_RULE_SINGLE_DECLARATION);
}

TEST_CASE("QueryValidator_ValidateQuery_NoDeclarationRuleViolation") {
    // Create a QueryObject violating the NoDeclarationRule
    IntermediateQuery qo;

    auto assignEntity = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");
    auto printEntity = std::make_shared<DeclarationClause>(DeclarationClause());
    printEntity->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::PRINT), "y");

    auto t1 = QPSToken(QPSTokenType(QPSTokenType::QPSTypeInfo::SYNONYM), "x");
    auto t2 = QPSToken(QPSTokenType(QPSTokenType::QPSTypeInfo::SYNONYM), "y");
    auto pConstraint = std::make_shared<RelationshipClause>(QPSTokenType::QPSTypeInfo::PARENT, t1, QPSTokenType::QPSTypeInfo::STMT_REF, t2, QPSTokenType::QPSTypeInfo::STMT_REF);

    qo.addClause(pConstraint);

    // Apply QueryValidator to validate the QueryObject
    QueryValidator validator;
    std::vector<std::string> failedRules = validator.validateQuery(qo);

    // Ensure NoDeclarationRule violation is detected
    REQUIRE(failedRules.size() == 1);
    REQUIRE(failedRules[0] == VALIDATION_RULE_NO_DECLARATION);
}

TEST_CASE("QueryValidator_ValidateQuery_MultipleRuleViolations") {
    // Create a QueryObject violating both SingleDeclarationRule and NoDeclarationRule
    IntermediateQuery qo;

    auto assignEntity1 = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity1->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");
    auto assignEntity2 = std::make_shared<DeclarationClause>(DeclarationClause());
    assignEntity2->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::ASSIGN), "x");
    auto printEntity = std::make_shared<DeclarationClause>(DeclarationClause());
    printEntity->addDeclaration(QPSTokenType(QPSTokenType::QPSTypeInfo::PRINT), "y");

    qo.addClause(assignEntity1);
    qo.addClause(assignEntity2);

    auto t1 = QPSToken(QPSTokenType(QPSTokenType::QPSTypeInfo::SYNONYM), "x");
    auto t2 = QPSToken(QPSTokenType(QPSTokenType::QPSTypeInfo::SYNONYM), "y");

    auto pConstraint = std::make_shared<RelationshipClause>(QPSTokenType::QPSTypeInfo::PARENT, t1, QPSTokenType::QPSTypeInfo::STMT_REF, t2, QPSTokenType::QPSTypeInfo::STMT_REF);
    qo.addClause(pConstraint);

    // Apply QueryValidator to validate the QueryObject
    QueryValidator validator;
    std::vector<std::string> failedRules = validator.validateQuery(qo);

    // Ensure both SingleDeclarationRule and NoDeclarationRule violations are detected
    REQUIRE(failedRules.size() == 2);
    REQUIRE(std::find(failedRules.begin(), failedRules.end(), VALIDATION_RULE_SINGLE_DECLARATION) != failedRules.end());
    REQUIRE(std::find(failedRules.begin(), failedRules.end(), VALIDATION_RULE_NO_DECLARATION) != failedRules.end());
}

TEST_CASE("QueryValidator_ValidateQuery_EmptyQueryObject") {
    // Create an empty QueryObject
    IntermediateQuery qo;

    // Apply QueryValidator to validate the QueryObject
    QueryValidator validator;
    std::vector<std::string> failedRules = validator.validateQuery(qo);

    // Ensure no failed rules are returned for an empty QueryObject
    REQUIRE(failedRules.empty());
}

// ai-gen end