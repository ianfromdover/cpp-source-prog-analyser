//
// Created by yewme on 26/2/2024.
//

#include "catch.hpp"
#include "pkb/apis/QueryPKB.h"
#include <memory>

TEST_CASE("Test QueryPKB class") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    QueryPKB queryPKB(pkb);

    SECTION("Test getRead() method") {
        // Add records to readTable
        pkb->readTable->addRecord("1", "x");
        pkb->readTable->addRecord("2", "y");

        // Retrieve readTable and verify its content
        std::vector<std::vector<std::string>> readTable = queryPKB.getRead();
        REQUIRE(readTable.size() == 2);
        REQUIRE(readTable[0][0] == "1");
        REQUIRE(readTable[0][1] == "x");
        REQUIRE(readTable[1][0] == "2");
        REQUIRE(readTable[1][1] == "y");
    }

    SECTION("Test getCallStmt() method") {
        // Add records to callTable
        pkb->callTable->addRecord("1", "proc1");
        pkb->callTable->addRecord("2", "proc2");

        // Retrieve callTable and verify its content
        std::vector<std::vector<std::string>> callTable = queryPKB.getCallStmt();
        REQUIRE(callTable.size() == 2);
        REQUIRE(callTable[0][0] == "1");
        REQUIRE(callTable[0][1] == "proc1");
        REQUIRE(callTable[1][0] == "2");
        REQUIRE(callTable[1][1] == "proc2");
    }
}
