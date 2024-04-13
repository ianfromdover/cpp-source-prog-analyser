#include <algorithm>
#include "pkb/storage/PkbTable.hpp"
#include "catch.hpp"
using namespace std;

// ai-gen start (gpt, 1, e)
// prompt: https://platform.openai.com/playground/p/ZlqY4SUWokphGAAdm9Ht7lR3?model=gpt-4&mode=chat

TEST_CASE("[PKB PkbTable] Initialisation") {
    PkbTable<int, int> intIntTable;
    PkbTable<int, std::string> intStringTable;
    PkbTable<std::string, int> stringIntTable;
    PkbTable<std::string, std::string> stringStringTable;

    SECTION("ContainsKey and ContainsValue when table is empty") {
        SECTION("int, int") {
            REQUIRE_FALSE(intIntTable.containsKey(1));
            REQUIRE_FALSE(intIntTable.containsValue(1));
        }

        SECTION("int, string") {
            REQUIRE_FALSE(intStringTable.containsKey(1));
            REQUIRE_FALSE(intStringTable.containsValue("value"));
        }

        SECTION("string, int") {
            REQUIRE_FALSE(stringIntTable.containsKey("key"));
            REQUIRE_FALSE(stringIntTable.containsValue(1));
        }

        SECTION("string, string") {
            REQUIRE_FALSE(stringStringTable.containsKey("key"));
            REQUIRE_FALSE(stringStringTable.containsValue("value"));
        }
    }

    SECTION("Make forward and backward map table") {
        REQUIRE(intIntTable.makeTable(true) != nullptr);
        REQUIRE(intIntTable.makeTable(false) != nullptr);

        // repeat for the other tables
        // copilot generated the remaining lines in this section
        REQUIRE(intStringTable.makeTable(true) != nullptr);
        REQUIRE(intStringTable.makeTable(false) != nullptr);

        REQUIRE(stringIntTable.makeTable(true) != nullptr);
        REQUIRE(stringIntTable.makeTable(false) != nullptr);

        REQUIRE(stringStringTable.makeTable(true) != nullptr);
        REQUIRE(stringStringTable.makeTable(false) != nullptr);
    }

    SECTION("All functions false and empty when table is empty") {
        SECTION("int, int") {
            REQUIRE_FALSE(intIntTable.containsPair(1, 2));

            REQUIRE(intIntTable.getRelatedValues(5).empty());
            REQUIRE(intIntTable.getRelatedKeys(5).empty());
            REQUIRE(intIntTable.getAllKeys().empty());
            REQUIRE(intIntTable.getAllValues().empty());
            REQUIRE(intIntTable.getAll().empty());
        }

        SECTION("int, string") {
            REQUIRE_FALSE(intStringTable.containsPair(1, "value"));

            REQUIRE(intStringTable.getRelatedValues(5).empty());
            REQUIRE(intStringTable.getRelatedKeys("value").empty());
            REQUIRE(intStringTable.getAllKeys().empty());
            REQUIRE(intStringTable.getAllValues().empty());
            REQUIRE(intStringTable.getAll().empty());
        }

        SECTION("string, int") {
            REQUIRE_FALSE(stringIntTable.containsPair("key", 2));

            REQUIRE(stringIntTable.getRelatedValues("key").empty());
            REQUIRE(stringIntTable.getRelatedKeys(5).empty());
            REQUIRE(stringIntTable.getAllKeys().empty());
            REQUIRE(stringIntTable.getAllValues().empty());
            REQUIRE(stringIntTable.getAll().empty());
        }

        SECTION("string, string") {
            REQUIRE_FALSE(stringStringTable.containsPair("key", "value"));

            REQUIRE(stringStringTable.getRelatedValues("key").empty());
            REQUIRE(stringStringTable.getRelatedKeys("value").empty());
            REQUIRE(stringStringTable.getAllKeys().empty());
            REQUIRE(stringStringTable.getAllValues().empty());
            REQUIRE(stringStringTable.getAll().empty());
        }
    }
}

