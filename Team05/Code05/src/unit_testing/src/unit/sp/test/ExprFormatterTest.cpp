//
// Created by Chua Bing Quan on 6/3/24.
//
#include "catch.hpp"
#include "sp/api/formatter/ExprFormatter.h"
#include "sp/exception/FormatterException.h"

TEST_CASE("ExprFormatter_TestFormatVariable") {
    SECTION("Variable") {
        REQUIRE(ExprFormatter::format("x") == "x");
    }
    SECTION("Nested variable") {
        REQUIRE(ExprFormatter::format("(x)") == "x");
    }
}

TEST_CASE("ExprFormatter_TestFormatInteger") {
    SECTION("Integer") {
        REQUIRE(ExprFormatter::format("1") == "1");
    }
    SECTION("Nested integer") {
        REQUIRE(ExprFormatter::format("(1)") == "1");
    }
}

TEST_CASE("ExprFormatter_TestFormatBinaryExpression") {
    SECTION("Addition") {
        REQUIRE(ExprFormatter::format("x + 1") == "( x + 1 )");
    }
    SECTION("Subtraction") {
        REQUIRE(ExprFormatter::format("x - 1") == "( x - 1 )");
    }
    SECTION("Multiplication") {
        REQUIRE(ExprFormatter::format("x * 1") == "( x * 1 )");
    }
    SECTION("Division") {
        REQUIRE(ExprFormatter::format("x / 1") == "( x / 1 )");
    }
    SECTION("Modulo") {
        REQUIRE(ExprFormatter::format("x % 1") == "( x % 1 )");
    }
}

TEST_CASE("ExprFormatter_TestFormatNestedExpression") {
    SECTION("Implicit nesting") {
        REQUIRE(ExprFormatter::format("x + 1 * 2") == "( x + ( 1 * 2 ) )");
    }
    SECTION("Explicit nesting") {
        REQUIRE(ExprFormatter::format("(x + 1) * 2") == "( ( x + 1 ) * 2 )");
    }
}

TEST_CASE("ExprFormatter_TestInvalidInputs") {
    SECTION("Empty String") {
        REQUIRE_THROWS_WITH(ExprFormatter::format(""), InvalidExprString::ERR_MSG);
    }
    SECTION("Single Space") {
        REQUIRE_THROWS_WITH(ExprFormatter::format(" "), InvalidExprString::ERR_MSG);
    }
    SECTION("Empty Parenthesis") {
        REQUIRE_THROWS_WITH(ExprFormatter::format("()"), InvalidExprString::ERR_MSG);
    }
    SECTION("Space in Parenthesis") {
        REQUIRE_THROWS_WITH(ExprFormatter::format("( )"), InvalidExprString::ERR_MSG);
    }
    SECTION("Statement without semicolon") {
        REQUIRE_THROWS_WITH(ExprFormatter::format("print x"), InvalidExprString::ERR_MSG);
    }
    SECTION("Statement with semicolon") {
        REQUIRE_THROWS_WITH(ExprFormatter::format("print x;"), InvalidExprString::ERR_MSG);
    }
    SECTION("Single semicolon") {
        REQUIRE_THROWS_WITH(ExprFormatter::format(";"), InvalidExprString::ERR_MSG);
    }
    SECTION("Trailing statement after semicolon") {
        REQUIRE_THROWS_WITH(ExprFormatter::format("x + 1; y = x + 2;"), InvalidExprString::ERR_MSG);
    }
    SECTION("Malformed expression") {
        REQUIRE_THROWS_WITH(ExprFormatter::format("(x"), InvalidExprString::ERR_MSG);
    }
}

