//
// Created by yewme on 26/2/2024.
//

#include "catch.hpp"
#include "pkb/apis/QueryPkb.h"
#include <memory>

std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
QueryPkb queryPkb(pkb);

bool isPresent(const std::vector<std::vector<std::string>>& vec,
               const std::vector<std::vector<std::string>>& elements) {
    return std::all_of(elements.begin(), elements.end(), [&](const auto& element) {
        return std::find(vec.begin(), vec.end(), element) != vec.end();
    });
}

TEST_CASE("Test isPresent testing helper function") {

    std::vector<std::vector<std::string>> test = {{"1"}};
    REQUIRE(test.size() == 1);
    REQUIRE(isPresent(test, {{"1"}}));
    REQUIRE(!isPresent(test, {{"2"}}));

    std::vector<std::vector<std::string>> two = {{"1", "a"}};
    std::vector<std::vector<std::string>> twoIdentical = {{"1", "a"}};
    REQUIRE(isPresent(two, twoIdentical));

}

TEST_CASE("Test toVecVecStr conversion methods") {

    SECTION("Test for string vector") {
        std::vector<std::string> input = {"1", "2", "3"};
        auto converted = queryPkb.toVecVecStr(input);
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
        auto converted = queryPkb.toVecVecStr(input);
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

        std::vector<std::vector<std::string>> test = queryPkb.getCallByNum(1);
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"proc1"}}));

    }

    SECTION("Test getCallByProc() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getCallByProc("proc3");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"3"}, {"4"}}));

    }

    SECTION("Test getCallTable() method") {

        // Retrieve callTable and verify its contents
        std::vector<std::vector<std::string>> callTable = queryPkb.getCallTable();
        REQUIRE(callTable.size() == 4);
        REQUIRE(isPresent(callTable, {{"1", "proc1"}, {"2", "proc2"}, {"3", "proc3"}, {"4", "proc3"}}));

    }
}


TEST_CASE("Test QueryPKB getProc methods") {

    // Add records to procTable
    pkb->procedureTable->addProc("proc1");
    pkb->procedureTable->addProc("proc2");
    pkb->procedureTable->addProc("proc3");

    SECTION("Test getProcByName() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getProcTable();
        REQUIRE(test.size() == 3);
        REQUIRE(isPresent(test, {{"proc1"}, {"proc2"}, {"proc3"}}));

    }

    SECTION("Test getProcTable() method") {

        // Retrieve procTable and verify its contents
        std::vector<std::vector<std::string>> procTable = queryPkb.getProcTable();
        REQUIRE(procTable.size() == 3);
        REQUIRE(isPresent(procTable, {{"proc1"}, {"proc2"}, {"proc3"}}));

    }
}


TEST_CASE("Test QueryPKB getRead methods") {

    // Add records to readTable
    pkb->readTable->addRead(1, "x");
    pkb->readTable->addRead(2, "y");
    pkb->readTable->addRead(3, "z");
    pkb->readTable->addRead(4, "y");

    SECTION("Test getReadByNum() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getReadByNum(1);
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"x"}}));

    }

    SECTION("Test getReadByVar() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getReadByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getReadTable() method") {

        // Retrieve readTable and verify its contents
        std::vector<std::vector<std::string>> readTable = queryPkb.getReadTable();
        REQUIRE(readTable.size() == 4);
        REQUIRE(isPresent(readTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPKB getIf methods") {

    // Add records to readTable
    pkb->ifTable->addIf(1, "x");
    pkb->ifTable->addIf(2, "y");
    pkb->ifTable->addIf(3, "z");
    pkb->ifTable->addIf(4, "y");

    SECTION("Test getIfByNum() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getIfByNum(1);
        std::vector<std::vector<std::string>> testResult = {{"x"}};
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"x"}}));

    }

    SECTION("Test getIfByVar() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getIfByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getIfTable() method") {

        // Retrieve readTable and verify its contents
        std::vector<std::vector<std::string>> ifTable = queryPkb.getIfTable();
        REQUIRE(ifTable.size() == 4);
        REQUIRE(isPresent(ifTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPKB getWhile methods") {

    // Add records to whileTable
    pkb->whileTable->addWhile(1, "x");
    pkb->whileTable->addWhile(2, "y");
    pkb->whileTable->addWhile(3, "z");
    pkb->whileTable->addWhile(4, "y");

    SECTION("Test getWhileByNum() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getWhileByNum(1);
        std::vector<std::vector<std::string>> testResult = {{"x"}};
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"x"}}));

    }

    SECTION("Test getWhileByVar() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getWhileByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getWhileTable() method") {

        // Retrieve whileTable and verify its contents
        std::vector<std::vector<std::string>> whileTable = queryPkb.getWhileTable();
        REQUIRE(whileTable.size() == 4);
        REQUIRE(isPresent(whileTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPKB getPrint methods") {

    // Add records to printTable
    pkb->printTable->addPrint(1, "x");
    pkb->printTable->addPrint(2, "y");
    pkb->printTable->addPrint(3, "z");
    pkb->printTable->addPrint(4, "y");
    pkb->printTable->addPrint(4, "z");

    SECTION("Test getPrintByNum() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getPrintByNum(4);
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"y"}, {"z"}}));

    }

    SECTION("Test getPrintByVar() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getPrintByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getPrintTable() method") {

        // Retrieve printTable and verify its contents
        std::vector<std::vector<std::string>> printTable = queryPkb.getPrintTable();
        REQUIRE(printTable.size() == 5);
        REQUIRE(isPresent(printTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"4", "z"}}));

    }
}