TEST_CASE("[PKB PkbTable] all contains methods") {
    PkbTable<int, int> intIntTable;
    PkbTable<int, std::string> intStringTable;
    PkbTable<std::string, int> stringIntTable;
    PkbTable<std::string, std::string> stringStringTable;

    SECTION("Add a pair and check contains methods") {
        SECTION("int, int") {
            intIntTable.add(1, 1);
            REQUIRE(intIntTable.containsKey(1));
            REQUIRE(intIntTable.containsValue(1));
            REQUIRE(intIntTable.containsPair(1, 1));
        }

        SECTION("int, string") {
            intStringTable.add(1, "value");
            REQUIRE(intStringTable.containsKey(1));
            REQUIRE(intStringTable.containsValue("value"));
            REQUIRE(intStringTable.containsPair(1, "value"));
        }

        SECTION("string, int") {
            stringIntTable.add("key", 1);
            REQUIRE(stringIntTable.containsKey("key"));
            REQUIRE(stringIntTable.containsValue(1));
            REQUIRE(stringIntTable.containsPair("key", 1));
        }

        SECTION("string, string") {
            stringStringTable.add("key", "value");
            REQUIRE(stringStringTable.containsKey("key"));
            REQUIRE(stringStringTable.containsValue("value"));
            REQUIRE(stringStringTable.containsPair("key", "value"));
        }
    }

    // use boundary testing to check for false cases
    // ensure exceptions are not thrown
    SECTION("Boundary testing cases") {
        SECTION("int, int") {
            intIntTable.add(1, 1);
            REQUIRE_FALSE(intIntTable.containsKey(2));
            REQUIRE_FALSE(intIntTable.containsValue(2));
            REQUIRE_FALSE(intIntTable.containsPair(1, 2));
            REQUIRE_NOTHROW(intIntTable.containsKey(2));
            REQUIRE_NOTHROW(intIntTable.containsValue(2));
            REQUIRE_NOTHROW(intIntTable.containsPair(1, 2));
        }

        SECTION("int, string") {
            intStringTable.add(1, "value");
            REQUIRE_FALSE(intStringTable.containsKey(2));
            REQUIRE_FALSE(intStringTable.containsValue("value2"));
            REQUIRE_FALSE(intStringTable.containsPair(1, "value2"));
            REQUIRE_NOTHROW(intStringTable.containsKey(2));
            REQUIRE_NOTHROW(intStringTable.containsValue("value2"));
            REQUIRE_NOTHROW(intStringTable.containsPair(1, "value2"));
        }

        SECTION("string, int") {
            stringIntTable.add("key", 1);
            REQUIRE_FALSE(stringIntTable.containsKey("key2"));
            REQUIRE_FALSE(stringIntTable.containsValue(2));
            REQUIRE_FALSE(stringIntTable.containsPair("key2", 2));
            REQUIRE_NOTHROW(stringIntTable.containsKey("key2"));
            REQUIRE_NOTHROW(stringIntTable.containsValue(2));
            REQUIRE_NOTHROW(stringIntTable.containsPair("key2", 2));
        }

        SECTION("string, string") {
            stringStringTable.add("key", "value");
            REQUIRE_FALSE(stringStringTable.containsKey("key2"));
            REQUIRE_FALSE(stringStringTable.containsValue("value2"));
            REQUIRE_FALSE(stringStringTable.containsPair("key2", "value2"));
            REQUIRE_NOTHROW(stringStringTable.containsKey("key2"));
            REQUIRE_NOTHROW(stringStringTable.containsValue("value2"));
            REQUIRE_NOTHROW(stringStringTable.containsPair("key2", "value2"));
        }
    }

    // use invalid inputs to check for false cases
    // ensure exceptions are not thrown
    SECTION("Boundary testing") {
        SECTION("int, int") {
            intIntTable.add(1, 1);
            REQUIRE_FALSE(intIntTable.containsKey(0));
            REQUIRE_FALSE(intIntTable.containsValue(0));
            REQUIRE_FALSE(intIntTable.containsPair(0, 0));
            REQUIRE_NOTHROW(intIntTable.containsKey(0));
            REQUIRE_NOTHROW(intIntTable.containsValue(0));
            REQUIRE_NOTHROW(intIntTable.containsPair(0, 0));
        }

        SECTION("int, string") {
            intStringTable.add(1, "value");
            REQUIRE_FALSE(intStringTable.containsKey(0));
            REQUIRE_FALSE(intStringTable.containsValue("value2"));
            REQUIRE_FALSE(intStringTable.containsPair(0, "value2"));
            REQUIRE_NOTHROW(intStringTable.containsKey(0));
            REQUIRE_NOTHROW(intStringTable.containsValue("value2"));
            REQUIRE_NOTHROW(intStringTable.containsPair(0, "value2"));
        }

        SECTION("string, int") {
            stringIntTable.add("key", 1);
            REQUIRE_FALSE(stringIntTable.containsKey("key2"));
            REQUIRE_FALSE(stringIntTable.containsValue(0));
            REQUIRE_FALSE(stringIntTable.containsPair("key2", 0));
            REQUIRE_NOTHROW(stringIntTable.containsKey("key2"));
            REQUIRE_NOTHROW(stringIntTable.containsValue(0));
            REQUIRE_NOTHROW(stringIntTable.containsPair("key2", 0));
        }

        SECTION("string, string") {
            stringStringTable.add("key", "value");
            REQUIRE_FALSE(stringStringTable.containsKey("key2"));
            REQUIRE_FALSE(stringStringTable.containsValue("value2"));
            REQUIRE_FALSE(stringStringTable.containsPair("key2", "value2"));
            REQUIRE_NOTHROW(stringStringTable.containsKey("key2"));
            REQUIRE_NOTHROW(stringStringTable.containsValue("value2"));
            REQUIRE_NOTHROW(stringStringTable.containsPair("key2", "value2"));
        }
    }
}

