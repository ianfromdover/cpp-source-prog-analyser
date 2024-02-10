//
// Created by Alex on 11/2/2024.
//

#include <iostream>
#include "catch.hpp"
#include "qps/QPS.h"
#include "Utils/Utils.h"

using namespace std;


TEST_CASE("System Test") {
    QPS q;
    std::string query = "stmt a,b;Select a such that Parent (b, a)";
    std::cout << Utils::formatWithSquareBrackets(q.evaluate(query));
}