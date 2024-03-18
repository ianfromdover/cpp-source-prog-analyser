//
// Created by yewme on 26/2/2024.
//

#include "catch.hpp"
#include "pkb/apis/QueryPkb.h"
#include <memory>

std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
QueryPkb queryPKB(pkb);

bool isPresent(const std::vector<std::vector<std::string>>& vec, const std::vector<std::vector<std::string>>& elements) {
    return std::all_of(elements.begin(), elements.end(), [&](const auto& element) {
        return std::find(vec.begin(), vec.end(), element) != vec.end();
    });
}

TEST_CASE("Test isPresent testing helper function") {

    std::vector<std::vector<std::string>> test = {{"1"}};
    REQUIRE(test.size() == 1);
    REQUIRE(isPresent(test, {{"1"}}));
    REQUIRE(!isPresent(test, {{"2"}}));
}

TEST_CASE("Test toVecVecStr conversion methods") {

//    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
//    QueryPkb queryPKB(pkb);

    SECTION("Test for string vector") {
        std::vector<std::string> input = {"1", "2", "3"};
        auto converted = queryPKB.toVecVecStr(input);
        std::vector<std::string> firstElem = {"1"};
        std::vector<std::string> secondElem = {"2"};
        std::vector<std::string> thirdElem = {"3"};

        REQUIRE(converted.size() == 3);
        REQUIRE(converted[0] == firstElem);
        REQUIRE(converted[1] == secondElem);
        REQUIRE(converted[2] == thirdElem);
    }

    SECTION("Test for int vector") {
        std::vector<int> input = {1, 2, 3};
        auto converted = queryPKB.toVecVecStr(input);
        std::vector<std::string> firstElem = {"1"};
        std::vector<std::string> secondElem = {"2"};
        std::vector<std::string> thirdElem = {"3"};

        REQUIRE(converted.size() == 3);
        REQUIRE(converted[0] == firstElem);
        REQUIRE(converted[1] == secondElem);
        REQUIRE(converted[2] == thirdElem);
    }
}


TEST_CASE("Test QueryPKB getCall methods") {

//    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
//    QueryPkb queryPKB(pkb);

    // Add records to callTable
    pkb->callTable->addCall(1, "proc1");
    pkb->callTable->addCall(2, "proc2");
    pkb->callTable->addCall(3, "proc3");
    pkb->callTable->addCall(4, "proc3");

    SECTION("Test getCallByNum() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getCallByNum(1);
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"proc1"}}));

    }

    SECTION("Test getCallByProc() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getCallByProc("proc3");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"3"}, {"4"}}));

    }

    SECTION("Test getCallTable() method") {

        // Retrieve callTable and verify its contents
        std::vector<std::vector<std::string>> callTable = queryPKB.getCallTable();
        REQUIRE(callTable.size() == 4);
        REQUIRE(isPresent(callTable, {{"1", "proc1"}, {"2", "proc2"}, {"3", "proc3"}, {"4", "proc3"}}));

    }
}


TEST_CASE("Test QueryPKB getProc methods") {

//    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
//    QueryPkb queryPKB(pkb);

    // Add records to procTable
    pkb->procedureTable->addProc("proc1");
    pkb->procedureTable->addProc("proc2");
    pkb->procedureTable->addProc("proc3");

    SECTION("Test getProcByName() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getProcTable();
        REQUIRE(test.size() == 3);
        REQUIRE(isPresent(test, {{"proc1"}, {"proc2"}, {"proc3"}}));

    }

    SECTION("Test getProcTable() method") {

        // Retrieve procTable and verify its contents
        std::vector<std::vector<std::string>> procTable = queryPKB.getProcTable();
        REQUIRE(procTable.size() == 3);
        REQUIRE(isPresent(procTable, {{"proc1"}, {"proc2"}, {"proc3"}}));

    }
}


