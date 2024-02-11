
#include "TNode.h"
#include "pkb/PKB.h"
#include "pkb/PKB.cpp"
// add tables and populate files too


#include "catch.hpp"
using namespace std;
void require(bool b) {
    REQUIRE(b);
}

TEST_CASE("1st Test") {

    TNode T;
	
	
	
    require(1 == 1);
}

TEST_CASE("Test PKB Table") {
    // TODO: move test into its file after test-scaffold is merged
    PKB pkb();

    SECTION("Test Parent Table") {
        // ai-gen start (copilot, 1, e)
        // prompt: used copilot
        // wrote comments and copilot generated the code

        // create a ParentTable
        pkb().parentTable = make_shared<ParentTable>();
        // test if the ParentTable is created
        REQUIRE(pkb().parentTable != nullptr);
        // add a parent-child pair 1, 2 to the ParentTable
        REQUIRE(pkb().parentTable->addParent(1, 2));
        // test if the parent-child pair 1, 2 is added to the ParentTable using hasParent and hasChild
        REQUIRE(pkb().parentTable->hasParent(2));
        REQUIRE(pkb().parentTable->hasChild(1));
        REQUIRE(pkb().parentTable->isParent(1, 2));
        // test if the parent of 2 is 1
        REQUIRE(pkb().parentTable->getParent(2) == 1);

        // add a parent-child pair 1, 3 to the ParentTable
        REQUIRE(pkb().parentTable->addParent(1, 3));
        // test if the children of 1 are 2 and 3
        REQUIRE(pkb().parentTable->getChildren(1).size() == 2);
        REQUIRE(pkb().parentTable->getChildren(1)[0] == 2);
        REQUIRE(pkb().parentTable->getChildren(1)[1] == 3);
        // test if the siblings of 2 are 3
        REQUIRE(pkb().parentTable->getSiblings(2).size() == 1);
        REQUIRE(pkb().parentTable->getSiblings(2)[0] == 3);
        // test if the size of the ParentTable is 2
        REQUIRE(pkb().parentTable->getSize() == 2);
    }
}


