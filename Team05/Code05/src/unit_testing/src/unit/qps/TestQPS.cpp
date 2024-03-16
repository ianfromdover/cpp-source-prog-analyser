#include <utility>
#include <iostream>

#include "catch.hpp"
#include "qps/QPS.h"
#include "query_evaluator/stub/QueryPKBStub.h"

using namespace std;

std::vector<std::string> testHelper(std::string queryStr);

TEST_CASE("[TestQPS] Replace with your unit tests") {
    SECTION("no constraints") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setStatement({{"1"}, {"2"}, {"3"}});
        QPS qps(pkb);

        std::string queryStr = "stmt s; Select s";
        std::vector<std::string> expected = {"1", "2", "3"};

        REQUIRE(qps.evaluate(std::move(queryStr)) == expected);

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
    SECTION("missing arguments"){
        std::string queryStr = "stmt s; Select s such that Follows()";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("missing first arguments"){
        std::string queryStr = "stmt s; Select s such that Parent(,1)";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("missing second arguments"){
        std::string queryStr = "stmt s; Select s such that Parent(s,)";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("missing argument left bracket"){
        std::string queryStr = "stmt s; Select s such that Parent 1,s)";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("missing argument right bracket"){
        std::string queryStr = "stmt s; Select s such that Parent (1,s";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("missing argument seperator"){
        std::string queryStr = "stmt s; Select s such that Parent (1 s)";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("semicolon at end of query"){
        std::string queryStr = "stmt s; Select s such that Parent (1, s);";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("integer with leading zero"){
        std::string queryStr = "stmt s; Select s such that Parent (01, s);";
        std::vector<std::string> expected = {"SyntaxError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("AI generated queries"){
        std::vector<std::string> queryLs = {
                R"(Select stmt s such that Follows(s1, s2))",
                R"(Select stmt s such that Parent*(s1, s2))",
                R"(Select variable v such that InvalidRel(v, s))",
                R"(Select assign a such that Modifies(1, "x"))",
                R"(Select assign a pattern InvalidPattern(_, "_"))",
                R"(Select stmt s such that Uses("1", s))",
                R"(Select stmt suchthat Follows(s1, s2))",
                R"(Select stmt s that Follows*(s1, s2))",
                R"(Select variable v such that Parent(s1, s2))",
                R"(Select assign a suchthat Modifies(s, "x"))",
                R"(Select stmt s pattern InvalidPattern(_, "_"))",
                R"(Select stmt s such that InvalidRel(s1, s2))",
                R"(Select stmt suchthat Follows*(s1, s2))",
                R"(Select stmt s such that Follows*(1, s2))",
                R"(Select variable v such that Uses("1", s))",
                R"(Select assign a suchthat Modifies(s1, "x"))",
                R"(Select stmt s pattern InvalidPattern("x", "_"))",
                R"(Select stmt s suchthat Follows(s1, s2)",
                R"(Select stmt s such that Parent*("x", s))",
                R"(Select variable v suchthat Modifies(1, "x"))",
                R"(Select assign a such that Modifies(s1, s2))",
                R"(Select stmt s pattern InvalidPattern(s, "_"))",
                R"(Select stmt s such that Uses(1, s))",
                R"(Select stmt s such that Follows*(_, s2))",
                R"(Select variable v such that Uses(1, s))",
                R"(Select assign a suchthat Modifies(s1, 1))",
                R"(Select stmt s pattern InvalidPattern(s1, "_"))",
                R"(Select stmt s suchthat Follows(s1, s2)))",
                R"(Select stmt s such that Parent*(s1, "x"))",
                R"(Select stmt s suchthat Follows(s1, s2)))",
                R"(Select stmt s suchthat Follows*(s1, s2))",
                R"(Select stmt s such that Parent*(s1, s2)",
                R"(Select variable v suchthat InvalidRel(v, s)",
                R"(Select assign a suchthat Modifies(1, "x")",
                R"(Select assign a suchthat Modifies(s, "x"))",
                R"(Select stmt s pattern InvalidPattern(_, "_"))",
                R"(Select stmt suchthat Follows(s1, s2)",
                R"(Select variable v suchthat Uses("1", s))",
                R"(Select assign a suchthat Modifies(s1, "x"))",
                R"(Select stmt s pattern InvalidPattern(s, "_"))",
                R"(Select stmt s suchthat Uses(1, s))",
                R"(Select variable v such that Uses(1, s))",
                R"(Select assign a suchthat Modifies(s1, 1))",
                R"(Select stmt s suchthat Follows(s1, s2)))",
                R"(Select stmt s suchthat Parent*(s1, "x"))"
        };

        for (auto & s : queryLs){
            std::vector<std::string> expected = {"SyntaxError"};
            std::vector<std::string> results = testHelper(s);
            REQUIRE(results == expected);
        }
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
        std::vector<std::string> expected = {"SyntaxError"}; // TODO: should be semantic error

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
        std::vector<std::string> expected = {"SyntaxError"}; // TODO: should be semantic error

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("only select"){
        std::string queryStr = "Select s";
        std::vector<std::string> expected = {"SemanticError"};

        std::vector<std::string> results = testHelper(queryStr);
        REQUIRE(results == expected);
    }
    SECTION("AI generated queries"){
        std::vector<std::string> queryLs = {
                R"(Select s pattern a(v, _))",
                R"(Select s such that Parent*(a, b))",
                R"(variable v; Select s such that Uses(_, v))"
//                R"()"
        };

        for (auto & s : queryLs){
            std::vector<std::string> expected = {"SemanticError"};
            std::vector<std::string> results = testHelper(s);
            std::cout << s << std::endl;
            REQUIRE(results == expected);
        }

    }
}

TEST_CASE("[TestQPS] No Constraints"){
    SECTION("statements") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setStatement({{"1"}, {"2"}, {"3"}});
        QPS qps(pkb);

        std::string queryStr = "stmt s; Select s";
        std::vector<std::string> expected = {"1", "2", "3"};

        REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
    }
    SECTION("read statements") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setRead({{"1"}, {"2"}, {"3"}});
        QPS qps(pkb);

        std::string queryStr = "read r; Select r";
        std::vector<std::string> expected = {"1", "2", "3"};

        REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
    }

    SECTION("print statements") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setPrint({{"1"}, {"2"}, {"3"}});
        QPS qps(pkb);

        std::string queryStr = "print r; Select r";
        std::vector<std::string> expected = {"1", "2", "3"};

        REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
    }

    SECTION("if statements") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setIf({{"1"}, {"2"}, {"3"}});
        QPS qps(pkb);

        std::string queryStr = "if r; Select r";
        std::vector<std::string> expected = {"1", "2", "3"};

        REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
    }

    SECTION("while statements") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setWhile({{"1"}, {"2"}, {"3"}});
        QPS qps(pkb);

        std::string queryStr = "while r; Select r";
        std::vector<std::string> expected = {"1", "2", "3"};

        REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
    }

    SECTION("procedure statements") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setProcedure({{"a", "a"}, {"b", "b"}, {"c", "c"}});
        QPS qps(pkb);

        std::string queryStr = "procedure r; Select r";
        std::vector<std::string> expected = {"a", "b", "c"};

        REQUIRE(qps.evaluate(std::move(queryStr)) == expected);

    }

    SECTION("variable statements") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setVar({{"1", "a"}, {"2", "b"}, {"3", "c"}});
        QPS qps(pkb);

        std::string queryStr = "variable r; Select r";
        std::vector<std::string> expected = {"a", "b", "c"};

        REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
    }

    SECTION("constant statements") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setConst({{"1", "a"}, {"2", "b"}, {"3", "c"}});
        QPS qps(pkb);

        std::string queryStr = "constant r; Select r";
        std::vector<std::string> expected = {"a", "b", "c"};

        REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
    }


}

TEST_CASE("[TestQPS] Multiple Constraints"){
    SECTION("follows pattern"){
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setFollows({{"1", "2"}, {"1", "3"}, {"1", "4"}, {"2", "7"}});
        pkb->setStatement({{"1"}, {"2"}, {"3"}, {"4"}, {"7"}});
        pkb->setPatternAsgn({{"1","x=c"}, {"2","x=k"}, {"3","y=c"}, {"4","y=k"}, {"7","z=i"}});
        QPS qps(pkb);

        SECTION("both non-empty"){
            std::string queryStr = "assign a;stmt s,s1; Select s1 such that Follows(s, 7) pattern a (_,_)";
            std::vector<std::string> expected = {"1", "2", "3", "4", "7"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("empty relationship clause"){
            std::string queryStr = "assign a;stmt s,s1; Select s1 such that Follows(1, 7) pattern a (_,_)";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("empty pattern clause"){
            std::string queryStr = "assign a;stmt s,s1; Select s1 such that Follows(s, 7) pattern a (\"k\",_)";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("both empty"){
            std::string queryStr = "assign a;stmt s,s1; Select s1 such that Follows(1, 7) pattern a (\"k\",_)";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("both wildcard"){
            std::string queryStr = "assign a;stmt s,s1; Select a such that Follows(_, _) pattern a (_,_)";
            std::vector<std::string> expected = {"1", "2", "3", "4", "7"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("common synonym"){
            std::string queryStr = "assign a;stmt s,s1; Select a such that Follows(1, a) pattern a (\"x\",_)";
            std::vector<std::string> expected = {"2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("common synonym1"){
            std::string queryStr = "assign a;stmt s,s1; Select a such that Follows(1, a) pattern a (_,\"k\")";
            std::vector<std::string> expected = {"2","4"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
    }
}

TEST_CASE("[TestQPS] Single Constraints") {
    SECTION("follows") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setFollows({{"1", "2"},
                         {"1", "3"},
                         {"1", "4"},
                         {"2", "7"}});
        pkb->setStatement({{"1"},
                           {"2"},
                           {"3"},
                           {"4"},
                           {"7"}});
        QPS qps(pkb);

        SECTION("right synonym") {
            std::string queryStr = "stmt s; Select s such that Follows(1, s)";
            std::vector<std::string> expected = {"2", "3", "4"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }

        SECTION("left synonym") {
            std::string queryStr = "stmt s; Select s such that Follows(s, 7)";
            std::vector<std::string> expected = {"2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }

        SECTION("both synonym") {
            std::string queryStr = "stmt s,s1; Select s such that Follows(s, s1)";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }

        SECTION("left wildcard") {
            std::string queryStr = "stmt s; Select s such that Follows(_, s)";
            std::vector<std::string> expected = {"2", "3", "4", "7"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }

        SECTION("right wildcard") {
            std::string queryStr = "stmt s,s1; Select s such that Follows(s, _)";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }

        SECTION("empty result") {
            std::string queryStr = "stmt s,s1; Select s such that Follows(1, 5)";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
    }
    SECTION("follows T") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setFollowsT({{"1", "2"},
                          {"1", "3"},
                          {"1", "4"},
                          {"2", "7"}});
        pkb->setStatement({{"1"},
                           {"2"},
                           {"3"},
                           {"4"},
                           {"7"}});
        QPS qps(pkb);

        SECTION("right synonym") {
            std::string queryStr = "stmt s; Select s such that Follows*(1, s)";
            std::vector<std::string> expected = {"2", "3", "4"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }SECTION("left synonym") {
            std::string queryStr = "stmt s; Select s such that Follows*(s, 7)";
            std::vector<std::string> expected = {"2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }SECTION("both synonym") {
            std::string queryStr = "stmt s,s1; Select s such that Follows*(s, s1)";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }SECTION("left wildcard") {
            std::string queryStr = "stmt s; Select s such that Follows*(_, s)";
            std::vector<std::string> expected = {"2", "3", "4", "7"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }SECTION("right wildcard") {
            std::string queryStr = "stmt s,s1; Select s such that Follows*(s, _)";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }SECTION("both wildcard") {
            std::string queryStr = "stmt s,s1; Select s such that Follows*(_, _)";
            std::vector<std::string> expected = {"1", "2", "3", "4", "7"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }SECTION("empty result") {
            std::string queryStr = "stmt s,s1; Select s such that Follows*(1, 5)";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
    }

    SECTION("parents") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setParent({{"1", "2"},
                          {"1", "3"},
                          {"1", "4"},
                          {"2", "7"}});
        pkb->setStatement({{"1"},
                           {"2"},
                           {"3"},
                           {"4"},
                           {"7"}});
        QPS qps(pkb);

        SECTION("right synonym") {
            std::string queryStr = "stmt s; Select s such that Parent(1, s)";
            std::vector<std::string> expected = {"2", "3", "4"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("left synonym") {
            std::string queryStr = "stmt s; Select s such that Parent(s, 7)";
            std::vector<std::string> expected = {"2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("both synonym") {
            std::string queryStr = "stmt s,s1; Select s such that Parent(s, s1)";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("left wildcard") {
            std::string queryStr = "stmt s; Select s such that Parent(_, s)";
            std::vector<std::string> expected = {"2", "3", "4", "7"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("right wildcard") {
            std::string queryStr = "stmt s,s1; Select s such that Parent(s, _)";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("both wildcard") {
            std::string queryStr = "stmt s,s1; Select s such that Parent(_, _)";
            std::vector<std::string> expected = {"1", "2", "3", "4", "7"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("empty result") {
            std::string queryStr = "stmt s,s1; Select s such that Parent(1, 5)";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
    }

    SECTION("parents T") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setParentT({{"1", "2"},
                        {"1", "3"},
                        {"1", "4"},
                        {"2", "7"}});
        pkb->setStatement({{"1"},
                           {"2"},
                           {"3"},
                           {"4"},
                           {"7"}});
        QPS qps(pkb);

        SECTION("right synonym") {
            std::string queryStr = "stmt s; Select s such that Parent*(1, s)";
            std::vector<std::string> expected = {"2", "3", "4"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("left synonym") {
            std::string queryStr = "stmt s; Select s such that Parent*(s, 7)";
            std::vector<std::string> expected = {"2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("both synonym") {
            std::string queryStr = "stmt s,s1; Select s such that Parent*(s, s1)";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("left wildcard") {
            std::string queryStr = "stmt s; Select s such that Parent*(_, s)";
            std::vector<std::string> expected = {"2", "3", "4", "7"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("right wildcard") {
            std::string queryStr = "stmt s,s1; Select s such that Parent*(s, _)";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("both wildcard") {
            std::string queryStr = "stmt s,s1; Select s such that Parent*(_, _)";
            std::vector<std::string> expected = {"1", "2", "3", "4", "7"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("empty result") {
            std::string queryStr = "stmt s,s1; Select s such that Parent*(1, 5)";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
    }

    SECTION("modifies"){
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setModifies({{"1", "v"},
                         {"1", "k"},
                         {"1", "c"},
                         {"2", "k"}});
        pkb->setStatement({{"1"},
                           {"2"},
                           {"3"},
                           {"4"},
                           {"7"}});
        pkb->setVar({{"1","v"},
                          {"1","k"},
                          {"2","c"},
                          {"2","i"}});
        QPS qps(pkb);

        SECTION("both synonym") {
            std::string queryStr = "stmt s; variable v; Select s such that Modifies(s, v)";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("right synonym select var") {
            std::string queryStr = "stmt s; variable v; Select v such that Modifies(1, v)";
            std::vector<std::string> expected = {"c", "k", "v"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("right synonym select stmt") {
            std::string queryStr = "stmt s; variable v; Select s such that Modifies(1, v)";
            std::vector<std::string> expected = {"1", "2", "3", "4", "7"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("left synonym right wildcard") {
            std::string queryStr = "stmt s; variable v; Select s such that Modifies(s, _)";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("left synonym right quoted") {
            std::string queryStr = "stmt s; variable v; Select s such that Modifies(s, \"k\")";
            std::vector<std::string> expected = {"1", "2"};

            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
    }
    SECTION("uses"){
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setUses({{"1", "v"},
                          {"1", "k"},
                          {"1", "c"},
                          {"2", "k"}});
        pkb->setStatement({{"1"},
                           {"2"},
                           {"3"},
                           {"4"},
                           {"7"}});
        pkb->setVar({{"1","v"},
                     {"1","k"},
                     {"2","c"},
                     {"2","i"}});
        QPS qps(pkb);

        SECTION("both synonym") {
            std::string queryStr = "stmt s; variable v; Select s such that Uses(s, v)";
            std::vector<std::string> expected = {"1", "2"};
            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("left int right synonym") {
            std::string queryStr = "stmt s; variable v; Select v such that Uses(1, v)";
            std::vector<std::string> expected = {"c", "k", "v"};
            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);

            queryStr = "stmt s; variable v; Select v such that Uses(5, v)";
            expected = {};
            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("left int right synonym") {
            std::string queryStr = "stmt s; variable v; Select s such that Uses(1, v)";
            std::vector<std::string> expected = {"1", "2", "3", "4", "7"};
            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
        SECTION("left wildcard right quoted") {
            std::string queryStr = "stmt s; variable v; Select s such that Uses(s, \"v\")";
            std::vector<std::string> expected = {"1"};
            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);

            queryStr = "stmt s; variable v; Select s such that Uses(s, \"k\")";
            expected = {"1", "2"};
            REQUIRE(qps.evaluate(std::move(queryStr)) == expected);
        }
    }
    SECTION("pattern"){
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setPatternAsgn({{"1","x=10"}, {"2","x=k"}, {"3","y=c"}, {"4","y=k"}, {"7","z=i"}});
        QPS qps(pkb);

        SECTION("wildcard, substring matching"){
            std::string queryStr = "assign a; Select a pattern a (_,_\"10\"_)";
            std::vector<std::string> expected = {"1"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }
        SECTION("wildcard, substring no match"){
            std::string queryStr = "assign a; Select a pattern a (_,_\"1\"_)";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("quoted ident, substring matching"){
            std::string queryStr = R"(assign a; Select a pattern a ("x",_"10"_))";
            std::vector<std::string> expected = {"1"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }
        SECTION("quoted ident, substring no match"){
            std::string queryStr = R"(assign a; Select a pattern a ("y",_"1"_))";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }
    }

    SECTION("Calls") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setProcedure({{"a", "a"}, {"b", "b"}, {"c", "c"}, {"d", "d"}, {"f", "f"}, {"g", "g"}});
        pkb->setCalls({{"a", "b"}, {"c", "d"}, {"b", "c"}, {"f", "g"}});
        QPS qps(pkb);

        SECTION("simple calls: procedure, procedure"){
            std::string queryStr = "procedure p1, p2; Select p1 such that Calls(p1, p2)";
            std::vector<std::string> expected = {"a", "b", "c", "f"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls flipped: procedure, procedure"){
            std::string queryStr = "procedure p1, p2; Select p1 such that Calls(p2, p1)";
            std::vector<std::string> expected = {"b", "c", "d", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls: procedure, wildcard") {
            std::string queryStr = "procedure p1, p2; Select p1 such that Calls(p1, _)";
            std::vector<std::string> expected = {"a", "b", "c", "f"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls: procedure, wildcard") {
            std::string queryStr = "procedure p1, p2; Select p1 such that Calls(_, p1)";
            std::vector<std::string> expected = {"b", "c", "d", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls: wildcard, wildcard") {
            std::string queryStr = "procedure p1, p2; Select p1 such that Calls(_, _)";
            std::vector<std::string> expected = {"a", "b", "c", "d", "f", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("recursive: procedure, procedure") {
            std::string queryStr = "procedure p1; Select p1 such that Calls(p1, p1)";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls: procedure, syn") {
            std::string queryStr = "procedure p1; Select p1 such that Calls(p1, \"b\")";
            std::vector<std::string> expected = {"a"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls: syn, syn") {
            std::string queryStr = R"(procedure p1; Select p1 such that Calls("a", "b"))";
            std::vector<std::string> expected = {"a", "b", "c", "d", "f", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls: syn, procedure") {
            std::string queryStr = "procedure p1; Select p1 such that Calls(\"b\", p1)";
            std::vector<std::string> expected = {"c"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls: syn, wildcard") {
            std::string queryStr = "procedure p1; Select p1 such that Calls(\"b\", _)";
            std::vector<std::string> expected = {"a", "b", "c", "d", "f", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls: wildcard, syn") {
            std::string queryStr = "procedure p1; Select p1 such that Calls(_, \"b\")";
            std::vector<std::string> expected = {"a", "b", "c", "d", "f", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls: wildcard, syn - negative") {
            std::string queryStr = "procedure p1; Select p1 such that Calls(_, \"k\")";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple calls: syn, syn - transitive property not captured") {
            std::string queryStr = R"(procedure p1; Select p1 such that Calls("a", "c"))";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }
    }

    SECTION("CallsT") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setProcedure({{"a", "a"}, {"b", "b"}, {"c", "c"}, {"d", "d"}, {"f", "f"}, {"g", "g"}});
        pkb->setCallsT({{"a", "b"}, {"c", "d"}, {"b", "c"}, {"f", "g"}, {"a", "c"}, {"a", "d"}, {"b", "d"}});
        QPS qps(pkb);

        SECTION("simple callsT: procedure, procedure"){
            std::string queryStr = "procedure p1, p2; Select p1 such that Calls*(p1, p2)";
            std::vector<std::string> expected = {"a", "b", "c", "f"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT flipped: procedure, procedure"){
            std::string queryStr = "procedure p1, p2; Select p1 such that Calls*(p2, p1)";
            std::vector<std::string> expected = {"b", "c", "d", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT: procedure, wildcard") {
            std::string queryStr = "procedure p1, p2; Select p1 such that Calls*(p1, _)";
            std::vector<std::string> expected = {"a", "b", "c", "f"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT: procedure, wildcard") {
            std::string queryStr = "procedure p1, p2; Select p1 such that Calls*(_, p1)";
            std::vector<std::string> expected = {"b", "c", "d", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT: wildcard, wildcard") {
            std::string queryStr = "procedure p1, p2; Select p1 such that Calls*(_, _)";
            std::vector<std::string> expected = {"a", "b", "c", "d", "f", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("recursive: procedure, procedure") {
            std::string queryStr = "procedure p1; Select p1 such that Calls*(p1, p1)";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT: procedure, syn") {
            std::string queryStr = "procedure p1; Select p1 such that Calls*(p1, \"b\")";
            std::vector<std::string> expected = {"a"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT: syn, syn") {
            std::string queryStr = R"(procedure p1; Select p1 such that Calls*("a", "b"))";
            std::vector<std::string> expected = {"a", "b", "c", "d", "f", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT: syn, procedure") {
            std::string queryStr = "procedure p1; Select p1 such that Calls*(\"b\", p1)";
            std::vector<std::string> expected = {"c", "d"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT: syn, wildcard") {
            std::string queryStr = "procedure p1; Select p1 such that Calls*(\"b\", _)";
            std::vector<std::string> expected = {"a", "b", "c", "d", "f", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT: wildcard, syn") {
            std::string queryStr = "procedure p1; Select p1 such that Calls*(_, \"b\")";
            std::vector<std::string> expected = {"a", "b", "c", "d", "f", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT: wildcard, syn - negative") {
            std::string queryStr = "procedure p1; Select p1 such that Calls*(_, \"k\")";
            std::vector<std::string> expected = {};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }

        SECTION("simple callsT: syn, syn - transitive property") {
            std::string queryStr = R"(procedure p1; Select p1 such that Calls*("a", "c"))";
            std::vector<std::string> expected = {"a", "b", "c", "d", "f", "g"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }
    }

    SECTION("ModifiesP") {
        std::shared_ptr<QueryPKBStub> pkb = std::make_shared<QueryPKBStub>();
        pkb->setProcedure({{"a", "a"}, {"b", "b"}});
        pkb->setVar({{"c", "c"}, {"d", "d"}});
        pkb->setModifiesP({{"a", "c"}, {"a", "d"}, {"b", "d"}});
        QPS qps(pkb);

        SECTION("ModifiesP, prod, var"){
            std::string queryStr = "procedure p; variable v; Select p such that Modifies*(p, v)";
            std::vector<std::string> expected = {"a", "b"};

            REQUIRE(qps.evaluate(queryStr) == expected);
        }
    }
}


std::vector<std::string> testHelper(std::string queryStr){
    std::shared_ptr<QueryPKBVirtual> pkb = std::make_shared<QueryPKBStub>();
    QPS qps(pkb);
    return qps.evaluate(std::move(queryStr));
}