TEST_CASE("[PKB PkbTable] add()") {
    PkbTable<int, std::string> intStringMap;

    SECTION("False if existing pair exists") {
        int key = 1;
        std::string value = "value";

        // successful for Adding a key that doesn't exist in fwdMap and bkwdMap yet
        REQUIRE(intStringMap.add(key, value)); // Add should be successful initially
        REQUIRE_FALSE(intStringMap.add(key, value)); // Second attempt should be false
    }

    SECTION("Add a key that already exists in the fwdMap but value doesn't, successful") {
        int key = 3;
        std::string value1 = "value1";
        std::string value2 = "value2";

        REQUIRE(intStringMap.add(key, value1)); // first adding, should be successful
        REQUIRE(intStringMap.add(key, value2)); // adding new value for the same key, should be successful
    }

    SECTION("Add a value that already exists in the bkwdMap, but key doesn't, successful") {
        std::string bwKey = "repeated";
        int bwValue1 = 4;
        int bwValue2 = 5;

        REQUIRE_NOTHROW(intStringMap.add(bwValue1, bwKey)); // first adding, should be successful
        REQUIRE_NOTHROW(intStringMap.add(bwValue2, bwKey)); // adding new key for the same value, should be successful
    }
}

TEST_CASE("[PKB PkbTable] getRelatedValues") {
    // each PKB state
    PkbTable<std::string, int> onePair;
    PkbTable<std::string, int> oneKeyFourVals;
    PkbTable<std::string, int> fourKeysOneVal;
    PkbTable<std::string, int> fourPairs; // 4 distinct pairs that are not related to each other
    PkbTable<std::string, int> fourManyMany; // 4 keys with many-to-many relations to 4 values (complete graph)

    SECTION("Setup Successful") { // only for this particular one, rest of get fns just do the add.
        onePair.add("1", 1);
        REQUIRE(onePair.containsPair("1", 1));

        oneKeyFourVals.add("key", 1);
        oneKeyFourVals.add("key", 2);
        oneKeyFourVals.add("key", 3);
        oneKeyFourVals.add("key", 4);
        REQUIRE(oneKeyFourVals.getRelatedValues("key").size() == 4);
        REQUIRE(oneKeyFourVals.getAll().size() == 4);

        fourKeysOneVal.add("key1", 1);
        fourKeysOneVal.add("key2", 1);
        fourKeysOneVal.add("key3", 1);
        fourKeysOneVal.add("key4", 1);
        REQUIRE(fourKeysOneVal.getRelatedKeys(1).size() == 4);
        REQUIRE(fourKeysOneVal.getAll().size() == 4);

        fourPairs.add("key1", 1);
        fourPairs.add("key2", 2);
        fourPairs.add("key3", 3);
        fourPairs.add("key4", 4);
        REQUIRE(fourPairs.getAll().size() == 4);
        for(const auto& key : {"key1", "key2", "key3", "key4"}) {
            REQUIRE(fourPairs.getRelatedValues(key).size() == 1);
        }
        for(int value = 1; value <= 4; value++) {
            REQUIRE(fourPairs.getRelatedKeys(value).size() == 1);
        }

        fourManyMany.add("key1", 1);
        fourManyMany.add("key2", 1);
        fourManyMany.add("key3", 1);
        fourManyMany.add("key4", 1);
        fourManyMany.add("key1", 2);
        fourManyMany.add("key2", 2);
        fourManyMany.add("key3", 2);
        fourManyMany.add("key4", 2);
        fourManyMany.add("key1", 3);
        fourManyMany.add("key2", 3);
        fourManyMany.add("key3", 3);
        fourManyMany.add("key4", 3);
        fourManyMany.add("key1", 4);
        fourManyMany.add("key2", 4);
        fourManyMany.add("key3", 4);
        fourManyMany.add("key4", 4);
        REQUIRE(fourManyMany.getAll().size() == 16);
        for(const auto& key : {"key1", "key2", "key3", "key4"}) {
            REQUIRE(fourManyMany.getRelatedValues(key).size() == 4);
        }
        for(int value = 1; value <= 4; value++) {
            REQUIRE(fourManyMany.getRelatedKeys(value).size() == 4);
        }
    }


    SECTION("Positive Cases") {
        // setup state of each PkbTable for the rest of the tests
        // identical to the setup test earlier
        onePair.add("1", 1);
        oneKeyFourVals.add("key", 1);
        oneKeyFourVals.add("key", 2);
        oneKeyFourVals.add("key", 3);
        oneKeyFourVals.add("key", 4);
        fourKeysOneVal.add("key1", 1);
        fourKeysOneVal.add("key2", 1);
        fourKeysOneVal.add("key3", 1);
        fourKeysOneVal.add("key4", 1);
        fourPairs.add("key1", 1);
        fourPairs.add("key2", 2);
        fourPairs.add("key3", 3);
        fourPairs.add("key4", 4);
        fourManyMany.add("key1", 1);
        fourManyMany.add("key2", 1);
        fourManyMany.add("key3", 1);
        fourManyMany.add("key4", 1);
        fourManyMany.add("key1", 2);
        fourManyMany.add("key2", 2);
        fourManyMany.add("key3", 2);
        fourManyMany.add("key4", 2);
        fourManyMany.add("key1", 3);
        fourManyMany.add("key2", 3);
        fourManyMany.add("key3", 3);
        fourManyMany.add("key4", 3);
        fourManyMany.add("key1", 4);
        fourManyMany.add("key2", 4);
        fourManyMany.add("key3", 4);
        fourManyMany.add("key4", 4);
        auto onePairResults = onePair.getRelatedValues("1");
        REQUIRE(onePairResults == std::vector<int>{1});

        auto oneKeyFourValsResults = oneKeyFourVals.getRelatedValues("key");
        std::sort(oneKeyFourValsResults.begin(), oneKeyFourValsResults.end());
        REQUIRE(oneKeyFourValsResults == std::vector<int>{1, 2, 3, 4});

        auto fourKeysOneValResults = fourKeysOneVal.getRelatedValues("key1");
        std::sort(fourKeysOneValResults.begin(), fourKeysOneValResults.end());
        REQUIRE(fourKeysOneValResults == std::vector<int>{1});

        auto fourPairsResults = fourPairs.getRelatedValues("key1");
        std::sort(fourPairsResults.begin(), fourPairsResults.end());
        REQUIRE(fourPairsResults == std::vector<int>{1});

        auto fourManyManyResults = fourManyMany.getRelatedValues("key1");
        std::sort(fourManyManyResults.begin(), fourManyManyResults.end());
        REQUIRE(fourManyManyResults == std::vector<int>{1, 2, 3, 4});
    }

    SECTION("Negative cases using boundary testing") {

        // onePair state
        PkbTable<std::string, int> onePair;
        onePair.add("1", 1);

        REQUIRE(onePair.getRelatedValues("").empty());
        REQUIRE(onePair.getRelatedValues("0").empty());
        REQUIRE(onePair.getRelatedValues("2").empty());

        // oneKeyFourVals state
        PkbTable<std::string, int> oneKeyFourVals;
        oneKeyFourVals.add("1", 1);
        oneKeyFourVals.add("1", 2);
        oneKeyFourVals.add("1", 3);
        oneKeyFourVals.add("1", 4);

        REQUIRE(oneKeyFourVals.getRelatedValues("").empty());
        REQUIRE(oneKeyFourVals.getRelatedValues("0").empty());
        REQUIRE(oneKeyFourVals.getRelatedValues("2").empty());

        // fourKeysOneVal state
        PkbTable<std::string, int> fourKeysOneVal;
        fourKeysOneVal.add("key1", 1);
        fourKeysOneVal.add("key2", 1);
        fourKeysOneVal.add("key3", 1);
        fourKeysOneVal.add("key4", 1);

        REQUIRE(fourKeysOneVal.getRelatedValues("").empty());
        REQUIRE(fourKeysOneVal.getRelatedValues("key0").empty());
        REQUIRE(fourKeysOneVal.getRelatedValues("key5").empty());

        // fourPairs state
        PkbTable<std::string, int> fourPairs;
        fourPairs.add("key1", 1);
        fourPairs.add("key2", 2);
        fourPairs.add("key3", 3);
        fourPairs.add("key4", 4);

        REQUIRE(fourPairs.getRelatedValues("").empty());
        REQUIRE(fourPairs.getRelatedValues("key0").empty());
        REQUIRE(fourPairs.getRelatedValues("key5").empty());

        // fourManyMany state
        PkbTable<std::string, int> fourManyMany;
        for (int i = 1; i <= 4; ++i) {
            for (int j = 1; j <= 4; ++j) {
                fourManyMany.add("key" + std::to_string(i), j);
            }
        }

        REQUIRE(fourManyMany.getRelatedValues("").empty());
        REQUIRE(fourManyMany.getRelatedValues("key0").empty());
        REQUIRE(fourManyMany.getRelatedValues("key5").empty());
    }
}