TEST_CASE("Test QueryPKB getStmt methods") {

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
        std::vector<std::vector<std::string>> stmtTable = queryPkb.getStmtTable();
        REQUIRE(stmtTable.size() == 3);
        REQUIRE(isPresent(stmtTable, {{"1"}, {"2"}, {"3"}}));

    }
}


TEST_CASE("Test QueryPKB getVar methods") {

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
        std::vector<std::vector<std::string>> varTable = queryPkb.getVarTable();
        REQUIRE(varTable.size() == 5);
        REQUIRE(isPresent(varTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "x"}, {"5", "z"}}));

    }
}


TEST_CASE("Test QueryPKB getConst methods") {

    // Add records to constTable
    pkb->constTable->addConst(1, 4);
    pkb->constTable->addConst(2, 2);
    pkb->constTable->addConst(3, 0);

//    SECTION("Test getConstByNum() method") {
//
//    }

    SECTION("Test getConstTable() method") {

        // Retrieve constTable and verify its contents
        std::vector<std::vector<std::string>> constTable = queryPkb.getConstTable();
        REQUIRE(constTable.size() == 3);
        REQUIRE(isPresent(constTable, {{"1", "4"}, {"2", "2"}, {"3", "0"}}));

    }
}


TEST_CASE("Test QueryPKB getFollows methods") {

    // Add records to followsTable
    pkb->followsTable->addFollows(1, 2);
    pkb->followsTable->addFollows(2, 3);
    pkb->followsTable->addFollows(3, 4);

    SECTION("Test getFollowsByBefore() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getFollowsByBefore(1);
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"2"}}));

    }

    SECTION("Test getFollowsByAfter() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getFollowsByAfter(4);
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"3"}}));

    }

    SECTION("Test getFollowsTable() method") {

        // Retrieve followsTable and verify its contents
        std::vector<std::vector<std::string>> followsTable = queryPkb.getFollowsTable();
        REQUIRE(followsTable.size() == 3);
        REQUIRE(isPresent(followsTable, {{"1", "2"}, {"2", "3"}, {"3", "4"}}));

    }
}


TEST_CASE("Test QueryPKB getFollowsT methods") {

    // Add records to followsTTable
    pkb->followsTTable->addFollowsT(1, 2);
    pkb->followsTTable->addFollowsT(2, 3);
    pkb->followsTTable->addFollowsT(1, 3);
    pkb->followsTTable->addFollowsT(3, 4);
    pkb->followsTTable->addFollowsT(2, 4);
    pkb->followsTTable->addFollowsT(1, 4);

    SECTION("Test getFollowsTByBefore() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getFollowsTByBefore(2);
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"3"}, {"4"}}));

    }

    SECTION("Test getFollowsTByAfter() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getFollowsTByAfter(3);
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"1"}}));

    }

    SECTION("Test getFollowsTable() method") {

        // Retrieve followsTTable and verify its contents
        std::vector<std::vector<std::string>> followsTTable = queryPkb.getFollowsTTable();
        REQUIRE(followsTTable.size() == 6);
        REQUIRE(isPresent(followsTTable, {{"1", "2"}, {"2", "3"}, {"1", "3"}, {"3", "4"}, {"2", "4"}, {"1", "4"}}));

    }
}


