// include "sp/yourClass.h"
// include "sp/yourClass.cpp"
// include "pkb/yourClass.h"
// include "pkb/yourClass.cpp"
// include "qps/yourClass.h"
// include "qps/yourClass.cpp"
// TODO: should we use namespaces for each component?

#include "catch.hpp"
using namespace std;

// Integration Tests for PKB
TEST_CASE("[IntegTestPKB] SP Integration") {
    // TODO: Initialize Stub for SP

    SECTION("Use Stub to test a feature") {
        REQUIRE(1 == 1);
    }
}

TEST_CASE("[IntegTestPKB] QPS Integration") {
    // TODO: Initialize Stub for QPS

    SECTION("Use Stub to test a feature") {
        REQUIRE(1 == 1);
    }
}
