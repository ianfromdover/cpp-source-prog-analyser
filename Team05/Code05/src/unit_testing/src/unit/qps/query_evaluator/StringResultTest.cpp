//
// Created by tohzh on 21/2/2024.
//


#include "qps/QueryEvaluator/QueryResult/StringResult.h"
#include "catch.hpp"
#include <iostream>
using namespace std;


// ai-start (gpt, 1, e)
// prompt: https://platform.openai.com/playground/p/tfczSZD2QnYx60j92yQmkCjd?model=gpt-4&mode=chat
TEST_CASE("stringResult-intersect_emptycontainers_returnsEmpty") {
    std::vector<std::string> baseResults = { };
    std::vector<std::string> intersectResults;

    StringResult baseRes(baseResults);
    std::shared_ptr<StringResult> intersectRes = std::make_shared<StringResult>(intersectResults);

    std::vector<std::string> result = baseRes.intersect(intersectRes);

    REQUIRE(result.empty());
}


TEST_CASE("stringResult-intersect_emptyResult_returnsEmpty") {
    std::vector<std::string> baseResults = { "test1", "test2", "test3" };
    std::vector<std::string> intersectResults;

    StringResult baseRes(baseResults);
    std::shared_ptr<StringResult> intersectRes = std::make_shared<StringResult>(intersectResults);

    std::vector<std::string> result = baseRes.intersect(intersectRes);

    REQUIRE(result.empty());
}

TEST_CASE("stringResult-intersect_nonEmptyIntersection_returnsExactly1") {
    std::vector<std::string> baseResults = { "test1", "test2", "test3" };
    std::vector<std::string> intersectResults = { "test2", "test4", "test5" };

    StringResult baseRes(baseResults);
    std::shared_ptr<StringResult> intersectRes = std::make_shared<StringResult>(intersectResults);

    std::vector<std::string> result = baseRes.intersect(intersectRes);

    REQUIRE(!result.empty());
    REQUIRE(result.size() == 1);
    REQUIRE(result[0] == "test2");
}

TEST_CASE("stringResult-intersect_nonEmptyIntersection_returnsMore1") {
    std::vector<std::string> baseResults = { "test1", "test2", "test3" , "a", "b", "c"};
    std::vector<std::string> intersectResults = { "test2", "test4", "test5" , "a", "b"};

    StringResult baseRes(baseResults);
    std::shared_ptr<StringResult> intersectRes = std::make_shared<StringResult>(intersectResults);

    std::vector<std::string> result = baseRes.intersect(intersectRes);

    REQUIRE(!result.empty());
    REQUIRE(result.size() == 3);
    REQUIRE(result[0] == "a");
    REQUIRE(result[1] == "b");
    REQUIRE(result[2] == "test2");
}

// ai-end