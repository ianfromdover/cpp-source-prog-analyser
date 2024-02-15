//
// Created by Alex on 12/2/2024.
//

#include "catch.hpp"
#include "qps/QueryPreprocessor/SelectComponent.h"
#include "qps/QueryPreprocessor/SelectHandler.h"

using namespace std;


TEST_CASE("select_handler_valid_syntax") {

    SelectHandler handler;
    std::string clause = "Select a";
    shared_ptr<QueryComponent> component;
    REQUIRE_NOTHROW(component = handler.handle(clause));

    shared_ptr<SelectComponent> expected = make_shared<SelectComponent>(SelectComponent());
    expected->setSynonym("a");

    shared_ptr<SelectComponent> actual = dynamic_pointer_cast<SelectComponent>(component);
    REQUIRE(actual != nullptr);
}

TEST_CASE("select_handler_invalid_syntax_throws") {
    SECTION("lowercase_select"){
        SelectHandler handler;
        std::string clause = "select a";
        shared_ptr<QueryComponent> component;
        REQUIRE_THROWS(component = handler.handle(clause));
    }
    SECTION("invalid synonym"){
        SelectHandler handler;
        std::string clause = "select 123";
        shared_ptr<QueryComponent> component;
        REQUIRE_THROWS(component = handler.handle(clause));
    }
}