#include "pkb/storage/base/TwoSideMap.hpp"
#include "catch.hpp"
using namespace std;

TEST_CASE("[PKB TwoSideMap] insert") {
    TwoSideMap<int, int> map;
    SECTION("Insert 1, 2, insertion successful") {
        REQUIRE(map.insert(1, 2));
    }
}

TEST_CASE("[PKB TwoSideMap] getKeys") {
    TwoSideMap<int, int> map;
    map.insert(1, 2);
    SECTION("Insert (1,2), get key 2 gives 1") {
        REQUIRE(map.getKeys(2).size() == 1);
        REQUIRE(map.getKeys(2)[0] == 1);
    }
}

// ai-gen start (copilot, 1, e)
// prompt: used copilot
// generate the getValues test just like the getKey one
TEST_CASE("[PKB TwoSideMap] getValues") {
    TwoSideMap<int, int> map;
    map.insert(1, 2);
    SECTION("Insert (1,2), get values 1 gives 2") {
        REQUIRE(map.getValues(1).size() == 1);
        REQUIRE(map.getValues(1)[0] == 2);
    }
}
// ai-gen end


/**
* Testing Categories:
Initialization
All functions except insert() return false and empty vector.
Type compatibility
Support only <int, int>, <int, std::string>, <std::string, int>, <std::string, std::string>
Functionality (White box testing)
Contents of Data Structure (permute with the functions below)
1 element inside: 1 to 1
1 key related to 4 values
4 keys related to 1 value
4 keys 1 to 1 related to 4 values
4 keys many to many related to 4 values
insert()
Throws exception if existing pair exists
Insert a key that doesn’t exist in the fwdMap yet > no errors
Insert a key that already exists in the fwdMap > no errors
Insert a value that doesn’t exist in the bkwdMap yet > no errors
Insert a value that already exists in the bkwdMap > no errors
getValues(key)
Key not present > return empty vector
Key not present but identical Value is present > return empty vector
Key present > test type compatibility
getKeys(value)
Same as getValues()
getAllForStrStr()
getAllForStrB()
getAllForAStr()
getAllForAB()
Test respective function for respective type of TwoSideMap: different contents of table
Next operation test: State of data structure remains usable after negative input operation is completed.
Robustness
Edge cases: Boundary testing
Getting the first, last, and non-existing elements
Ensure NullPointerError and ArrayIndexError never occurs
Edge cases: Invalid inputs
Inserting items with the wrong type (shouldn’t compile)
Exceptions are triggered and handled in its expected way.
State of data structure remains usable after exceptions are triggered.
Stress testing
Large number of elements inside
Inputs
Big int values
Long strings
Repeatedly calling functions

*/