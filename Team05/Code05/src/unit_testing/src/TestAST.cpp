
#include "TNode.h"
#include "pkb/PKB.h"
#include "catch.hpp"
using namespace std;
void require(bool b) {
    REQUIRE(b);
}

TEST_CASE("1st Test") {

    TNode T;
	
	
	
    require(1 == 1);
}

TEST_CASE("Test PKB Parent Table") {
    // TODO: move test into its file after test-scaffold is merged
    PKB p;

    SECTION("Test if parent table is created") {
        REQUIRE(p.parentTable != nullptr);
    }
    SECTION("Insert") {
        REQUIRE(p.parentTable->addParent(1, 2));
    }

    // test if the parent-child pair 1, 2 is added to the ParentTable using hasParent and hasChild
    p.parentTable->addParent(1, 2);
    SECTION("hasParent") {
        REQUIRE(p.parentTable->hasParent(2));
    }
    SECTION("hasChild") {
        REQUIRE(p.parentTable->hasChildren(1));
    }

    // test if the parent of 2 is 1
    SECTION("isParent") {
        REQUIRE(p.parentTable->isParent(1, 2));
    }
    SECTION("getParent") {
        REQUIRE(p.parentTable->getParent(2) == 1);
    }

    // test if the children of 1 are 2, 3, 4
    p.parentTable->addParent(1, 3);
    p.parentTable->addParent(1, 4);
    SECTION("getChildren") {
        REQUIRE(p.parentTable->getChildren(1).size() == 3);
        auto children = p.parentTable->getChildren(1);
        std::sort(children.begin(), children.end());
        REQUIRE(children[0] == 2);
        REQUIRE(children[1] == 3);
        REQUIRE(children[2] == 4);
    }
    SECTION("getSize") {
        REQUIRE(p.parentTable->getSize() == 3);
    }
}


