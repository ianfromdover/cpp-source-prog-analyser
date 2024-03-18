//
// Created by yewme on 26/2/2024.
//

#include "catch.hpp"
#include "pkb/apis/QueryPkb.h"
#include <memory>

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

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPKB(pkb);

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

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPKB(pkb);

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
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{{"3"}}}));
        REQUIRE(isPresent(test, {{{"4"}}}));

    }

    SECTION("Test getCallTable() method") {

        // Retrieve callTable and verify its contents
        std::vector<std::vector<std::string>> callTable = queryPKB.getCallTable();
        REQUIRE(callTable.size() == 4);
        REQUIRE(isPresent(callTable, {{"1", "proc1"}, {"2", "proc2"}, {"3", "proc3"}, {"4", "proc3"}}));

    }
}


TEST_CASE("Test QueryPKB getProc methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPKB(pkb);

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

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPKB(pkb);

    // Add records to readTable
    pkb->readTable->addRead(1, "x");
    pkb->readTable->addRead(2, "y");
    pkb->readTable->addRead(3, "z");
    pkb->readTable->addRead(4, "y");

    SECTION("Test getReadByNum() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getReadByNum(1);
        std::vector<std::vector<std::string>> testResult = {{"x"}};
        REQUIRE(test.size() == 1);
        REQUIRE(test == testResult);

    }

    SECTION("Test getReadByVar() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getReadByVar("y");
        std::vector<std::vector<std::string>> testResult = {{"2"}, {"4"}};
        std::vector<std::vector<std::string>> testResult1 = {{"4"}, {"2"}};
        REQUIRE(test.size() == 2);
        REQUIRE((test == testResult || test == testResult1));

    }

    SECTION("Test getReadTable() method") {

        // Retrieve readTable and verify its contents
        std::vector<std::vector<std::string>> readTable = queryPKB.getReadTable();
        REQUIRE(readTable.size() == 4);
        REQUIRE(isPresent(readTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPKB getIf methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPKB(pkb);

    // Add records to readTable
    pkb->ifTable->addIf(1, "x");
    pkb->ifTable->addIf(2, "y");
    pkb->ifTable->addIf(3, "z");
    pkb->ifTable->addIf(4, "y");

    SECTION("Test getIfByNum() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getIfByNum(1);
        std::vector<std::vector<std::string>> testResult = {{"x"}};
        REQUIRE(test.size() == 1);
        REQUIRE(test == testResult);

    }

    SECTION("Test getIfByVar() method") {

        std::vector<std::vector<std::string>> test = queryPKB.getIfByVar("y");
        std::vector<std::vector<std::string>> testResult = {{"2"}, {"4"}};
        std::vector<std::vector<std::string>> testResult1 = {{"4"}, {"2"}};
        REQUIRE(test.size() == 2);
        REQUIRE((test == testResult || test == testResult1));

    }

    SECTION("Test getIfTable() method") {

        // Retrieve readTable and verify its contents
        std::vector<std::vector<std::string>> ifTable = queryPKB.getIfTable();
        REQUIRE(ifTable.size() == 4);
        REQUIRE(isPresent(ifTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}