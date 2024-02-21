#include "utilSpa/TwoSideMapSet.hpp"
#include "catch.hpp"
using namespace std;

TEST_CASE("[Utils TwoSideMapSet] insert") {
    TwoSideMapSet<int, int> map;
    SECTION("Insert 1, 2, insertion successful") {
        REQUIRE(map.insert(1, 2));
    }
}

TEST_CASE("[Utils TwoSideMapSet] containsKey") {
    TwoSideMapSet<int, int> map;
    map.insert(1, 2);
    SECTION("Insert 1, 2, contains key 1") {
        REQUIRE(map.containsKey(1));
    }
    SECTION("Insert 1, 2, does not contain key 2") {
        REQUIRE(!map.containsKey(2));
    }
}

TEST_CASE("[Utils TwoSideMapSet] containsValue") {
    TwoSideMapSet<int, int> map;
    map.insert(1, 2);
    SECTION("Insert 1, 2, contains value 2") {
        REQUIRE(map.containsValue(2));
    }
    SECTION("Insert 1, 2, does not contain value 1") {
        REQUIRE(!map.containsValue(1));
    }
}

TEST_CASE("[Utils TwoSideMapSet] size") {
    TwoSideMapSet<int, int> map;
    map.insert(1, 2);
    SECTION("Insert 1, 2, size is 1") {
        REQUIRE(map.size() == 1);
    }

    SECTION("Insert (1,2) (1,3) (1,4), size is 3") {
        map.insert(1, 3);
        map.insert(1, 4);
        REQUIRE(map.size() == 3);
    }

    SECTION("Insert (1,2) (1,2), size is still 1") {
        map.insert(1, 2);
        REQUIRE(map.size() == 1);
    }
}

TEST_CASE("[Utils TwoSideMapSet] getKey") {
    TwoSideMapSet<int, int> map;
    map.insert(1, 2);
    SECTION("Insert (1,2), get key 2 gives 1") {
        REQUIRE(map.getKey(2) == 1);
    }
}

// ai-gen start (copilot, 1, e)
// prompt: used copilot
// generate the getValues test just like the getKey one
TEST_CASE("[Utils TwoSideMapSet] getValues") {
    TwoSideMapSet<int, int> map;
    map.insert(1, 2);
    SECTION("Insert (1,2), get values 1 gives 2") {
        REQUIRE(map.getValues(1).size() == 1);
        REQUIRE(map.getValues(1)[0] == 2);
    }
}
// ai-gen end
