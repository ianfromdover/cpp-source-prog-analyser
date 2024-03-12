//
// Created by Alex on 11/2/2024.
//

#include "catch.hpp"
#include "qps/QueryPreprocessor/QueryPreprocessor.h"

using namespace std;


TEST_CASE("preprocessor_valid_syntax") {
    QueryPreprocessor q;
    std::string query = "stmt a,b;Select a such that Parent (b, a)";
    auto ls = std::shared_ptr<QueryObject>();
    REQUIRE_NOTHROW(ls = q.processQuery(query));
    REQUIRE(ls != nullptr);
}

TEST_CASE("preprocessor_invalid_syntax") {
    QueryPreprocessor q;
    std::string query = "stmt a,b;Select a such that Pasrent (b, a)";
    auto ls = std::shared_ptr<QueryObject>();
    REQUIRE_THROWS(ls = q.processQuery(query));
}


