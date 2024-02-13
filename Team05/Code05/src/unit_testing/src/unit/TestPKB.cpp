// Author: Ian Hong
#include "pkb/PKB.h"

#include "catch.hpp"
using namespace std;

TEST_CASE("[TestPKB] Test Tables") {
    PKB pkb();
    // ai-gen start (copilot, 1, e)
    // prompt: used copilot
    SECTION("Initialise PKB") {
        /*
        REQUIRE(pkb.varTable->getSize() == 0);
        REQUIRE(pkb.constTable->getSize() == 0);
        REQUIRE(pkb.procTable->getSize() == 0);
        REQUIRE(pkb.stmtTable->getSize() == 0);
        REQUIRE(pkb.parentTable->getSize() == 0);
        REQUIRE(pkb.followsTable->getSize() == 0);
        REQUIRE(pkb.usesTable->getSize() == 0);
        REQUIRE(pkb.modifiesTable->getSize() == 0);
        */
    }
    // ai-gen end
}

TEST_CASE("[TestPKB] Test Population") {
    PKB pkb();
    SECTION("Populate FollowsT") {
    }
    SECTION("Populate ParentT") {
    }
}