TEST_CASE("Test QueryPKB getParent methods") {

    // Add records to parentTable
    pkb->parentTable->addParent(1, 2);
    pkb->parentTable->addParent(1, 3);
    pkb->parentTable->addParent(1, 4);

    SECTION("Test getParentByParent() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getParentByParent(1);
        REQUIRE(test.size() == 3);
        REQUIRE(isPresent(test, {{"2"}, {"3"}, {"4"}}));

    }

    SECTION("Test getParentByChild() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getParentByChild(4);
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"1"}}));

    }

    SECTION("Test getParentTable() method") {

        // Retrieve parentTable and verify its contents
        std::vector<std::vector<std::string>> parentTable = queryPkb.getParentTable();
        REQUIRE(parentTable.size() == 3);
        REQUIRE(isPresent(parentTable, {{"1", "2"}, {"1", "3"}, {"1", "4"}}));

    }
}


TEST_CASE("Test QueryPKB getParentT methods") {

    // Add records to parentTTable
    pkb->parentTTable->addParentT(1, 2);
    pkb->parentTTable->addParentT(1, 3);
    pkb->parentTTable->addParentT(3, 4);
    pkb->parentTTable->addParentT(1, 4);


    SECTION("Test getParentTByParent() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getParentTByParent(1);
        REQUIRE(test.size() == 3);
        REQUIRE(isPresent(test, {{"2"}, {"3"}, {"4"}}));

    }

    SECTION("Test getParentTByChild() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getParentTByChild(4);
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"1"}, {"3"}}));

    }

    SECTION("Test getParentTTable() method") {

        // Retrieve parentTTable and verify its contents
        std::vector<std::vector<std::string>> parentTTable = queryPkb.getParentTTable();
        REQUIRE(parentTTable.size() == 4);
        REQUIRE(isPresent(parentTTable, {{"1", "2"}, {"1", "3"}, {"3", "4"}, {"1", "4"}}));

    }
}


TEST_CASE("Test QueryPKB getUsesS methods") {

    // Add records to usesSTable
    pkb->usesSTable->addUsesS(1, "x");
    pkb->usesSTable->addUsesS(2, "y");
    pkb->usesSTable->addUsesS(3, "z");
    pkb->usesSTable->addUsesS(4, "y");
    pkb->usesSTable->addUsesS(4, "z");

    SECTION("Test getUsesSByNum() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getUsesSByNum(4);
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"y"}, {"z"}}));

    }

    SECTION("Test getUsesSByVar() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getUsesSByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getUsesSTable() method") {

        // Retrieve usesSTable and verify its contents
        std::vector<std::vector<std::string>> usesSTable = queryPkb.getUsesSTable();
        REQUIRE(usesSTable.size() == 5);
        REQUIRE(isPresent(usesSTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"4", "z"}}));

    }
}


TEST_CASE("Test QueryPKB getUsesP methods") {

    // Add records to usesPTable
    pkb->usesPTable->addUsesP("proc1", "x");
    pkb->usesPTable->addUsesP("proc1", "y");
    pkb->usesPTable->addUsesP("proc1", "z");
    pkb->usesPTable->addUsesP("proc2", "y");
    pkb->usesPTable->addUsesP("proc2", "z");

//    SECTION("Test getUsesPByProc() method") {
//
//        std::vector<std::vector<std::string>> test = queryPkb.getUsesSByNum(4);
//        REQUIRE(test.size() == 2);
//        REQUIRE(isPresent(test, {{"y"}, {"z"}}));
//
//    }
//
//    SECTION("Test getUsesPByVar() method") {
//
//        std::vector<std::vector<std::string>> test = queryPkb.getUsesSByVar("y");
//        REQUIRE(test.size() == 2);
//        REQUIRE(isPresent(test, {{"2"}, {"4"}}));
//
//    }

    SECTION("Test getUsesPTable() method") {

        // Retrieve usesPTable and verify its contents
        std::vector<std::vector<std::string>> usesPTable = queryPkb.getUsesPTable();
        REQUIRE(usesPTable.size() == 5);
        REQUIRE(isPresent(usesPTable, {{"proc1", "x"}, {"proc1", "y"}, {"proc1", "z"},
                                       {"proc2", "y"}, {"proc2", "z"}}));

    }
}


