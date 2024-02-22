// include "qps/yourClass.h"
// include "qps/yourClass.cpp"

#include <utility>

#include "catch.hpp"
#include "qps/QPS.h"
#include "qps/query_evaluator/stub/QueryPKBStub.h"

using namespace std;

std::vector<std::string> testHelper(std::string queryStr);

// Unit Tests for QPS
TEST_CASE("[TestQPS] Replace with your unit tests") {
    SECTION("no constraints") {
        std::string queryStr = "stmt s; Select s";
        std::vector<std::string> expected = {"1", "2", "3"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
}

TEST_CASE("[TestQPS] Syntax Error Tests"){
    SECTION("only declarations"){
        std::string queryStr = "stmt s;";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("only declarations and relationship"){
        std::string queryStr = "stmt s; such that Follows(1, s)";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("only declarations and variable pattern"){
        std::string queryStr = "assign a; such that pattern a (_, _\"x\"_)";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("only declarations and constant pattern"){
        std::string queryStr = "assign a; such that pattern a (_, _\"1\"_)";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
}

TEST_CASE("[TestQPS] Semantic Error Tests"){
    SECTION("undeclared synonym"){
        std::string queryStr = "stmt s; Select s such that Follows(1, a)";
        std::vector<std::string> expected = {"SemanticError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("double declaration"){
        std::string queryStr = "stmt s,s; Select s such that Follows(1, a)";
        std::vector<std::string> expected = {"SemanticError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("pattern assign synonym"){
        std::string queryStr = "assign a;stmt s; Select a such that pattern s (_, _\"x+y\"_)";
        std::vector<std::string> expected = {"SemanticError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("parent with invalid argument"){
        std::string queryStr = "variable v;stmt s;Select s such that Parent(v, 2)";
        std::vector<std::string> expected = {"SemanticError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("modifies invalid argument"){
        std::string queryStr = "stmt s;variable v; Select s such that Modifies(_, s)";
        std::vector<std::string> expected = {"SemanticError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("modifies wildcard argument"){
        std::string queryStr = "stmt s;variable v; Select s such that Modifies(_, v)";
        std::vector<std::string> expected = {"SemanticError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("uses wildcard argument"){
        std::string queryStr = "stmt s;variable v; Select s such that Uses(_, v)";
        std::vector<std::string> expected = {"SemanticError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("pattern invalid argument"){
        std::string queryStr = "assign a;stmt s; Select s such that pattern a (s, _\"x+y\"_)";
        std::vector<std::string> expected = {"SemanticError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
}

TEST_CASE("[TestQPS] No Constraints"){
    SECTION("statements") {
        std::string queryStr = "stmt s; Select s";
        std::vector<std::string> expected = {"1", "2", "3"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("read statements") {
        std::string queryStr = "read r; Select r";
        std::vector<std::string> expected = {"1", "2", "3"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
}

TEST_CASE("[TestQPS] Single Constraints"){
    SECTION("follows") {
        std::string queryStr = "stmt s; Select s such that Follows(1, s)";
        std::vector<std::string> expected = {"1", "2", "3"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("follows T") {
        std::string queryStr = "stmt s; Select s such that Follows*(1, s)";
        std::vector<std::string> expected = {"3", "4", "5"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("parents") {
        std::string queryStr = "stmt s; Select s such that Parent(1, s)";
        std::vector<std::string> expected = {"a", "b", "c", "f"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("parents T") {
        std::string queryStr = "stmt s; Select s such that Parent*(1, s)";
        std::vector<std::string> expected = {"c", "d", "e"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("modifies"){
        std::string queryStr = "stmt s; variable v; Select s such that Modifies(s, v)";
        std::vector<std::string> expected = {"2","3","4"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);

    }
    SECTION("uses"){
        std::string queryStr = "stmt s; variable v; Select s such that Uses(s, v)";
        std::vector<std::string> expected = {"2", "4", "3"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("pattern"){
        std::string queryStr = "assign a; Select a such that pattern a (_, _\"1\"_)";
        std::vector<std::string> expected = {"c","d","e","f"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
}

std::vector<std::string> testHelper(std::string queryStr){
    std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
    QPS qps(pkb);
    return qps.evaluate(std::move(queryStr));
}
