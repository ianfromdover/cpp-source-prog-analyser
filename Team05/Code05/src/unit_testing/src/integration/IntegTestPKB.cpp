// include "sp/yourClass.h"
// include "sp/yourClass.cpp"
// include "pkb/yourClass.h"
// include "pkb/yourClass.cpp"
// include "qps/yourClass.h"
// include "qps/yourClass.cpp"

#include "catch.hpp"
using namespace std;

// Integration Tests for PKB
TEST_CASE("[IntegTestPKB] SP Integration") {
    // Initialize Stub for SP

    SECTION("Use Stub to test a feature") {
        REQUIRE(1 == 1);
    }
}

TEST_CASE("[IntegTestPKB] QPS Integration") {
    // Initialize Stub for QPS

    SECTION("Use Stub to test a feature") {
        REQUIRE(1 == 1);
    }
}
