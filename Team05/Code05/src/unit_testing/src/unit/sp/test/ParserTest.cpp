//
// Created by Chua Bing Quan on 26/2/24.
//
#include "catch.hpp"
#include "../helper/TokenProcedures.cpp"
#include "sp/parser/Parser.h"

// Parser_TestZeroNestingLevel

std::string programToString(const Program& program) {
    std::string result;
    for (const auto& procedure : *program) {
        result += procedure->toString();
    }
    return result;
}

TEST_CASE("Parser_TestAssignCallReadPrint") {
    auto tokens = TokenProcedures::createAssignCallReadPrintTokens();
    const auto program = Parser(tokens).parse();
    REQUIRE(programToString(program) == TokenProcedures::createAssignCallReadPrint()->toString());
}

// Parser_TestSingleNestingLevel

TEST_CASE("Parser_TestIfElseWithStmtsBeforeAndInside") {
    auto tokens = TokenProcedures::createIfElseWithStmtsBeforeAndInsideTokens();
    const auto program = Parser(tokens).parse();
    REQUIRE(programToString(program) == TokenProcedures::createIfElseWithStmtsBeforeAndInside()->toString());
}

// Parser_TestDoubleNestingLevel

TEST_CASE("Parser_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    auto tokens = TokenProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInsideTokens();
    const auto program = Parser(tokens).parse();
    REQUIRE(programToString(program) == TokenProcedures::createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside()->toString());
}