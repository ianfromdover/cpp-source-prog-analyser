//
// Created by yewme on 26/2/2024.
//

/*
#include "catch.hpp"
#include "pkb/apis/PopulatePKB.h"
#include "pkb/apis/PKBStorage.h"
#include "pkb/apis/QueryPKB.h"

TEST_CASE("Integration test: PopulatePKB, PKBStorage, and QueryPKB") {
    // Create PKBStorage instance
    std::shared_ptr<PKBStorage> pkbStorage = std::make_shared<PKBStorage>();

    // Create PopulatePKB instance with PKBStorage
    PopulatePKB populatePKB(pkbStorage);

    // Create QueryPKB instance with PKBStorage
    QueryPKB queryPKB(pkbStorage);

    SECTION("Test adding data to PKBStorage through PopulatePKB and querying through QueryPKB") {
        // Add data using PopulatePKB methods
        populatePKB.addRead(1, "x");
        populatePKB.addCallStmt(2, "proc1");

        // Query data using QueryPKB methods
        Table readTable = queryPKB.getRead();
        REQUIRE(readTable.size() == 1);
        REQUIRE(readTable[0][0] == "1");
        REQUIRE(readTable[0][1] == "x");

        Table callTable = queryPKB.getCallStmt();
        REQUIRE(callTable.size() == 1);
        REQUIRE(callTable[0][0] == "2");
        REQUIRE(callTable[0][1] == "proc1");
    }

    SECTION("Test adding data to PKBStorage directly and querying through QueryPKB") {
        // Add data directly to PKBStorage
        pkbStorage->readTable->addRecord("1", "x");
        pkbStorage->callTable->addRecord("2", "proc1");

        // Query data using QueryPKB methods
        Table readTable = queryPKB.getRead();
        REQUIRE(readTable.size() == 1);
        REQUIRE(readTable[0][0] == "1");
        REQUIRE(readTable[0][1] == "x");

        Table callTable = queryPKB.getCallStmt();
        REQUIRE(callTable.size() == 1);
        REQUIRE(callTable[0][0] == "2");
        REQUIRE(callTable[0][1] == "proc1");
    }

}

 */