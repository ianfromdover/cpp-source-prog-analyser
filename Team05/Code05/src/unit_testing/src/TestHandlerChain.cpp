//
// Created by Alex on 9/2/2024.
//


#include "catch.hpp"
#include "QPS/QueryPreprocessor/HandlerChain.h"

using namespace std;


TEST_CASE("handler_chain_valid_syntax") {

    HandlerChain handlerChain;
    REQUIRE_NOTHROW(handlerChain.handle("stmt a,b;Select a such that Parent (w, a)"));
    REQUIRE_NOTHROW(handlerChain.handle("stmt a,b;Select a such that Parent* (w,a)"));
}

TEST_CASE("handler_chain_invalid_syntax") {

    HandlerChain handlerChain;
    SECTION("invalid_design_entity")
        REQUIRE_THROWS(handlerChain.handle("invalid a,b;Select a such that Parent (w, a)"));

    SECTION("invalid_design_entity_synonym")
        REQUIRE_THROWS(handlerChain.handle("stmt 1,b;Select a such that Parent (w, a)"));

    SECTION("invalid_select_synonym")
        REQUIRE_THROWS(handlerChain.handle("stmt a,b;Select 1 such that Parent (w, a)"));

    SECTION("invalid_relationship_synonym")
        REQUIRE_THROWS(handlerChain.handle("stmt a,b;Select 1 such that Parent (1, a)"));

    SECTION("extra_semicolon")
        REQUIRE_THROWS(handlerChain.handle("stmt a,b;Select 1 such that Parent (1, a);"));

}