// generate the same for getRelatedKeys
TEST_CASE("[PKB PkbTable] getRelatedKeys") {
    // each PKB state
    PkbTable<std::string, int> onePair;
    PkbTable<std::string, int> oneKeyFourVals;
    PkbTable<std::string, int> fourKeysOneVal;
    PkbTable<std::string, int> fourPairs; // 4 distinct pairs that are not related to each other
    PkbTable<std::string, int> fourManyMany; // 4 keys with many-to-many relations to 4 values (complete graph)

    SECTION("Positive Cases") {
        // setup state of each PkbTable for the rest of the tests
        // identical to the setup test earlier
        onePair.add("1", 1);
        oneKeyFourVals.add("key", 1);
        oneKeyFourVals.add("key", 2);
        oneKeyFourVals.add("key", 3);
        oneKeyFourVals.add("key", 4);
        fourKeysOneVal.add("key1", 1);
        fourKeysOneVal.add("key2", 1);
        fourKeysOneVal.add("key3", 1);
        fourKeysOneVal.add("key4", 1);
        fourPairs.add("key1", 1);
        fourPairs.add("key2", 2);
        fourPairs.add("key3", 3);
        fourPairs.add("key4", 4);
        fourManyMany.add("key1", 1);
        fourManyMany.add("key2", 1);
        fourManyMany.add("key3", 1);
        fourManyMany.add("key4", 1);
        fourManyMany.add("key1", 2);
        fourManyMany.add("key2", 2);
        fourManyMany.add("key3", 2);
        fourManyMany.add("key4", 2);
        fourManyMany.add("key1", 3);
        fourManyMany.add("key2", 3);
        fourManyMany.add("key3", 3);
        fourManyMany.add("key4", 3);
        fourManyMany.add("key1", 4);
        fourManyMany.add("key2", 4);
        fourManyMany.add("key3", 4);
        fourManyMany.add("key4", 4);
        auto onePairResults = onePair.getRelatedKeys(1);
        REQUIRE(onePairResults == std::vector<std::string>{"1"});

        auto oneKeyFourValsResults = oneKeyFourVals.getRelatedKeys(1);
        std::sort(oneKeyFourValsResults.begin(), oneKeyFourValsResults.end());
        REQUIRE(oneKeyFourValsResults == std::vector<std::string>{"key"});

        auto fourKeysOneValResults = fourKeysOneVal.getRelatedKeys(1);
        std::sort(fourKeysOneValResults.begin(), fourKeysOneValResults.end());
        REQUIRE(fourKeysOneValResults == std::vector<std::string>{"key1", "key2", "key3", "key4"});

        auto fourPairsResults = fourPairs.getRelatedKeys(1);
        std::sort(fourPairsResults.begin(), fourPairsResults.end());
        REQUIRE(fourPairsResults == std::vector<std::string>{"key1"});

        auto fourManyManyResults = fourManyMany.getRelatedKeys(1);
        std::sort(fourManyManyResults.begin(), fourManyManyResults.end());
        REQUIRE(fourManyManyResults == std::vector<std::string>{"key1", "key2", "key3", "key4"});
    }

    SECTION("Negative cases using boundary testing") {

        // onePair state
        onePair.add("1", 1);

        REQUIRE(onePair.getRelatedKeys(0).empty());
        REQUIRE(onePair.getRelatedKeys(2).empty());

        // oneKeyFourVals state
        oneKeyFourVals.add("1", 1);
        oneKeyFourVals.add("1", 2);
        oneKeyFourVals.add("1", 3);
        oneKeyFourVals.add("1", 4);

        REQUIRE(oneKeyFourVals.getRelatedKeys(0).empty());
        REQUIRE(oneKeyFourVals.getRelatedKeys(5).empty());

        // fourKeysOneVal state
        fourKeysOneVal.add("key1", 1);
        fourKeysOneVal.add("key2", 1);
        fourKeysOneVal.add("key3", 1);
        fourKeysOneVal.add("key4", 1);

        REQUIRE(fourKeysOneVal.getRelatedKeys(0).empty());
        REQUIRE(fourKeysOneVal.getRelatedKeys(5).empty());

        // fourPairs state
        fourPairs.add("key1", 1);
        fourPairs.add("key2", 2);
        fourPairs.add("key3", 3);
        fourPairs.add("key4", 4);

        REQUIRE(fourKeysOneVal.getRelatedKeys(0).empty());
        REQUIRE(fourKeysOneVal.getRelatedKeys(5).empty());

        // fourManyMany state
        for (int i = 1; i <= 4; ++i) {
            for (int j = 1; j <= 4; ++j) {
                fourManyMany.add("key" + std::to_string(i), j);
            }
        }

        REQUIRE(fourKeysOneVal.getRelatedKeys(0).empty());
        REQUIRE(fourKeysOneVal.getRelatedKeys(5).empty());
    }
}

