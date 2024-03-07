//
// Created by Alex on 11/2/2024.
//

#include <iostream>
#include "catch.hpp"
#include "qps/QPS.h"
#include "common/StringUtils.h"

using namespace std;


TEST_CASE("System Test") {

//    std::vector<std::string> ls = {"s1","s2"};
//    PKBStub stub(ls);
//    QPS q(stub);
//    std::string query = "stmt a,b;stmt c,d;Select a such that Parent* (b, a)";
//    std::vector<std::string> actual = q.evaluate(query);
//
//    REQUIRE(ls == actual);
}

TEST_CASE("Invalid Syntax"){
//    std::string SYNTAX_ERROR = "SyntaxError";
//    std::vector<std::string> expected = std::vector<std::string>({SYNTAX_ERROR});
//
//    std::vector<std::string> ls = {"s1","s2"};
//    PKBStub stub(ls);
//    QPS q(stub);
//    std::string query = "stmt a,b;stmt c,d;Select a such that invalid* (b, a)";
//    std::vector<std::string> actual = q.evaluate(query);
//
//    REQUIRE(expected == actual);
}

TEST_CASE("double synonym declaration"){
//    std::string SYNTAX_ERROR = "SemanticError";
//    std::vector<std::string> expected = std::vector<std::string>({SYNTAX_ERROR});
//
//    std::vector<std::string> ls = {"s1","s2"};
//    PKBStub stub(ls);
//    QPS q(stub);
//    std::string query = "stmt a,b;stmt a;Select a such that Parent* (b, a)";
//    std::vector<std::string> actual = q.evaluate(query);
//
//    REQUIRE(expected == actual);
}

TEST_CASE("integer argument"){
//    std::string SYNTAX_ERROR = "SemanticError";
//    std::vector<std::string> expected = std::vector<std::string>({SYNTAX_ERROR});
//
//    std::vector<std::string> ls = {"s1","s2"};
//    PKBStub stub(ls);
//    QPS q(stub);
//    std::string query = "stmt a;Select a such that Parent (a, 1)";
//    std::vector<std::string> actual = q.evaluate(query);
//
//    REQUIRE(expected == actual);
}