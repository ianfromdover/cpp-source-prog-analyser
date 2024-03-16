//
// Created by yewme on 26/2/2024.
//

#include "catch.hpp"
#include "pkb/apis/QueryPkb.h"
#include <memory>

std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
QueryPkb queryPKB(pkb);

TEST_CASE("Test toVecVecStr conversion methods") {

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
    // Add records to callTable
    pkb->callTable->addCall(1, "proc1");
    pkb->callTable->addCall(2, "proc2");
    pkb->callTable->addCall(3, "proc3");
    pkb->callTable->addCall(4, "proc3");

    SECTION("Test getCallByNum() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getCallByNum(1);
        std::vector<std::vector<std::string>> testResult = {{"proc1"}};
        REQUIRE(test.size() == 1);
        REQUIRE(test == testResult);

    }

    SECTION("Test getCallByProc() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getCallByProc("proc3");
        std::vector<std::vector<std::string>> testResult = {{"3"}, {"4"}};
        REQUIRE(test.size() == 2);
        REQUIRE(test == testResult);

    }

    SECTION("Test getCallTable() method") {

        // Retrieve callTable and verify its content
        std::vector<std::vector<std::string>> callTable = queryPKB.getCallTable();
        REQUIRE(callTable.size() == 4);
        REQUIRE(callTable[0][0] == "1");
        REQUIRE(callTable[0][1] == "proc1");
        REQUIRE(callTable[1][0] == "2");
        REQUIRE(callTable[1][1] == "proc2");
        REQUIRE(callTable[2][0] == "3");
        REQUIRE(callTable[2][1] == "proc3");
        REQUIRE(callTable[3][0] == "4");
        REQUIRE(callTable[3][1] == "proc3");

    }
}


TEST_CASE("Test QueryPKB getProc methods") {
    // Add records to callTable
    pkb->procedureTable->addProc("proc1");
    pkb->procedureTable->addProc("proc2");
    pkb->procedureTable->addProc("proc3");

    SECTION("Test getProcByName() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getProcTable();
        std::vector<std::vector<std::string>> testResult = {{"proc1"}, {"proc2"}, {"proc3"}};
        REQUIRE(test.size() == 3);
        REQUIRE(test == testResult);

    }

    SECTION("Test getProcTable() method") {

        // Retrieve procTable and verify its content
        std::vector<std::vector<std::string>> procTable = queryPKB.getProcTable();
        REQUIRE(procTable.size() == 3);
        REQUIRE(procTable[0][0] == "proc1");
        REQUIRE(procTable[1][0] == "proc2");
        REQUIRE(procTable[2][0] == "proc3");

    }
}