TEST_CASE("[PKB PkbTable] getAllKeys() and getAllValues()") {
    // onePair state
    PkbTable<std::string, int> onePair;
    onePair.add("1", 1);

    // oneKeyFourVals state
    PkbTable<std::string, int> oneKeyFourVals;
    for (int i = 1; i <= 4; ++i) {
        oneKeyFourVals.add("1", i);
    }

    // fourKeysOneVal state
    PkbTable<std::string, int> fourKeysOneVal;
    for (int i = 1; i <= 4; ++i) {
        fourKeysOneVal.add("key" + std::to_string(i), 1);
    }

    // fourPairs state
    PkbTable<std::string, int> fourPairs;
    for (int i = 1; i <= 4; ++i) {
        fourPairs.add("key" + std::to_string(i), i);
    }

    // fourManyMany state
    PkbTable<std::string, int> fourManyMany;
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            fourManyMany.add("key" + std::to_string(i), j);
        }
    }

    // Positive test cases for getAllKeys()
    SECTION("getAllKeys() positive test cases") {
        REQUIRE(onePair.getAllKeys().size() == 1);
        REQUIRE(oneKeyFourVals.getAllKeys().size() == 1);
        REQUIRE(fourKeysOneVal.getAllKeys().size() == 4);
        REQUIRE(fourPairs.getAllKeys().size() == 4);
        REQUIRE(fourManyMany.getAllKeys().size() == 4);
    }

        // Negative test cases for getAllKeys()
    SECTION("getAllKeys() negative test cases") {
        REQUIRE_FALSE((onePair.getAllKeys().size() == 0));
        REQUIRE_FALSE((oneKeyFourVals.getAllKeys().size() == 0));
        REQUIRE_FALSE((fourKeysOneVal.getAllKeys().size() == 0));
        REQUIRE_FALSE((fourPairs.getAllKeys().size() == 0));
        REQUIRE_FALSE((fourManyMany.getAllKeys().size() == 0));
    }

        // Positive test cases for getAllValues()
    SECTION("getAllValues() positive test cases") {
        REQUIRE(onePair.getAllValues().size() == 1);
        REQUIRE(oneKeyFourVals.getAllValues().size() == 4);
        REQUIRE(fourKeysOneVal.getAllValues().size() == 1);
        REQUIRE(fourPairs.getAllValues().size() == 4);
        REQUIRE(fourManyMany.getAllValues().size() == 4);
    }

        // Negative test cases for getAllValues()
    SECTION("getAllValues() negative test cases") {
        REQUIRE_FALSE(onePair.getAll().empty());
        REQUIRE_FALSE(oneKeyFourVals.getAll().empty());
        REQUIRE_FALSE(fourKeysOneVal.getAll().empty());
        REQUIRE_FALSE(fourPairs.getAll().empty());
        REQUIRE_FALSE(fourManyMany.getAll().empty());
    }
}

