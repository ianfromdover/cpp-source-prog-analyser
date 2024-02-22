// Author: Ian Hong
#include "pkb/PopulatePKB.h"
#include "pkb/PKBStorage.h"
#include "catch.hpp"
using namespace std;

TEST_CASE("[PKB ParentTable] Init") {
    PKBStorage p;
    SECTION("Check != null, not null") {
        REQUIRE(p.parentTable != nullptr);
    }
}
TEST_CASE("[PKB ParentTable] addParent") {
    PKBStorage p;
    SECTION("+ve stmt no, success") {
        REQUIRE(p.parentTable->addParent(1, 2));
    }
}

TEST_CASE("[PKB ParentTable] hasParent") {
    PKBStorage p;
    // test if the parent-child pair 1, 2 is added to the ParentTable using hasParent and hasChild
    p.parentTable->addParent(1, 2);
    SECTION("1 parent of 2, has child 2") {
        REQUIRE(p.parentTable->hasParent(2));
    }
}
TEST_CASE("[PKB ParentTable] hasChild") {
    PKBStorage p;
    p.parentTable->addParent(1, 2);
    SECTION("1 parent of 2, has parent 1") {
        REQUIRE(p.parentTable->hasChildren(1));
    }
}

TEST_CASE("[PKB ParentTable] isParent") {
    PKBStorage p;
    p.parentTable->addParent(1, 2);
    // test if the parent of 2 is 1
    SECTION("1 parent of 2, 1 is parent of 2") {
        REQUIRE(p.parentTable->isParent(1, 2));
    }
}

TEST_CASE("[PKB ParentTable] getParent") {
    PKBStorage p;
    p.parentTable->addParent(1, 2);
    SECTION("1 parent of 2, getting parent of 2 gives 1") {
        REQUIRE(p.parentTable->getParent(2) == 1);
    }
}

// test if the children of 1 are 2, 3, 4
TEST_CASE("[PKB ParentTable] getChildren") {
    PKBStorage p;
    p.parentTable->addParent(1, 2);
    p.parentTable->addParent(1, 3);
    p.parentTable->addParent(1, 4);
    SECTION("1 parent of 2, 3, 4, size is 3") {
        REQUIRE(p.parentTable->getChildren(1).size() == 3);
    }
    SECTION("1 parent of 2, 3, 4, getting children of 1 gives 2, 3, 4") {
        auto children = p.parentTable->getChildren(1);
        std::sort(children.begin(), children.end());
        REQUIRE(children[0] == 2);
        REQUIRE(children[1] == 3);
        REQUIRE(children[2] == 4);
    }
}

TEST_CASE("[PKB ParentTable] getSize") {
    PKBStorage p;
    p.parentTable->addParent(1, 2);
    p.parentTable->addParent(1, 3);
    p.parentTable->addParent(1, 4);
    SECTION("3 relationships, size is 3") {
        REQUIRE(p.parentTable->getSize() == 3);
    }
}
