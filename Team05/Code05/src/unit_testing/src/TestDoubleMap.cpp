// Author: Ian Hong
#include "utilSpa/DoubleMap.h"
#include "utilSpa/DoubleMap.cpp"

#include "catch.hpp"
using namespace std;

// NOTE: depends on REQUIRE function defined in TestAST.cpp
// generate testcases for double map
TEST_CASE("Test DoubleMap") {
    DoubleMap<int, string> dm;
    // ai-gen start (copilot, 1, e)
    // prompt: used copilot
    SECTION("Test insert, get and contains") {
        dm.insert(1, "two");
        REQUIRE(dm.getValue(1) == "two");
        REQUIRE(dm.getKey("two") == 1);
        REQUIRE(dm.containsKey(1) == true);
        REQUIRE(dm.containsValue("two") == true);
    }
    SECTION("Test erase") {
        dm.insert(1, "two");
        dm.eraseKey(1);
        REQUIRE(dm.containsKey(1) == false);
        dm.insert(1, "three");
        dm.eraseValue("three");
        REQUIRE(dm.containsValue("three") == false);
    }
    // ai-gen end
}
