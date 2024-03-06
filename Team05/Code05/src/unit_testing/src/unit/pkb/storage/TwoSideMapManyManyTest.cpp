#include "pkb/storage/base/TwoSideMapManyMany.hpp"
#include "catch.hpp"
using namespace std;

TEST_CASE("[Utils TwoSideMapTwoSet] insert") {
    TwoSideMapManyMany<int, int> map;
    SECTION("Insert 1, 2, insertion successful") {
        REQUIRE(map.insert(1, 2));
    }
}

TEST_CASE("[Utils TwoSideMapTwoSet] getKeys") {
    TwoSideMapManyMany<int, int> map;
    map.insert(1, 2);
    SECTION("Insert (1,2), get key 2 gives 1") {
        REQUIRE(map.getKeys(2).size() == 1);
        REQUIRE(map.getKeys(2)[0] == 1);
    }
}

// ai-gen start (copilot, 1, e)
// prompt: used copilot
// generate the getValues test just like the getKey one
TEST_CASE("[Utils TwoSideMapTwoSet] getValues") {
    TwoSideMapManyMany<int, int> map;
    map.insert(1, 2);
    SECTION("Insert (1,2), get values 1 gives 2") {
        REQUIRE(map.getValues(1).size() == 1);
        REQUIRE(map.getValues(1)[0] == 2);
    }
}
// ai-gen end
