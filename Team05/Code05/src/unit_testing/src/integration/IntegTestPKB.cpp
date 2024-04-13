#include "catch.hpp"
#include "pkb/apis/PkbStorage.h"
#include "pkb/apis/PopulatePkb.h"
#include "pkb/apis/QueryPkb.h"
#include "qps/QPS.h"

using namespace std;

// Integration Tests for PKB
TEST_CASE("[IntegTestPKB] SP Integration") {
    // Initialize Stub for SP

    SECTION("Use Stub to test a feature") {
        REQUIRE(1 == 1);
    }
}

TEST_CASE("[IntegTestPKB] QPS Integration") {

    std::shared_ptr<PkbStorage> p=std::make_shared<PkbStorage>();
    std::shared_ptr<PopulatePkb> pkb = make_shared<PopulatePkb>(p);
    QueryPkb pkb1 = QueryPkb(p);
    QPS qps = QPS(std::make_shared<QueryPkb>(pkb1));

    SECTION("Test Follows") {
        pkb->addFinalStatementNo(1);
        pkb->addFinalStatementNo(2);
        pkb->addFinalStatementNo(3);
        pkb->addFinalStatementNo(4);
        pkb->addFinalStatementNo(5);
        pkb->addFollows(2, 3);
        pkb->addFollows(3, 4);
        pkb->addFollows(4, 5);

        Str query = "stmt s; Select s such that Follows(2, s)";
        std::vector<std::string> result = qps.evaluate(query);
        std::vector<std::string> expected = {"3"};
        REQUIRE(result == expected);
    }

    SECTION("Test Follows*") {
        pkb->addFinalStatementNo(1);
        pkb->addFinalStatementNo(2);
        pkb->addFinalStatementNo(3);
        pkb->addFinalStatementNo(4);
        pkb->addFinalStatementNo(5);
        pkb->addFollowsT(2, 3);
        pkb->addFollowsT(3, 4);
        pkb->addFollowsT(2, 4);

        Str query = "stmt s; Select s such that Follows*(2, s)";
        std::vector<std::string> result = qps.evaluate(query);
        std::vector<std::string> expected = {"3", "4"};
        REQUIRE(result == expected);
    }

    SECTION("Test Parent") {
        pkb->addFinalStatementNo(1);
        pkb->addFinalStatementNo(2);
        pkb->addFinalStatementNo(3);
        pkb->addFinalStatementNo(4);
        pkb->addFinalStatementNo(5);
        pkb->addParent(2, 3);
        pkb->addParent(3, 4);
        pkb->addParent(4, 5);

        Str query = "stmt s; Select s such that Parent(2, s)";
        std::vector<std::string> result = qps.evaluate(query);
        std::vector<std::string> expected = {"3"};
        REQUIRE(result == expected);
    }

    SECTION("Test Parent*") {
        pkb->addFinalStatementNo(1);
        pkb->addFinalStatementNo(2);
        pkb->addFinalStatementNo(3);
        pkb->addFinalStatementNo(4);
        pkb->addFinalStatementNo(5);
        pkb->addParentT(2, 3);
        pkb->addParentT(3, 4);
        pkb->addParentT(2, 4);

        Str query = "stmt s; Select s such that Parent*(2, s)";
        std::vector<std::string> result = qps.evaluate(query);
        std::vector<std::string> expected = {"3", "4"};
        REQUIRE(result == expected);
    }

}