TEST_CASE("Test QueryPKB getModifiesS methods") {

    // Add records to modifiesSTable
    pkb->modifiesSTable->addModifiesS(1, "x");
    pkb->modifiesSTable->addModifiesS(2, "y");
    pkb->modifiesSTable->addModifiesS(3, "z");
    pkb->modifiesSTable->addModifiesS(4, "y");

    SECTION("Test getModifiesSByNum() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getModifiesSByNum(4);
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"y"}}));

    }

    SECTION("Test getModifiesSByVar() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getModifiesSByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getModifiesSTable() method") {

        // Retrieve modifiesSTable and verify its contents
        std::vector<std::vector<std::string>> modifiesSTable = queryPkb.getModifiesSTable();
        REQUIRE(modifiesSTable.size() == 4);
        REQUIRE(isPresent(modifiesSTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPKB getModifiesP methods") {

    // Add records to modifiesPTable
    pkb->modifiesPTable->addModifiesP("proc1", "x");
    pkb->modifiesPTable->addModifiesP("proc1", "y");
    pkb->modifiesPTable->addModifiesP("proc1", "z");
    pkb->modifiesPTable->addModifiesP("proc2", "y");
    pkb->modifiesPTable->addModifiesP("proc2", "z");

    SECTION("Test getModifiesPByProc() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getModifiesPByProc("proc2");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"y"}, {"z"}}));

    }

    SECTION("Test getModifiesPByVar() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getModifiesPByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"proc1"}, {"proc2"}}));

    }

    SECTION("Test getModifiesPTable() method") {

        // Retrieve modifiesPTable and verify its contents
        std::vector<std::vector<std::string>> modifiesPTable = queryPkb.getModifiesPTable();
        REQUIRE(modifiesPTable.size() == 5);
        REQUIRE(isPresent(modifiesPTable, {{"proc1", "x"}, {"proc1", "y"}, {"proc1", "z"},
                                           {"proc2", "y"}, {"proc2", "z"}}));

    }
}


TEST_CASE("Test getPatternAsgn methods") {

    // Add records to patternAsgnTable
    pkb->patternAssignTable->addStmtLhs(1, "x");
    pkb->patternAssignTable->addStmtRhs(1, "3");
    pkb->patternAssignTable->addStmtLhs(2, "y");
    pkb->patternAssignTable->addStmtRhs(2, "5");

    // Add the other get methods where necessary

    // Retrieve patternAsgnTable and verify its contents
    std::vector<std::vector<std::string>> patternAsgnTable = queryPkb.getPatternAsgnTable();
    REQUIRE(patternAsgnTable.size() == 2);
    REQUIRE(isPresent(patternAsgnTable, {{"1", "x=3"}, {"2", "y=5"}}));

}


TEST_CASE("Test getPatternIf methods") {

    // Add records to patternIfTable
    pkb->patternIfTable->addIf(1, "x");
    pkb->patternIfTable->addIf(2, "y");

    // TODO: Add the other get methods where necessary

    // Retrieve patternIfTable and verify its contents
    std::vector<std::vector<std::string>> patternIfTable = queryPkb.getPatternIfTable();
    REQUIRE(patternIfTable.size() == 2);
    REQUIRE(isPresent(patternIfTable, {{"1", "x"}, {"2", "y"}}));

}


TEST_CASE("Test getPatternWhile methods") {

    // Add records to patternWhileTable
    pkb->patternWhileTable->addWhile(1, "x");
    pkb->patternWhileTable->addWhile(4, "y");

    // TODO: Add the other get methods where necessary

    // Retrieve patternWhileTable and verify its contents
    std::vector<std::vector<std::string>> patternWhileTable = queryPkb.getPatternWhileTable();
    REQUIRE(patternWhileTable.size() == 2);
    REQUIRE(isPresent(patternWhileTable, {{"1", "x"}, {"4", "y"}}));

}


TEST_CASE("Test QueryPKB getCalls methods") {

    // Add records to callsTable
    pkb->callsTable->addCalls("proc1", "procx");
    pkb->callsTable->addCalls("proc1", "procy");
    pkb->callsTable->addCalls("proc1", "procz");
    pkb->callsTable->addCalls("proc2", "procy");
    pkb->callsTable->addCalls("proc2", "procz");

    SECTION("Test getCallsByCaller() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getCallsByCaller("proc2");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"procy"}, {"procz"}}));

    }

    SECTION("Test getCallsByCalled() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getCallsByCalled("procy");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"proc1"}, {"proc2"}}));

    }

    SECTION("Test getCallsTable() method") {

        // Retrieve callsTable and verify its contents
        std::vector<std::vector<std::string>> callsTable = queryPkb.getCallsTable();
        REQUIRE(callsTable.size() == 5);
        REQUIRE(isPresent(callsTable, {{"proc1", "procx"}, {"proc1", "procy"}, {"proc1", "procz"},
                                           {"proc2", "procy"}, {"proc2", "procz"}}));

    }
}


TEST_CASE("Test QueryPKB getCallsT methods") {

    // Add records to callsTTable
    pkb->callsTTable->addCallsT("proc1", "procx");
    pkb->callsTTable->addCallsT("proc1", "procy");
    pkb->callsTTable->addCallsT("procx", "procz");
    pkb->callsTTable->addCallsT("proc1", "procz");

    SECTION("Test getCallsTByCaller() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getCallsTByCaller("proc1");
        REQUIRE(test.size() == 3);
        REQUIRE(isPresent(test, {{"procx"}, {"procy"}, {"procz"}}));

    }

    SECTION("Test getCallsTByCalled() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getCallsTByCalled("procz");
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"proc1"}, {"procx"}}));

    }

    SECTION("Test getCallsTTable() method") {

        // Retrieve callsTable and verify its contents
        std::vector<std::vector<std::string>> callsTTable = queryPkb.getCallsTTable();
        REQUIRE(callsTTable.size() == 4);
        REQUIRE(isPresent(callsTTable, {{"proc1", "procx"}, {"proc1", "procy"}, {"procx", "procz"},
                                        {"proc1", "procz"}}));

    }
}