TEST_CASE("[PKB PkbTable] getAll") {
    // each PKB state
    PkbTable<std::string, int> onePair;
    PkbTable<std::string, int> oneKeyFourVals;
    PkbTable<std::string, int> fourKeysOneVal;
    PkbTable<std::string, int> fourPairs; // 4 distinct pairs that are not related to each other
    PkbTable<std::string, int> fourManyMany; // 4 keys with many-to-many relations to 4 values (complete graph)

    onePair.add("1", 1);
    oneKeyFourVals.add("key", 1);
    oneKeyFourVals.add("key", 2);
    oneKeyFourVals.add("key", 3);
    oneKeyFourVals.add("key", 4);
    fourKeysOneVal.add("key1", 1);
    fourKeysOneVal.add("key2", 1);
    fourKeysOneVal.add("key3", 1);
    fourKeysOneVal.add("key4", 1);
    fourPairs.add("key1", 1);
    fourPairs.add("key2", 2);
    fourPairs.add("key3", 3);
    fourPairs.add("key4", 4);
    fourManyMany.add("key1", 1);
    fourManyMany.add("key2", 1);
    fourManyMany.add("key3", 1);
    fourManyMany.add("key4", 1);
    fourManyMany.add("key1", 2);
    fourManyMany.add("key2", 2);
    fourManyMany.add("key3", 2);
    fourManyMany.add("key4", 2);
    fourManyMany.add("key1", 3);
    fourManyMany.add("key2", 3);
    fourManyMany.add("key3", 3);
    fourManyMany.add("key4", 3);
    fourManyMany.add("key1", 4);
    fourManyMany.add("key2", 4);
    fourManyMany.add("key3", 4);
    fourManyMany.add("key4", 4);

    // Positive test cases for getAll()
    SECTION("getAllKeys() positive test cases") {
        REQUIRE(onePair.getAll().size() == 1);
        REQUIRE(oneKeyFourVals.getAll().size() == 4);
        REQUIRE(fourKeysOneVal.getAll().size() == 4);
        REQUIRE(fourPairs.getAll().size() == 4);
        REQUIRE(fourManyMany.getAll().size() == 16);

        // check the elements of the table

        // onePair state
        auto onePairResults = onePair.getAll();
        REQUIRE(onePairResults[0][0] == "1");
        REQUIRE(onePairResults[0][1] == "1");

        // oneKeyFourVals state
        auto oneKeyFourValsResults = oneKeyFourVals.getAll();
        for (int i = 1; i <= 4; ++i) {
            REQUIRE(oneKeyFourValsResults[i - 1][0] == "key");
        }
        bool oneFound = false;
        bool twoFound = false;
        bool threeFound = false;
        bool fourFound = false;
        // loop through the results, if the value is found, set the corresponding bool to true
        for (const auto& result : oneKeyFourValsResults) {
            if (result[1] == "1") {
                oneFound = true;
            } else if (result[1] == "2") {
                twoFound = true;
            } else if (result[1] == "3") {
                threeFound = true;
            } else if (result[1] == "4") {
                fourFound = true;
            }
        }
        bool allFound = oneFound && twoFound && threeFound && fourFound;
        REQUIRE(allFound);

        // fourKeysOneVal state
        auto fourKeysOneValResults = fourKeysOneVal.getAll();
        for (int i = 1; i <= 4; ++i) {
            REQUIRE(fourKeysOneValResults[i - 1][1] == "1");
        }
        // loop through the results, if the key is found, set the corresponding bool to true
        bool key1Found = false;
        bool key2Found = false;
        bool key3Found = false;
        bool key4Found = false;
        for (const auto& result : fourKeysOneValResults) {
            if (result[0] == "key1") {
                key1Found = true;
            } else if (result[0] == "key2") {
                key2Found = true;
            } else if (result[0] == "key3") {
                key3Found = true;
            } else if (result[0] == "key4") {
                key4Found = true;
            }
        }
        bool allKeysFound = key1Found && key2Found && key3Found && key4Found;
        REQUIRE(allKeysFound);

        // fourPairs state
        auto fourPairsResults = fourPairs.getAll();
        // loop through the results, if the pair is found, set the corresponding bool to true
        bool pair1Found = false;
        bool pair2Found = false;
        bool pair3Found = false;
        bool pair4Found = false;
        for (const auto& result : fourPairsResults) {
            if (result[0] == "key1" && result[1] == "1") {
                pair1Found = true;
            } else if (result[0] == "key2" && result[1] == "2") {
                pair2Found = true;
            } else if (result[0] == "key3" && result[1] == "3") {
                pair3Found = true;
            } else if (result[0] == "key4" && result[1] == "4") {
                pair4Found = true;
            }
        }
        bool allPairsFound = pair1Found && pair2Found && pair3Found && pair4Found;
        REQUIRE(allPairsFound);


        // fourManyMany state
        auto fourManyManyResults = fourManyMany.getAll();
        // loop through the results, if the pair is found, set the corresponding bool to true
        bool pair11Found = false;
        bool pair12Found = false;
        bool pair13Found = false;
        bool pair14Found = false;
        bool pair21Found = false;
        bool pair22Found = false;
        bool pair23Found = false;
        bool pair24Found = false;
        bool pair31Found = false;
        bool pair32Found = false;
        bool pair33Found = false;
        bool pair34Found = false;
        bool pair41Found = false;
        bool pair42Found = false;
        bool pair43Found = false;
        bool pair44Found = false;

        // use a switch statement in a for loop
        for (const auto& result : fourManyManyResults) {
            switch (result[0][3]) { // idx 3 because the key is "key" + number
                case '1':
                    switch (result[1][0]) {
                        case '1':
                            pair11Found = true;
                            break;
                        case '2':
                            pair12Found = true;
                            break;
                        case '3':
                            pair13Found = true;
                            break;
                        case '4':
                            pair14Found = true;
                            break;
                    }
                    break;
                case '2':
                    switch (result[1][0]) {
                        case '1':
                            pair21Found = true;
                            break;
                        case '2':
                            pair22Found = true;
                            break;
                        case '3':
                            pair23Found = true;
                            break;
                        case '4':
                            pair24Found = true;
                            break;
                    }
                    break;
                case '3':
                    switch (result[1][0]) {
                        case '1':
                            pair31Found = true;
                            break;
                        case '2':
                            pair32Found = true;
                            break;
                        case '3':
                            pair33Found = true;
                            break;
                        case '4':
                            pair34Found = true;
                            break;
                    }
                    break;
                case '4':
                    switch (result[1][0]) {
                        case '1':
                            pair41Found = true;
                            break;
                        case '2':
                            pair42Found = true;
                            break;
                        case '3':
                            pair43Found = true;
                            break;
                        case '4':
                            pair44Found = true;
                            break;
                    }
                    break;
                default:
                    break;
            }
        }
        bool allCombisFound = pair11Found && pair12Found && pair13Found && pair14Found &&
                             pair21Found && pair22Found && pair23Found && pair24Found &&
                             pair31Found && pair32Found && pair33Found && pair34Found &&
                             pair41Found && pair42Found && pair43Found && pair44Found;
        REQUIRE(allCombisFound);
    }

    // Negative test cases for getAll()
    SECTION("getAllKeys() negative test cases") {
        REQUIRE_FALSE(onePair.getAll().empty());
        REQUIRE_FALSE(oneKeyFourVals.getAll().empty());
        REQUIRE_FALSE(fourKeysOneVal.getAll().empty());
        REQUIRE_FALSE(fourPairs.getAll().empty());
        REQUIRE_FALSE(fourManyMany.getAll().empty());
    }
}

