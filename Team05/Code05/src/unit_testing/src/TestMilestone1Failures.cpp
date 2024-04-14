//
// Created by Alex Teo on 6/3/2024.
//




#include "sp/parser/Parser.h"

#include "sp/SourceProcessor.h"
#include "catch.hpp"
#include "qps/QPS.h"

using namespace std;

TEST_CASE("Milestone 1 failures") {

    std::string codeSnippet = R"(
    procedure computeCentroid {
        print x;
        if (hello == 0) then {
            y=1;
            print t;
            read f;
            while (x == 0) {
                if (i == 1) then {
                    w = 0;
                } else {
                    g = 10;
                    g=x;
                }
                x=1;
            }
        } else {
            print hello;
        }
        x=0;
        y=1;
        z=x+y;
    }
    )";

    std::shared_ptr<PkbStorage> p=std::make_shared<PkbStorage>();
    auto pkb = make_shared<PopulatePkb>(p);
    auto sp = SourceProcessor(pkb);

    const auto program = sp.parse(sp.scan(codeSnippet));
    sp.validate(program);
    sp.extract(program);

    QueryPkb pkb1(p);
    QPS qps(std::make_shared<QueryPkb>(pkb1));

    SECTION("fail 1") {
        std::string query = "assign a; while w; Select a such that Modifies (w, \"x\") pattern a (_, _\"x\"_)";
        Table table = pkb1.getModifiesSTable();
        ResultTable t(table);
        std::string s = t.toString();
        std::vector<std::string> expected  = {"10", "15"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("fail 2") {
        std::string query = "assign a, a1; variable v, v1; Select v1 such that Modifies (a, v) pattern a1 (v1, _)";
        std::vector<std::string> expected  = {"y", "x", "w", "g", "z"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

//    SECTION("fail 3") {
//        std::string query = "assign a, a1; Select a such that Parent* (28, a) pattern a1 (\"left\", _)";
//        std::vector<std::string> expected  = {"SyntaxError"};
//        std::vector<std::string> ans = qps.evaluate(query);
//        std::sort(ans.begin(), ans.end());
//        std::sort(expected.begin(), expected.end());
//        REQUIRE(ans==expected);
//    }
//
//    SECTION("fail 4") {
//        std::string query = "assign a, a1; Select a such that Parent* (27, a) pattern a1 (_, _\"x\"_)";
//        std::vector<std::string> expected  = {"SyntaxError"};
//        std::vector<std::string> ans = qps.evaluate(query);
//        std::sort(ans.begin(), ans.end());
//        std::sort(expected.begin(), expected.end());
//        REQUIRE(ans==expected);
//    }
//
    SECTION("fail 5") {
        std::string query = "assign a; Select a pattern a (_, _\"1 \"_)";
        std::vector<std::string> expected  = {"3","11","14"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("fail 5-1") {
        std::string query = "assign a; Select a pattern a (_, _\"10 \"_)";
        std::vector<std::string> expected  = {"9"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("fail 6") {
        std::string query = "assign a; variable v; Select a such that Uses (a, v) pattern a (v, _)";
        std::vector<std::string> expected  = {};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

//    SECTION("fail 7") {
//        std::string query = "while w; assign a; Select w such that Uses(w, \"left\") pattern a(_, _\"right\"_)";
//        std::vector<std::string> expected  = {"SyntaxError"};
//        std::vector<std::string> ans = qps.evaluate(query);
//        std::sort(ans.begin(), ans.end());
//        std::sort(expected.begin(), expected.end());
//        REQUIRE(ans==expected);
//    }
//
//    SECTION("fail 8") {
//        std::string query = "stmt w; assign a; print pr; Select w such that Parent*(w, pr) pattern a(_, _\"left\"_)";
//        std::vector<std::string> expected  = {"SyntaxError"};
//        std::vector<std::string> ans = qps.evaluate(query);
//        std::sort(ans.begin(), ans.end());
//        std::sort(expected.begin(), expected.end());
//        REQUIRE(ans==expected);
//    }

    SECTION("fail 9") {
        std::string query = "print rd; variable v; stmt s; assign a; Select s such that Parent (s, rd) pattern a(v,_)";
        std::vector<std::string> expected  = {"2"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("fail 10") {
        std::string query = "print s; variable v; Select s such that Modifies (s, v)";
        std::vector<std::string> expected  = {};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Same stmt synonym for parents") {
        std::string query = "stmt s; Select s such that Parent(s, s)";
        std::vector<std::string> expected  = { };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Same stmt synonym for parentsT") {
        std::string query = "stmt s; Select s such that Parent*(s, s)";
        std::vector<std::string> expected  = { };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Same stmt synonym for follows") {
        std::string query = "stmt s; Select s such that Follows(s, s)";
        std::vector<std::string> expected  = { };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Same assign synonym for follows") {
        std::string query = "assign a; Select a such that Follows (a, a)";
        std::vector<std::string> expected  = { };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("Same stmt synonym for followsT") {
        std::string query = "stmt s; Select s such that Follows*(s, s)";
        std::vector<std::string> expected  = { };
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }

    SECTION("such that pattern") {
        std::string query = "assign s, s1; Select s such that pattern s (_, _)";
        std::vector<std::string> expected  = {"SyntaxError"};
        std::vector<std::string> ans = qps.evaluate(query);
        std::sort(ans.begin(), ans.end());
        std::sort(expected.begin(), expected.end());
        REQUIRE(ans==expected);
    }
}