TEST_CASE("Test QueryPKB getNext methods") {

    // Add records to nextTable
    pkb->nextTable->addNext(1, 2);
    pkb->nextTable->addNext(2, 3);
    pkb->nextTable->addNext(3, 4);

    SECTION("Test getNextByBefore() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getNextByBefore(1);
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"2"}}));

    }

    SECTION("Test getNextByAfter() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getNextByAfter(4);
        REQUIRE(test.size() == 1);
        REQUIRE(isPresent(test, {{"3"}}));

    }

    SECTION("Test getNextTable() method") {

        // Retrieve nextTable and verify its contents
        std::vector<std::vector<std::string>> nextTable = queryPkb.getNextTable();
        REQUIRE(nextTable.size() == 3);
        REQUIRE(isPresent(nextTable, {{"1", "2"}, {"2", "3"}, {"3", "4"}}));

    }
}


TEST_CASE("Test QueryPKB getNextT methods") {

    // Add records to nextTTable
    pkb->nextTTable->addNextT(1, 2);
    pkb->nextTTable->addNextT(2, 3);
    pkb->nextTTable->addNextT(2, 4);
    pkb->nextTTable->addNextT(1, 4);

    SECTION("Test getNextTByBefore() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getNextTByBefore(1);
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getNextTByAfter() method") {

        std::vector<std::vector<std::string>> test = queryPkb.getNextTByAfter(4);
        REQUIRE(test.size() == 2);
        REQUIRE(isPresent(test, {{"1"}, {"2"}}));

    }

    SECTION("Test getNextTTable() method") {

        // Retrieve nextTTable and verify its contents
        std::vector<std::vector<std::string>> nextTTable = queryPkb.getNextTTable();
        REQUIRE(nextTTable.size() == 4);
        REQUIRE(isPresent(nextTTable, {{"1", "2"}, {"2", "3"}, {"1", "4"}, {"2", "4"}}));

    }
}