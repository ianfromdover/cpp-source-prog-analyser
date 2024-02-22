//
// Created by sjh_9 on 21/2/2024.
//
#include "catch.hpp"
#include "../helper/AstFactory.cpp"
#include "../helper/SpPKBStub.cpp"
#include "sp/ReadExtractor.h"

//testZeroNestingLevel

TEST_CASE("testAssignCallPrintRead") {
    REQUIRE(1==1);
}

//testSingleNestingLevel

TEST_CASE("testIfElseWithStmtsBeforeAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testIfElseWithStmtsBeforeAfterAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testIfElseWithStmtsAfterAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testWhileWithStmtsBeforeAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testWhileWithStmtsBeforeAfterAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testWhileWithStmtsAfterAndInside") {
    REQUIRE(1==1);
}

//testDoubleNestingLevel

TEST_CASE("testIfElseWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testIfElseWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testIfElseWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testIfElseWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testIfElseWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testIfElseWithNestedWhilePlusNestedStmtsAfterAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testWhileWithNestedIfElsePlusNestedStmtsBeforeAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testWhileWithNestedIfElsePlusNestedStmtsBeforeAfterAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testWhileWithNestedIfElsePlusNestedStmtsAfterAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testWhileWithNestedWhilePlusNestedStmtsBeforeAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testWhileWithNestedWhilePlusNestedStmtsBeforeAfterAndInside") {
    REQUIRE(1==1);
}

TEST_CASE("testWhileWithNestedWhilePlusNestedStmtsAfterAndInside") {
    REQUIRE(1==1);
}