//
// Created by Chua Bing Quan on 26/2/24.
//
#include "catch.hpp"
#include "../helper/TokenProcedures.cpp"
#include "sp/Parser.h"
#include "sp/SourceProcessor.h"

//Parser_TestSingleNestingLevel

TEST_CASE("Parser_TestIfElseWithStmtsBeforeAndInside") {
    auto tokens = TokenProcedures::createIfElseWithStmtsBeforeAndInsideTokens();
    const auto program = Parser(tokens).parse();
    std::string result;
    for (const auto& procedure : *program) {
        result += procedure->toString();
    }
    REQUIRE(result == TokenProcedures::createIfElseWithStmtsBeforeAndInside()->toString());
}