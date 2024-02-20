// Author: Ian Hong
#include "pkb/PopulatePKB.h"
#include "pkb/PKBStorage.h"
#include "catch.hpp"
using namespace std;

TEST_CASE("[PKB PopulatePkb] exists") {
    // ai-gen start (copilot, 1, e)
    // prompt: used copilot
    shared_ptr<PKBStorage> p = make_shared<PKBStorage>();
    PopulatePKB pp(p);
    SECTION("Initialize with shared ptr, should exist") {
        REQUIRE(pp.exists());
    }

}
TEST_CASE("[PKB PopulatePkb] addParent") {
    shared_ptr<PKBStorage> p = make_shared<PKBStorage>();
    PopulatePKB pp(p);
    SECTION("add parent 1, 2, can add") {
        REQUIRE(pp.addParent(1, 2));
    }
    // ai-gen end
}

TEST_CASE("[PKB PopulatePkb] hasParent") {
    shared_ptr<PKBStorage> p = make_shared<PKBStorage>();
    PopulatePKB pp(p);
    pp.addParent(4, 5);
    SECTION("4 is parent of 5, 4 has parent of 5") {
        REQUIRE(p->parentTable->hasParent(5));
    }

    SECTION("2 not in table, 2 has no parent") {
        REQUIRE(!(p->parentTable->hasParent(2)));
    }
    SECTION("4 is parent but has no parent, 4 has no parent") {
        REQUIRE(!(p->parentTable->hasParent(4)));
    }
}
