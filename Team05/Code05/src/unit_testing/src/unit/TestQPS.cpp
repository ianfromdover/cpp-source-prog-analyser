// include "qps/yourClass.h"
// include "qps/yourClass.cpp"

#include "catch.hpp"
#include "qps/QPS.h"
#include "qps/query_evaluator/stub/QueryPKBStub.h"

using namespace std;

// Unit Tests for QPS
TEST_CASE("[TestQPS] Replace with your unit tests") {
    SECTION("Test a single aspect of the features") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        QPS qps(pkb);

        std::string queryStr = "stmt s; Select s such that Follows(1, s)";
        std::vector<std::string> results = qps.evaluate(queryStr);
        std::vector<std::string> expected = {"1", "2", "3"};

        REQUIRE(results == expected);
    }
}

TEST_CASE("[TestQPS] Syntax Error Tests"){
    SECTION("only declarations"){
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        QPS qps(pkb);

        std::string queryStr = "stmt s;";
        std::vector<std::string> results = qps.evaluate(queryStr);
        std::vector<std::string> expected = {"SyntaxError"};

        REQUIRE(results == expected);
    }
}
