//
// Created by Chua Bing Quan on 26/2/24.
//
#include "catch.hpp"
#include "../helper/AstTestProgramProducer.h"
#include "../helper/TokenizedTestProgramProducer.h"
#include "sp/parser/Parser.h"

inline TokenizedTestProgramProducer tokenizedPrograms = TokenizedTestProgramProducer();
inline AstTestProgramProducer astPrograms = AstTestProgramProducer();

std::string programToString(const std::shared_ptr<Program>& program) {
    std::string result;
    for (const auto& procedure : *program->getProcedures()) {
        result += procedure->toString();
    }
    return result;
}

bool isSameProgram(const std::shared_ptr<Program>& got, const std::shared_ptr<Program>& expect) {
    return programToString(got) == programToString(expect);
}

// Parser_TestZeroNestingLevel
TEST_CASE("Parser_TestAssignCallPrintRead") {
    const auto& tokens = tokenizedPrograms.createAssignCallPrintRead();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createAssignCallPrintRead()));
}

// Parser_TestSingleNestingLevel
TEST_CASE("Parser_TestIfElseWithStmtsBeforeAndInside") {
    const auto& tokens = tokenizedPrograms.createIfElseWithStmtsBeforeAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createIfElseWithStmtsBeforeAndInside()));
}

TEST_CASE("Parser_TestIfElseWithStmtsBeforeAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createIfElseWithStmtsBeforeAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createIfElseWithStmtsBeforeAfterAndInside()));
}

TEST_CASE("Parser_TestIfElseWithStmtsAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createIfElseWithStmtsAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createIfElseWithStmtsAfterAndInside()));
}

TEST_CASE("Parser_TestWhileWithStmtsBeforeAndInside") {
    const auto& tokens = tokenizedPrograms.createWhileWithStmtsBeforeAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createWhileWithStmtsBeforeAndInside()));
}

TEST_CASE("Parser_TestWhileWithStmtsBeforeAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createWhileWithStmtsBeforeAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createWhileWithStmtsBeforeAfterAndInside()));
}

TEST_CASE("Parser_TestWhileWithStmtsAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createWhileWithStmtsAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createWhileWithStmtsAfterAndInside()));
}

// Parser_TestDoubleNestingLevel
TEST_CASE("Parser_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    const auto& tokens = tokenizedPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside()));
}

TEST_CASE("Parser_TestIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside()));
}

TEST_CASE("Parser_TestIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside()));
}

TEST_CASE("Parser_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    const auto& tokens = tokenizedPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside()));
}

TEST_CASE("Parser_TestIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside()));
}

TEST_CASE("Parser_TestIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createIfElseWithNestedWhilePlusNestedStmtsAfterAndInside()));
}

TEST_CASE("Parser_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    const auto& tokens = tokenizedPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside()));
}

TEST_CASE("Parser_TestWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside()));
}

TEST_CASE("Parser_TestWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createWhileWithNestedIfElsePlusNestedStmtsAfterAndInside()));
}

TEST_CASE("Parser_TestWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    const auto& tokens = tokenizedPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAndInside()));
}

TEST_CASE("Parser_TestWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside()));
}

TEST_CASE("Parser_TestWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    const auto& tokens = tokenizedPrograms.createWhileWithNestedWhilePlusNestedStmtsAfterAndInside();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createWhileWithNestedWhilePlusNestedStmtsAfterAndInside()));
}

TEST_CASE("Parser_TestSequentialNestingChain") {
    const auto& tokens = tokenizedPrograms.createSequentialNestingChain();
    const auto& program = Parser(tokens).parse();
    REQUIRE(isSameProgram(program, astPrograms.createSequentialNestingChain()));
}
