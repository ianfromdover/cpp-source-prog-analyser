//
// Created by yewme on 26/2/2024.
//

/*
#include "catch.hpp"
#include "pkb/apis/PopulatePKB.h"

TEST_CASE("Test addRead function") {
    // Create a mock PKBStorage object
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);

    // Add a record to the read table
    REQUIRE(populatePKB.addRead(1, "y"));

    // Check if the entry was added to the table
    auto table = pkb->readTable->getTable();
    bool entryFound = false;
    for (const auto& record : table) {
        if (record[0] == "1" && record[1] == "y") {
            entryFound = true;
            break;
        }
    }
    REQUIRE(entryFound);
}

TEST_CASE("Test Table") {
    SECTION("AddRecord") {
        Table table;

        REQUIRE(table.addRecord("1", "x"));
        REQUIRE(table.addRecord("2", "y"));

        auto tableData = table.getTable();
        REQUIRE(tableData.size() == 2);
        REQUIRE(tableData[0][0] == "1");
        REQUIRE(tableData[0][1] == "x");
        REQUIRE(tableData[1][0] == "2");
        REQUIRE(tableData[1][1] == "y");
    }
}

TEST_CASE("Test addWhile function") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);
    REQUIRE(populatePKB.addPatternWhile(3, "while1"));
    auto table = pkb->whileTable->getTable();
    REQUIRE(table.size() == 1);
    REQUIRE(table[0][0] == "3");
    REQUIRE(table[0][1] == "while1");
}

TEST_CASE("Test addPrint function") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);
    REQUIRE(populatePKB.addPrint(4, "print1"));
    auto table = pkb->printTable->getTable();
    REQUIRE(table.size() == 1);
    REQUIRE(table[0][0] == "4");
    REQUIRE(table[0][1] == "print1");
}

TEST_CASE("Test addFinalStatementNo function") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);
    REQUIRE(populatePKB.addFinalStatementNo(5));
    auto table = pkb->statementTable->getTable();
    REQUIRE(table.size() == 1);
    REQUIRE(table[0][0] == "5");
    REQUIRE(table[0][1] == "5");
}

TEST_CASE("Test addProcedure function") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);
    REQUIRE(populatePKB.addProcedure("proc2"));
    auto table = pkb->procedureTable->getTable();
    REQUIRE(table.size() == 1);
    REQUIRE(table[0][0] == "proc2");
    REQUIRE(table[0][1] == "proc2");
}

TEST_CASE("Test addVar function") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);
    REQUIRE(populatePKB.addVar(6, "x"));
    auto table = pkb->variableTable->getTable();
    REQUIRE(table.size() == 1);
    REQUIRE(table[0][0] == "6");
    REQUIRE(table[0][1] == "x");
}

TEST_CASE("Test addConst function") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);
    REQUIRE(populatePKB.addConst(7, 42));
    auto table = pkb->constantTable->getTable();
    REQUIRE(table.size() == 1);
    REQUIRE(table[0][0] == "7");
    REQUIRE(table[0][1] == "42");
}

TEST_CASE("Test addFollows function") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);
    REQUIRE(populatePKB.addFollows(8, 9));
    auto table = pkb->followsTable->getTable();
    REQUIRE(table.size() == 1);
    REQUIRE(table[0][0] == "8");
    REQUIRE(table[0][1] == "9");
}

TEST_CASE("Test addFollowsT function") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);
    REQUIRE(populatePKB.addFollowsT(10, 11));
    auto table = pkb->followsTTable->getTable();
    REQUIRE(table.size() == 1);
    REQUIRE(table[0][0] == "10");
    REQUIRE(table[0][1] == "11");
}

TEST_CASE("Test addParent function") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);
    REQUIRE(populatePKB.addParent(12, 13));
    auto table = pkb->parentTable->getTable();
    REQUIRE(table.size() == 1);
    REQUIRE(table[0][0] == "12");
    REQUIRE(table[0][1] == "13");
}

TEST_CASE("Test addParentT function") {
    std::shared_ptr<PKBStorage> pkb = std::make_shared<PKBStorage>();
    PopulatePKB populatePKB(pkb);
    REQUIRE(populatePKB.addParentT(14, 15));
    auto table = pkb->parentTTable->getTable();
    REQUIRE(table.size() == 1);
    REQUIRE(table[0][0] == "14");
    REQUIRE(table[0][1] == "15");
}

 */