//
// Created by yewme on 26/2/2024.
//

#include "catch.hpp"
#include "pkb/apis/PKBStorage.h"

TEST_CASE("Test PKBStorage class") {
    PKBStorage pkb;

    SECTION("Test if all tables are initialized") {
        REQUIRE(pkb.readTable != nullptr);
        REQUIRE(pkb.callTable != nullptr);
        REQUIRE(pkb.ifTable != nullptr);
        REQUIRE(pkb.whileTable != nullptr);
        REQUIRE(pkb.printTable != nullptr);
        REQUIRE(pkb.statementTable != nullptr);
        REQUIRE(pkb.procedureTable != nullptr);
        REQUIRE(pkb.variableTable != nullptr);
        REQUIRE(pkb.constantTable != nullptr);
        REQUIRE(pkb.assignTable != nullptr);
        REQUIRE(pkb.followsTable != nullptr);
        REQUIRE(pkb.followsTTable != nullptr);
        REQUIRE(pkb.parentTable != nullptr);
        REQUIRE(pkb.parentTTable != nullptr);
        REQUIRE(pkb.modifiesSTable != nullptr);
        REQUIRE(pkb.usesSTable != nullptr);
        REQUIRE(pkb.modifiesPTable != nullptr);
        REQUIRE(pkb.usesPTable != nullptr);
    }

    SECTION("Test adding records to tables") {
        REQUIRE(pkb.readTable->addRecord("1", "x"));
        REQUIRE(pkb.readTable->getTable().size() == 1);
        REQUIRE(pkb.readTable->getTable()[0][0] == "1");
        REQUIRE(pkb.readTable->getTable()[0][1] == "x");

        REQUIRE(pkb.assignTable->addRecord("2", "a=5"));
        REQUIRE(pkb.assignTable->getTable().size() == 1);
        REQUIRE(pkb.assignTable->getTable()[0][0] == "2");
        REQUIRE(pkb.assignTable->getTable()[0][1] == "a=5");

        // Add more similar test cases for other tables
    }

    SECTION("Test adding records to callTable") {
        REQUIRE(pkb.callTable->addRecord("1", "proc1"));
        REQUIRE(pkb.callTable->getTable().size() == 1);
        REQUIRE(pkb.callTable->getTable()[0][0] == "1");
        REQUIRE(pkb.callTable->getTable()[0][1] == "proc1");

    }

    SECTION("Test adding records to ifTable") {
        REQUIRE(pkb.ifTable->addRecord("2", "if (x) then"));
        REQUIRE(pkb.ifTable->getTable().size() == 1);
        REQUIRE(pkb.ifTable->getTable()[0][0] == "2");
        REQUIRE(pkb.ifTable->getTable()[0][1] == "if (x) then");

    }
}