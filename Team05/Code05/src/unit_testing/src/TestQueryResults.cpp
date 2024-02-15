//
// Created by Alex on 11/2/2024.
//

#include "catch.hpp"
#include "qps/QueryEvaluator/QueryResult/QueryResult.h"
#include "qps/QueryEvaluator/QueryResult/IntResult.h"
#include "qps/QueryEvaluator/QueryResult/StringResult.h"

using namespace std;



TEST_CASE("String Result") {
    std::string s1 = "myVar1";
    std::string s2 = "myVar2";
    std::string s3 = "myVar3";
    std::vector<std::string> ls = {s1,s2,s3};
    StringResult result(ls);

    std::vector<std::string> expected = {s1,s2,s3};
    std::vector<std::string> actual = result.getResults();

    REQUIRE(expected == actual);
}

TEST_CASE("Integer Result") {
    int i1(1);
    int i2(2);
    int i3(3);
    std::vector<int> ls = {i1,i2,i3};
    IntResult result(ls);

    std::vector<int> expected = {i1,i2,i3};
    std::vector<int> actual = result.getResults();

    REQUIRE(expected == actual);
}