TEST_CASE("Test QueryPKB getRead methods") {

//    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
//    QueryPkb queryPKB(pkb);

    // Add records to readTable
    pkb->readTable->addRead(1, "x");
    pkb->readTable->addRead(2, "y");
    pkb->readTable->addRead(3, "z");
    pkb->readTable->addRead(4, "y");

    SECTION("Test getReadByNum() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getReadByNum(1);
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"x"}}));

    }

    SECTION("Test getReadByVar() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getReadByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getReadTable() method") {

        // Retrieve readTable and verify its contents
        std::vector<std::vector<std::string>> readTable = queryPKB.getReadTable();
        REQUIRE(readTable.size() == 4);
        REQUIRE(isPresent(readTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPKB getIf methods") {

//    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
//    QueryPkb queryPKB(pkb);

    // Add records to readTable
    pkb->ifTable->addIf(1, "x");
    pkb->ifTable->addIf(2, "y");
    pkb->ifTable->addIf(3, "z");
    pkb->ifTable->addIf(4, "y");

    SECTION("Test getIfByNum() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getIfByNum(1);
        std::vector<std::vector<std::string>> testResult = {{"x"}};
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"x"}}));

    }

    SECTION("Test getIfByVar() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getIfByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getIfTable() method") {

        // Retrieve readTable and verify its contents
        std::vector<std::vector<std::string>> ifTable = queryPKB.getIfTable();
        REQUIRE(ifTable.size() == 4);
        REQUIRE(isPresent(ifTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPKB getWhile methods") {

//    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
//    QueryPkb queryPKB(pkb);

    // Add records to whileTable
    pkb->whileTable->addWhile(1, "x");
    pkb->whileTable->addWhile(2, "y");
    pkb->whileTable->addWhile(3, "z");
    pkb->whileTable->addWhile(4, "y");

    SECTION("Test getWhileByNum() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getWhileByNum(1);
        std::vector<std::vector<std::string>> testResult = {{"x"}};
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"x"}}));

    }

    SECTION("Test getWhileByVar() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getWhileByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getWhileTable() method") {

        // Retrieve whileTable and verify its contents
        std::vector<std::vector<std::string>> whileTable = queryPKB.getWhileTable();
        REQUIRE(whileTable.size() == 4);
        REQUIRE(isPresent(whileTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPKB getPrint methods") {

//    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
//    QueryPkb queryPKB(pkb);

    // Add records to printTable
    pkb->printTable->addPrint(1, "x");
    pkb->printTable->addPrint(2, "y");
    pkb->printTable->addPrint(3, "z");
    pkb->printTable->addPrint(4, "y");
    pkb->printTable->addPrint(4, "z");

    SECTION("Test getPrintByNum() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getPrintByNum(4);
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"y"}, {"z"}}));

    }

    SECTION("Test getPrintByVar() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getPrintByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getPrintTable() method") {

        // Retrieve printTable and verify its contents
        std::vector<std::vector<std::string>> printTable = queryPKB.getPrintTable();
        REQUIRE(printTable.size() == 5);
        REQUIRE(isPresent(printTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"4", "z"}}));

    }
}


TEST_CASE("Test QueryPKB getStmt methods") {

//    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
//    QueryPkb queryPKB(pkb);

    // Add records to stmtTable
    pkb->statementTable->addFinalStatementNo(0); // proc name line, not counted in stmts
    pkb->statementTable->addFinalStatementNo(1);
    pkb->statementTable->addFinalStatementNo(2);
    pkb->statementTable->addFinalStatementNo(3);
    pkb->statementTable->addFinalStatementNo(4); // bracket, not counted in stmts

//    SECTION("Test getStmtByNum() method") {
//
//    }

    SECTION("Test getStmtTable() method") {

        // Retrieve stmtTable and verify its contents
        std::vector<std::vector<std::string>> stmtTable = queryPKB.getStmtTable();
        REQUIRE(stmtTable.size() == 3);
        REQUIRE(isPresent(stmtTable, {{"1"}, {"2"}, {"3"}}));

    }
}


TEST_CASE("Test QueryPKB getVar methods") {

//    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
//    QueryPkb queryPKB(pkb);

    // Add records to varTable
    pkb->varTable->addVar(1, "x");
    pkb->varTable->addVar(2, "y");
    pkb->varTable->addVar(3, "z");
    pkb->varTable->addVar(4, "x");
    pkb->varTable->addVar(5, "z");

//    SECTION("Test getVarByName() method") {
//
//    }

//    SECTION("Test getVarByNum() method") {
//
//    }

    SECTION("Test getVarTable() method") {

        // Retrieve procTable and verify its contents
        std::vector<std::vector<std::string>> varTable = queryPKB.getVarTable();
        REQUIRE(varTable.size() == 5);
        REQUIRE(isPresent(varTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "x"}, {"5", "z"}}));

    }
}


TEST_CASE("Test QueryPKB getConst methods") {

//    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
//    QueryPkb queryPKB(pkb);

    // Add records to constTable
    pkb->constTable->addConst(1, 4);
    pkb->constTable->addConst(2, 2);
    pkb->constTable->addConst(3, 0);

//    SECTION("Test getConstByNum() method") {
//
//    }

    SECTION("Test getConstTable() method") {

        // Retrieve constTable and verify its contents
        std::vector<std::vector<std::string>> constTable = queryPKB.getConstTable();
        REQUIRE(constTable.size() == 3);
        REQUIRE(isPresent(constTable, {{"1", "4"}, {"2", "2"}, {"3", "0"}}));

    }
}
