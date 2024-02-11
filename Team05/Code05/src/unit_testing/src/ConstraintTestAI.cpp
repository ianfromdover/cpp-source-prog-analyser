//
// Created by tohzh on 10/2/2024.
//

#include "TNode.h"

#include "catch.hpp"
using namespace std;

#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "qps/query_elements/constraint/Constraint.h"
#include "qps/query_elements/constraint/FollowsConstraint.h"
#include "qps/query_elements/constraint/FollowsTConstraint.h"
#include "qps/query_elements/constraint/ParentConstraint.h"
#include "qps/query_elements/constraint/ParentTConstraint.h"

#include "qps/query_elements/constraint_argument/StatementEntity.h"
#include "qps/query_elements/constraint_argument/ReadEntity.h"
#include "qps/query_elements/constraint_argument/PrintEntity.h"
#include "qps/query_elements/constraint_argument/AssignEntity.h"
#include "qps/query_elements/constraint_argument/CallEntity.h"
#include "qps/query_elements/constraint_argument/IfEntity.h"
#include "qps/query_elements/constraint_argument/WhileEntity.h"
#include "qps/query_elements/constraint_argument/IntegerArgument.h."
#include "qps/query_elements/constraint_argument/WildCard.h"

// ai-gen start(gpt, 1, e)
// prompt: https://chat.openai.com/share/f965b299-102c-4b5b-a9df-e2e1a17ded54
TEST_CASE("dynamic_cast_inheritance_relationship_constraint") {
    auto* s = new StatementEntity("q");
    auto* r = new ReadEntity("f");
    FollowsConstraint follows_constraint(s, r);
    FollowsTConstraint follows_t_constraint(s, r);
    ParentConstraint parent_constraint(s, r);
    ParentTConstraint parent_t_constraint(s, r);

    SECTION("FollowsConstraint is a RelationshipConstraint") {
        Constraint* constraint_ptr = &follows_constraint;
        REQUIRE(dynamic_cast<RelationshipConstraint*>(constraint_ptr) != nullptr);
    }

    SECTION("FollowsTConstraint is a RelationshipConstraint") {
        Constraint* constraint_ptr = &follows_t_constraint;
        REQUIRE(dynamic_cast<RelationshipConstraint*>(constraint_ptr) != nullptr);
    }

    SECTION("ParentConstraint is a RelationshipConstraint") {
        Constraint* constraint_ptr = &parent_constraint;
        REQUIRE(dynamic_cast<RelationshipConstraint*>(constraint_ptr) != nullptr);
    }

    SECTION("ParentTConstraint is a RelationshipConstraint") {
        Constraint* constraint_ptr = &parent_t_constraint;
        REQUIRE(dynamic_cast<RelationshipConstraint*>(constraint_ptr) != nullptr);
    }
    delete s;
    delete r;
}


TEST_CASE("getConstraintClass_returns_CONSTRAINT_CLASS_RELATIONSHIP") {
    auto* s = new StatementEntity("o");
    auto* r = new ReadEntity("p");

    SECTION("FollowsConstraint") {
    FollowsConstraint follows_constraint(s, r);
    REQUIRE(follows_constraint.getConstraintClass() == CONSTRAINT_CLASS_RELATIONSHIP);
    }

    SECTION("FollowsTConstraint") {
    FollowsTConstraint follows_t_constraint(s, r);
    REQUIRE(follows_t_constraint.getConstraintClass() == CONSTRAINT_CLASS_RELATIONSHIP);
    }

    SECTION("ParentConstraint") {
    ParentConstraint parent_constraint(s, r);
    REQUIRE(parent_constraint.getConstraintClass() == CONSTRAINT_CLASS_RELATIONSHIP);
    }

    SECTION("ParentTConstraint") {
    ParentTConstraint parent_t_constraint(s, r);
    REQUIRE(parent_t_constraint.getConstraintClass() == CONSTRAINT_CLASS_RELATIONSHIP);
    }

    delete s;
    delete r;
}


TEST_CASE("InitializeConstraint_with_StatementReference_subclasses") {
    // All possible StatementReference subclasses
    std::vector<StatementReference*> entities;

    entities.push_back(new StatementEntity("q"));
    entities.push_back(new ReadEntity("w"));
    entities.push_back(new PrintEntity("e"));
    entities.push_back(new AssignEntity("r"));
    entities.push_back(new CallEntity("t"));
    entities.push_back(new IfEntity("y"));
    entities.push_back(new WhileEntity("u"));
    entities.push_back(new IntegerArgument);
    entities.push_back(new WildCard);

    SECTION("FollowsConstraint") {
        // Pairwise testing for FollowsConstraint initialization
        for (auto it1 = std::begin(entities); it1 != std::end(entities); ++it1) {
            for (auto it2 = it1 + 1; it2 != std::end(entities); ++it2) {
                REQUIRE_NOTHROW(FollowsConstraint(*it1, *it2));
            }
        }
    }

    SECTION("FollowsTConstraint") {
        // Pairwise testing for FollowsTConstraint initialization
        for (auto it1 = std::begin(entities); it1 != std::end(entities); ++it1) {
            for (auto it2 = it1 + 1; it2 != std::end(entities); ++it2) {
                REQUIRE_NOTHROW(FollowsTConstraint(*it1, *it2));
            }
        }
    }

    SECTION("ParentConstraint") {
        // Pairwise testing for ParentConstraint initialization
        for (auto it1 = std::begin(entities); it1 != std::end(entities); ++it1) {
            for (auto it2 = it1 + 1; it2 != std::end(entities); ++it2) {
                REQUIRE_NOTHROW(ParentConstraint(*it1, *it2));
            }
        }
    }

    SECTION("ParentTConstraint") {
        // Pairwise testing for ParentTConstraint initialization
        for (auto it1 = std::begin(entities); it1 != std::end(entities); ++it1) {
            for (auto it2 = it1 + 1; it2 != std::end(entities); ++it2) {
                REQUIRE_NOTHROW(ParentTConstraint(*it1, *it2));
            }
        }
    }

    // Clean up dynamically allocated memory
    for (auto* entity : entities) {
        delete entity;
    }
}

// ai-gen end