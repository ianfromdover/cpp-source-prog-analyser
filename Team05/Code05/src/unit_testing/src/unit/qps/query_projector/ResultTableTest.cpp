//
// Created by tohzh on 3/4/2024.
//

#include "qps/query_projector/ResultTable.h"
#include "catch.hpp"
using namespace std;


TEST_CASE("ResultTable_minus") {
    std::vector<string> header1 = {"animals", "objects", "names"};
    std::vector<string> header1_val1 = {"cat", "phone", "tom"}; // should be deleted
    std::vector<string> header1_val2 = {"dog", "table", "barry"}; // should be deleted
    std::vector<string> header1_val3 = {"giraffe", "table", "tom"};
    std::vector<string> header1_val4 = {"tiger", "table", "john"};

    std::vector<string> header2 = {"animals", "metals", "names"};
    std::vector<string> header2_val1 = {"cat", "gold", "tom"};
    std::vector<string> header2_val2 = {"dog", "aluminium", "barry"};
    std::vector<string> header2_val3 = {"tiger", "aluminium", "barry"};

    table a;
    a.push_back(header1);
    a.push_back(header1_val1);
    a.push_back(header1_val2);
    a.push_back(header1_val3);
    a.push_back(header1_val4);

    table b;
    b.push_back(header2);
    b.push_back(header2_val1);
    b.push_back(header2_val2);
    b.push_back(header2_val3);

    SECTION("returnsValuesWithHeadersAtIndex") {
        SECTION("oneCommonHeader") {
            vector<string> header = {"names"};
            vector<string> res = ResultTable::getValuesAtHeadersAtIndex(b, header, 3);
            vector<string> expected = {"barry"};
            REQUIRE(expected == res);
        }

        SECTION("twoCommonHeader") {
            vector<string> header = {"names", "animals"};
            vector<string> res = ResultTable::getValuesAtHeadersAtIndex(b, header, 1);
            vector<string> expected = {"tom", "cat"};
            REQUIRE(expected == res);
        }
    }

    SECTION("minustable") {
        table c = ResultTable::minusTable(a, b);
        table expected;
        expected.push_back(header1);
        expected.push_back(header1_val3);
        expected.push_back(header1_val4);
        REQUIRE(expected == c);
    }

}