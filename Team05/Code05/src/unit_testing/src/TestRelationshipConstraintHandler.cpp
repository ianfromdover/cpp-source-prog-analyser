//
// Created by Alex on 12/2/2024.
//

#include "catch.hpp"
#include "qps/QueryPreprocessor/RelationshipConstraintComponent.h"
#include "qps/QueryPreprocessor/RelationshipConstraintHandler.h"

using namespace std;


TEST_CASE("relationship_handler_valid_syntax") {

    SECTION("Parent") {
        RelationshipConstraintHandler handler;
        std::string clause = "such that Parent(a,b)";
        shared_ptr<QueryComponent> component;
        REQUIRE_NOTHROW(component = handler.handle(clause));

        shared_ptr<RelationshipConstraintComponent> expected = make_shared<RelationshipConstraintComponent>(
                RelationshipConstraintComponent());
        expected->addArgument("a");
        expected->addArgument("b");

        shared_ptr<RelationshipConstraintComponent> actual = dynamic_pointer_cast<RelationshipConstraintComponent>(
                component);
        REQUIRE(actual != nullptr);
    }
    SECTION("Parent*") {
        RelationshipConstraintHandler handler;
        std::string clause = "such that Parent*(a,b)";
        shared_ptr<QueryComponent> component;
        REQUIRE_NOTHROW(component = handler.handle(clause));

        shared_ptr<RelationshipConstraintComponent> expected = make_shared<RelationshipConstraintComponent>(
                RelationshipConstraintComponent());
        expected->addArgument("a");
        expected->addArgument("b");

        shared_ptr<RelationshipConstraintComponent> actual = dynamic_pointer_cast<RelationshipConstraintComponent>(
                component);
        REQUIRE(actual != nullptr);
    }
}

TEST_CASE("relationship_invalid_syntax_throws") {
    SECTION("uppercase_such_that"){
        RelationshipConstraintHandler handler;
        std::string clause = "Such That Parent(a,b)";
        shared_ptr<QueryComponent> component;
        REQUIRE_THROWS(component = handler.handle(clause));
    }
    SECTION("invalid relationship"){
        RelationshipConstraintHandler handler;
        std::string clause = "such that invalid(a,b)";
        shared_ptr<QueryComponent> component;
        REQUIRE_THROWS(component = handler.handle(clause));
    }
    SECTION("invalid synonyms"){
        RelationshipConstraintHandler handler;
        std::string clause = "such that Parent(1,2)";
        shared_ptr<QueryComponent> component;
        //REQUIRE_THROWS(component = handler.handle(clause));
        //TODO: enable once implemented
    }
}
