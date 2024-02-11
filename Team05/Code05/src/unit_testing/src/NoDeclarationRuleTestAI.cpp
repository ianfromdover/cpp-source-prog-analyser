//
// Created by tohzh on 11/2/2024.
//

#include "TNode.h"

#include "catch.hpp"
using namespace std;

#include "catch.hpp"
#include "qps/query_validator/NoDeclarationRule.h" // Include the header file for SingleDeclarationRule
#include "qps/query_elements/QueryObject.h"
#include "qps/query_elements/constraint_argument/StatementEntity.h"
#include "qps/query_elements/constraint_argument/PrintEntity.h"
#include "qps/query_elements/constraint/ParentConstraint.h"

TEST_CASE("noDeclarationRule_AllEntitiesDeclaredOnce_returnsNoString") {
    // Create a QueryObject with all entities declared exactly once
    QueryObject qo;
    // Add entity declarations
    auto *e1 = new StatementEntity("q");
    auto *e2 = new PrintEntity("s");
    qo.addDeclaration(*e1);
    qo.addDeclaration(*e2);
    // Add a constraint with entities as arguments
    qo.addConstraint(*new ParentConstraint(e1, e2));
    NoDeclarationRule rule;
    REQUIRE(rule.validate(qo).empty());
}

TEST_CASE("noDeclarationRule_Missing2EntityDeclaration_returnsString") {
    // Create a QueryObject with a missing entity declaration
    QueryObject qo;
    // Add entity declaration
    auto *e1 = new StatementEntity("q");
    auto *e2 = new PrintEntity("l");
    // Add a constraint with an undeclared entity as an argument
    auto* p = new ParentConstraint(e1, e2); // e2 is not declared in qo
    qo.addConstraint(*p);
    NoDeclarationRule rule;

    REQUIRE(rule.validate(qo) == VALIDATION_RULE_NO_DECLARATION);
}

TEST_CASE("noDeclarationRule_Missing1EntityDeclaration_returnsString") {
    // Create a QueryObject with a missing entity declaration
    QueryObject qo;
    // Add entity declaration
    auto *e1 = new StatementEntity("g");
    auto *e2 = new PrintEntity("f");
    qo.addDeclaration(*e1);
    // Add a constraint with an undeclared entity as an argument
    auto* p = new ParentConstraint(e1, e2); // e2 is not declared in qo
    qo.addConstraint(*p);
    NoDeclarationRule rule;

    REQUIRE(rule.validate(qo) == VALIDATION_RULE_NO_DECLARATION);
}



TEST_CASE("noDeclarationRule_MultipleUsageOfSameEntity_returnsString") {
    // Create a QueryObject with multiple usage of the same entity
    QueryObject qo;
    // Add entity declaration
    auto *e1 = new StatementEntity("e");
    auto *e2 = new PrintEntity("e2");
    qo.addDeclaration(*e1);
    // Add a constraint with multiple occurrences of the same entity as arguments
    auto* p = new ParentConstraint(e2, e2); // e1 is assigned again
    qo.addConstraint(*p);
    NoDeclarationRule rule;
    REQUIRE(rule.validate(qo) == VALIDATION_RULE_NO_DECLARATION);
}

TEST_CASE("noDeclarationRule_EmptyQueryObjectPass_returnsNoString") {
    // Create an empty QueryObject
    QueryObject qo;
    NoDeclarationRule rule;
    REQUIRE(rule.validate(qo).empty());
}

TEST_CASE("noDeclarationRule_EntitiesUsedAsArgumentsNotDeclared_returnsString") {
    // Create a QueryObject with entities used as arguments but not declared
    QueryObject qo;
    // Add a constraint with an entity as an argument without declaration
    auto *e1 = new StatementEntity("q");
    auto *e2 = new StatementEntity("r");
    ParentConstraint p = ParentConstraint(e1, e2); // e1 and e2 is not declared in qo
    qo.addConstraint(p);
    NoDeclarationRule rule;
    REQUIRE(rule.validate(qo) == VALIDATION_RULE_NO_DECLARATION);
}