// ai-gen end

// ai-gen start (gpt, 1, 0)
// prompt: https://platform.openai.com/playground/p/Ggj0170ehFqtNNTs8CbIzzIi?model=gpt-4&mode=chat

TEST_CASE("[PKB PkbTable] Stress Tests") {
    PkbTable<int, std::string> map;
    int load = 10000;

    // For keeping track of all the entries added
    std::unordered_map<int, std::set<std::string>> testEntries;
    std::unordered_map<std::string, std::set<int>> bkwdTestEntries;

    SECTION("add() Stress Test") {
        for(int i = 0; i < load; i++) {
            map.add(i, "val" + std::to_string(i));
            testEntries[i].insert("val" + std::to_string(i));
            bkwdTestEntries["val" + std::to_string(i)].insert(i);
        }
    }

    for(int i = 0; i < load; i++) {
        map.add(i, "val" + std::to_string(i));
    }

    SECTION("containsKey() Stress Test") {
        for(int i = 0; i < load; i++) {
            int randKey = rand() % load;
            REQUIRE(map.containsKey(randKey));
        }
    }

    SECTION("containsValue() Stress Test") {
        for(int i = 0; i < load; i++) {
            std::string randVal = "val" + std::to_string(rand() % load);
            REQUIRE(map.containsValue(randVal));
        }
    }

    SECTION("containsPair() Stress Test") {
        for(int i = 0; i < 5; i++) {
            int randKey = rand() % load;
            std::string randVal = "val" + std::to_string(randKey);
            REQUIRE(map.containsPair(randKey, randVal));
        }
    }

    SECTION("getRelatedValues() Stress Test") {
        for(int i = 0; i < 5; i++) {
            int randKey = rand() % load;
            std::vector<std::string> relatedVals = map.getRelatedValues(randKey);
            for(auto v : relatedVals) {
                REQUIRE(map.containsPair(randKey, v));
            }
        }
    }

    SECTION("getRelatedKeys() Stress Test") {
        for(int i = 0; i < 5; i++) {
            std::string randVal = "val" + std::to_string(rand() % load);
            std::vector<int> relatedKeys = map.getRelatedKeys(randVal);
            for(int key: relatedKeys) {
                REQUIRE(map.containsPair(key, randVal));
            }
        }
    }

    SECTION("getAllKeys() Stress Test") {
        Table allKeys = map.getAllKeys();
        REQUIRE(allKeys.size() == load);
        // checking correctness may majorly influence time taken to run the test
    }

    SECTION("getAllValues() Stress Test") {
        Table allValues = map.getAllValues();
        REQUIRE(allValues.size() == load);
    }

    SECTION("getAll() Stress Test") {
        Table allEntries = map.getAll();
        REQUIRE(allEntries.size() == load);
    }
}
// ai-gen end