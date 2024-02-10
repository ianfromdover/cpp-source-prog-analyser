//
// Created by Alex on 11/2/2024.
//

#include "catch.hpp"
#include "QPS/QueryPreprocessor/QueryPreprocessor.h"

using namespace std;


TEST_CASE("Valid PQL Syntax1") {
    QueryPreprocessor q;
    std::string query = "stmt a,b;Select a such that Parent (b, a)";
    q.processQuery(query);
}


