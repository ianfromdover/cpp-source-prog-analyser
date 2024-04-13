#include "catch.hpp"
#include "pkb/apis/QueryPkb.h"
#include "common/TableUtils.h"
#include <memory>

TEST_CASE("Test TableUtils::isPresent testing helper function") {

    Table test = {{"1"}};
    REQUIRE(test.size() == 1);
    REQUIRE(TableUtils::isPresent(test, {{"1"}}));
    REQUIRE(!TableUtils::isPresent(test, {{"2"}}));

    Table two = {{"1", "a"}};
    Table twoIdentical = {{"1", "a"}};
    REQUIRE(TableUtils::isPresent(two, twoIdentical));

}

TEST_CASE("Test toTable conversion methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    SECTION("Test for string vector") {
        std::vector<std::string> input = {"1", "2", "3"};
        auto converted = TableUtils::toTable(input);
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
        auto converted = TableUtils::toTable(input);
        std::vector<std::string> firstElem = {"1"};
        std::vector<std::string> secondElem = {"2"};
        std::vector<std::string> thirdElem = {"3"};

        REQUIRE(converted.size() == 3);
        REQUIRE(converted[0] == firstElem);
        REQUIRE(converted[1] == secondElem);
        REQUIRE(converted[2] == thirdElem);
    }
}


TEST_CASE("Test QueryPkb getCall methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to callTable
    pkb->callTable->add(1, "proc1");
    pkb->callTable->add(2, "proc2");
    pkb->callTable->add(3, "proc3");
    pkb->callTable->add(4, "proc3");

    SECTION("Test getCallByNum() method") {

        Table test = queryPkb.getCallProcsByStmt(1);
        REQUIRE(test.size() == 1);
        REQUIRE(TableUtils::isPresent(test, {{"proc1"}}));

    }

    SECTION("Test getCallByProc() method") {

        Table test = queryPkb.getCallStmtsByProc("proc3");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"3"}, {"4"}}));

    }

    SECTION("Test getCallTable() method") {

        // Retrieve callTable and verify its contents
        Table callTable = queryPkb.getCallTable();
        REQUIRE(callTable.size() == 4);
        REQUIRE(TableUtils::isPresent(callTable, {{"1", "proc1"}, {"2", "proc2"}, {"3", "proc3"}, {"4", "proc3"}}));

    }
}


TEST_CASE("Test QueryPkb getProc methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to procTable
    pkb->procedureTable->add("proc1");
    pkb->procedureTable->add("proc2");
    pkb->procedureTable->add("proc3");

    SECTION("Test getProcByName() method") {

        Table test = queryPkb.getProcTable();
        REQUIRE(test.size() == 3);
        REQUIRE(TableUtils::isPresent(test, {{"proc1"}, {"proc2"}, {"proc3"}}));

    }

    SECTION("Test getProcTable() method") {

        // Retrieve procTable and verify its contents
        Table procTable = queryPkb.getProcTable();
        REQUIRE(procTable.size() == 3);
        REQUIRE(TableUtils::isPresent(procTable, {{"proc1"}, {"proc2"}, {"proc3"}}));

    }
}


TEST_CASE("Test QueryPkb getRead methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to readTable
    pkb->readTable->add(1, "x");
    pkb->readTable->add(2, "y");
    pkb->readTable->add(3, "z");
    pkb->readTable->add(4, "y");

    SECTION("Test getReadByStmt() method") {

        Table test = queryPkb.getReadVarsByStmt(1);
        REQUIRE(test.size() == 1);
        REQUIRE(TableUtils::isPresent(test, {{"x"}}));

    }

    SECTION("Test getReadByVar() method") {

        Table test = queryPkb.getReadStmtsByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getReadTable() method") {

        // Retrieve readTable and verify its contents
        Table readTable = queryPkb.getReadTable();
        REQUIRE(readTable.size() == 4);
        REQUIRE(TableUtils::isPresent(readTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPkb getIf methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to readTable
    pkb->patternIfTable->add(1, "x");
    pkb->patternIfTable->add(2, "y");
    pkb->patternIfTable->add(3, "z");
    pkb->patternIfTable->add(4, "y");

    SECTION("Test getIfByNum() method") {

        Table test = queryPkb.getIfVarsByStmt(1);
        Table testResult = {{"x"}};
        REQUIRE(test.size() == 1);
        REQUIRE(TableUtils::isPresent(test, {{"x"}}));

    }

    SECTION("Test getIfByVar() method") {

        Table test = queryPkb.getIfStmtsByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getIfTable() method") {

        // Retrieve readTable and verify its contents
        Table ifTable = queryPkb.getIfTable();
        REQUIRE(ifTable.size() == 4);
        REQUIRE(TableUtils::isPresent(ifTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPkb getWhile methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to whileTable
    pkb->patternWhileTable->add(1, "x");
    pkb->patternWhileTable->add(2, "y");
    pkb->patternWhileTable->add(3, "z");
    pkb->patternWhileTable->add(4, "y");

    SECTION("Test getWhileByNum() method") {

        Table test = queryPkb.getWhileVarsByStmt(1);
        Table testResult = {{"x"}};
        REQUIRE(test.size() == 1);
        REQUIRE(TableUtils::isPresent(test, {{"x"}}));

    }

    SECTION("Test getWhileByVar() method") {

        Table test = queryPkb.getWhileStmtsByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getWhileTable() method") {

        // Retrieve whileTable and verify its contents
        Table whileTable = queryPkb.getWhileTable();
        REQUIRE(whileTable.size() == 4);
        REQUIRE(TableUtils::isPresent(whileTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPkb getPrint methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to printTable
    pkb->printTable->add(1, "x");
    pkb->printTable->add(2, "y");
    pkb->printTable->add(3, "z");
    pkb->printTable->add(4, "y");
    pkb->printTable->add(4, "z");

    SECTION("Test getPrintByNum() method") {

        Table test = queryPkb.getPrintVarsByStmt(4);
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"y"}, {"z"}}));

    }

    SECTION("Test getPrintByVar() method") {

        Table test = queryPkb.getPrintStmtsByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getPrintTable() method") {

        // Retrieve printTable and verify its contents
        Table printTable = queryPkb.getPrintTable();
        REQUIRE(printTable.size() == 5);
        REQUIRE(TableUtils::isPresent(printTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"4", "z"}}));

    }
}


TEST_CASE("Test QueryPkb getStmt methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to stmtTable
    pkb->statementTable->addFinalStatementNo(4); // bracket, not counted in stmts

    SECTION("Test getStmtTable() method") {

        // Retrieve stmtTable and verify its contents
        Table stmtTable = queryPkb.getStmtTable();
        REQUIRE(stmtTable.size() == 4);
        REQUIRE(TableUtils::isPresent(stmtTable, {{"1"}, {"2"}, {"3"}, {"4"}}));
    }
}


TEST_CASE("Test QueryPkb getVar methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to varTable
    pkb->varTable->add(1, "x");
    pkb->varTable->add(2, "y");
    pkb->varTable->add(3, "z");
    pkb->varTable->add(4, "x");
    pkb->varTable->add(5, "z");

    SECTION("Test getVarTable() method") {

        // Retrieve procTable and verify its contents
        Table varTable = queryPkb.getVarTable();
        REQUIRE(varTable.size() == 5);
        REQUIRE(TableUtils::isPresent(varTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "x"}, {"5", "z"}}));

    }
}


TEST_CASE("Test QueryPkb getConst methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to constTable
    pkb->constTable->add(1, 4);
    pkb->constTable->add(2, 2);
    pkb->constTable->add(3, 0);

    SECTION("Test getConstTable() method") {

        // Retrieve constTable and verify its contents
        Table constTable = queryPkb.getConstTable();
        REQUIRE(constTable.size() == 3);
        REQUIRE(TableUtils::isPresent(constTable, {{"1", "4"}, {"2", "2"}, {"3", "0"}}));

    }
}


TEST_CASE("Test QueryPkb getFollows methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to followsTable
    pkb->followsTable->add(1, 2);
    pkb->followsTable->add(2, 3);
    pkb->followsTable->add(3, 4);

    SECTION("Test getFollowsByBefore() method") {

        Table test = queryPkb.getFollowsAfterByBefore(1);
        REQUIRE(test.size() == 1);
        REQUIRE(TableUtils::isPresent(test, {{"2"}}));

    }

    SECTION("Test getFollowsByAfter() method") {

        Table test = queryPkb.getFollowsBeforeByAfter(4);
        REQUIRE(test.size() == 1);
        REQUIRE(TableUtils::isPresent(test, {{"3"}}));

    }

    SECTION("Test getFollowsTable() method") {

        // Retrieve followsTable and verify its contents
        Table followsTable = queryPkb.getFollowsTable();
        REQUIRE(followsTable.size() == 3);
        REQUIRE(TableUtils::isPresent(followsTable, {{"1", "2"}, {"2", "3"}, {"3", "4"}}));

    }
}


TEST_CASE("Test QueryPkb getFollowsT methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to followsTTable
    pkb->followsTTable->add(1, 2);
    pkb->followsTTable->add(2, 3);
    pkb->followsTTable->add(1, 3);
    pkb->followsTTable->add(3, 4);
    pkb->followsTTable->add(2, 4);
    pkb->followsTTable->add(1, 4);

    SECTION("Test getFollowsTByBefore() method") {

        Table test = queryPkb.getFollowsTAfterByBefore(2);
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"3"}, {"4"}}));

    }

    SECTION("Test getFollowsTByAfter() method") {

        Table test = queryPkb.getFollowsTBeforeByAfter(3);
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"2"}, {"1"}}));

    }

    SECTION("Test getFollowsTable() method") {

        // Retrieve followsTTable and verify its contents
        Table followsTTable = queryPkb.getFollowsTTable();
        REQUIRE(followsTTable.size() == 6);
        REQUIRE(TableUtils::isPresent(followsTTable, {{"1", "2"}, {"2", "3"}, {"1", "3"}, {"3", "4"}, {"2", "4"}, {"1", "4"}}));

    }
}


TEST_CASE("Test QueryPkb getParent methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to parentTable
    pkb->parentTable->add(1, 2);
    pkb->parentTable->add(1, 3);
    pkb->parentTable->add(1, 4);

    SECTION("Test getParentByParent() method") {

        Table test = queryPkb.getParentChildByParent(1);
        REQUIRE(test.size() == 3);
        REQUIRE(TableUtils::isPresent(test, {{"2"}, {"3"}, {"4"}}));

    }

    SECTION("Test getParentByChild() method") {

        Table test = queryPkb.getParentParentByChild(4);
        REQUIRE(test.size() == 1);
        REQUIRE(TableUtils::isPresent(test, {{"1"}}));

    }

    SECTION("Test getParentTable() method") {

        // Retrieve parentTable and verify its contents
        Table parentTable = queryPkb.getParentTable();
        REQUIRE(parentTable.size() == 3);
        REQUIRE(TableUtils::isPresent(parentTable, {{"1", "2"}, {"1", "3"}, {"1", "4"}}));

    }
}


TEST_CASE("Test QueryPkb getParentT methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to parentTTable
    pkb->parentTTable->add(1, 2);
    pkb->parentTTable->add(1, 3);
    pkb->parentTTable->add(3, 4);
    pkb->parentTTable->add(1, 4);


    SECTION("Test getParentTByParent() method") {

        Table test = queryPkb.getParentTChildByParent(1);
        REQUIRE(test.size() == 3);
        REQUIRE(TableUtils::isPresent(test, {{"2"}, {"3"}, {"4"}}));

    }

    SECTION("Test getParentTByChild() method") {

        Table test = queryPkb.getParentTParentByChild(4);
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"1"}, {"3"}}));

    }

    SECTION("Test getParentTTable() method") {

        // Retrieve parentTTable and verify its contents
        Table parentTTable = queryPkb.getParentTTable();
        REQUIRE(parentTTable.size() == 4);
        REQUIRE(TableUtils::isPresent(parentTTable, {{"1", "2"}, {"1", "3"}, {"3", "4"}, {"1", "4"}}));

    }
}


TEST_CASE("Test QueryPkb getUsesS methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to usesSTable
    pkb->usesSTable->add(1, "x");
    pkb->usesSTable->add(2, "y");
    pkb->usesSTable->add(3, "z");
    pkb->usesSTable->add(4, "y");
    pkb->usesSTable->add(4, "z");

    SECTION("Test getUsesSByNum() method") {

        Table test = queryPkb.getUsesSVarsByStmt(4);
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"y"}, {"z"}}));

    }

    SECTION("Test getUsesSByVar() method") {

        Table test = queryPkb.getUsesSStmtsByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getUsesSTable() method") {

        // Retrieve usesSTable and verify its contents
        Table usesSTable = queryPkb.getUsesSTable();
        REQUIRE(usesSTable.size() == 5);
        REQUIRE(TableUtils::isPresent(usesSTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"4", "z"}}));

    }
}


TEST_CASE("Test QueryPkb getUsesP methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to usesPTable
    pkb->usesPTable->add("proc1", "x");
    pkb->usesPTable->add("proc1", "y");
    pkb->usesPTable->add("proc1", "z");
    pkb->usesPTable->add("proc2", "y");
    pkb->usesPTable->add("proc2", "z");

    SECTION("Test getUsesPTable() method") {

        // Retrieve usesPTable and verify its contents
        Table usesPTable = queryPkb.getUsesPTable();
        REQUIRE(usesPTable.size() == 5);
        REQUIRE(TableUtils::isPresent(usesPTable, {{"proc1", "x"}, {"proc1", "y"}, {"proc1", "z"},
                                                   {"proc2", "y"}, {"proc2", "z"}}));

    }
}


TEST_CASE("Test QueryPkb getModifiesS methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to modifiesSTable
    pkb->modifiesSTable->add(1, "x");
    pkb->modifiesSTable->add(2, "y");
    pkb->modifiesSTable->add(3, "z");
    pkb->modifiesSTable->add(4, "y");

    SECTION("Test getModifiesSByNum() method") {

        Table test = queryPkb.getModifiesSVarsByStmt(4);
        REQUIRE(test.size() == 1);
        REQUIRE(TableUtils::isPresent(test, {{"y"}}));

    }

    SECTION("Test getModifiesSByVar() method") {

        Table test = queryPkb.getModifiesSStmtsByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"2"}, {"4"}}));

    }

    SECTION("Test getModifiesSTable() method") {

        // Retrieve modifiesSTable and verify its contents
        Table modifiesSTable = queryPkb.getModifiesSTable();
        REQUIRE(modifiesSTable.size() == 4);
        REQUIRE(TableUtils::isPresent(modifiesSTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPkb getModifiesP methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to modifiesPTable
    pkb->modifiesPTable->add("proc1", "x");
    pkb->modifiesPTable->add("proc1", "y");
    pkb->modifiesPTable->add("proc1", "z");
    pkb->modifiesPTable->add("proc2", "y");
    pkb->modifiesPTable->add("proc2", "z");

    SECTION("Test getModifiesPByProc() method") {

        Table test = queryPkb.getModifiesPVarsByProc("proc2");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"y"}, {"z"}}));

    }

    SECTION("Test getModifiesPByVar() method") {

        Table test = queryPkb.getModifiesPProcsByVar("y");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"proc1"}, {"proc2"}}));

    }

    SECTION("Test getModifiesPTable() method") {

        // Retrieve modifiesPTable and verify its contents
        Table modifiesPTable = queryPkb.getModifiesPTable();
        REQUIRE(modifiesPTable.size() == 5);
        REQUIRE(TableUtils::isPresent(modifiesPTable, {{"proc1", "x"}, {"proc1", "y"}, {"proc1", "z"},
                                                       {"proc2", "y"}, {"proc2", "z"}}));

    }
}


TEST_CASE("Test QueryPkb getPatternAsgn methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to patternAsgnTable
    pkb->patternAssignTable->addStmtLhs(1, "x");
    pkb->patternAssignTable->addStmtRhs(1, "3");
    pkb->patternAssignTable->addStmtLhs(2, "y");
    pkb->patternAssignTable->addStmtRhs(2, "5");

    // Add the other get methods where necessary

    // Retrieve patternAsgnTable and verify its contents
    Table patternAsgnTable = queryPkb.getPatternAsgnTable();
    REQUIRE(patternAsgnTable.size() == 2);
    REQUIRE(TableUtils::isPresent(patternAsgnTable, {{"1", "x=3"}, {"2", "y=5"}}));

}


TEST_CASE("Test QueryPkb getPatternIf methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to patternIfTable
    pkb->patternIfTable->add(1, "x");
    pkb->patternIfTable->add(2, "y");
    pkb->patternIfTable->add(3, "z");
    pkb->patternIfTable->add(4, "y");

    // Retrieve patternIfTable and verify its contents
    Table patternIfTable = queryPkb.getPatternIfTable();
    TableUtils::printTable(patternIfTable);
    REQUIRE(patternIfTable.size() == 4);
    REQUIRE(TableUtils::isPresent(patternIfTable,
                                  {{"1", "x"},
                                   {"2", "y"},
                                   {"3", "z"},
                                   {"4", "y"}}));

}


TEST_CASE("Test QueryPkb getPatternWhile methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to patternWhileTable
    pkb->patternWhileTable->add(1, "x");
    pkb->patternWhileTable->add(4, "y");

    // Retrieve patternWhileTable and verify its contents
    Table patternWhileTable = queryPkb.getPatternWhileTable();
    REQUIRE(patternWhileTable.size() == 2);
    REQUIRE(TableUtils::isPresent(patternWhileTable, {{"1", "x"}, {"4", "y"}}));

}


TEST_CASE("Test QueryPkb getCalls methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to callsTable
    pkb->callsTable->add("proc1", "procx");
    pkb->callsTable->add("proc1", "procy");
    pkb->callsTable->add("proc1", "procz");
    pkb->callsTable->add("proc2", "procy");
    pkb->callsTable->add("proc2", "procz");

    SECTION("Test getCallsByCaller() method") {

        Table test = queryPkb.getCallsCalledByCaller("proc2");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"procy"}, {"procz"}}));

    }

    SECTION("Test getCallsByCalled() method") {

        Table test = queryPkb.getCallsCallerByCalled("procy");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"proc1"}, {"proc2"}}));

    }

    SECTION("Test getCallsTable() method") {

        // Retrieve callsTable and verify its contents
        Table callsTable = queryPkb.getCallsTable();
        REQUIRE(callsTable.size() == 5);
        REQUIRE(TableUtils::isPresent(callsTable, {{"proc1", "procx"}, {"proc1", "procy"}, {"proc1", "procz"},
                                                   {"proc2", "procy"}, {"proc2", "procz"}}));

    }
}


TEST_CASE("Test QueryPkb getCallsT methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to callsTTable
    pkb->callsTTable->add("proc1", "procx");
    pkb->callsTTable->add("proc1", "procy");
    pkb->callsTTable->add("procx", "procz");
    pkb->callsTTable->add("proc1", "procz");

    SECTION("Test getCallsTByCaller() method") {

        Table test = queryPkb.getCallsTCalledByCaller("proc1");
        REQUIRE(test.size() == 3);
        REQUIRE(TableUtils::isPresent(test, {{"procx"}, {"procy"}, {"procz"}}));

    }

    SECTION("Test getCallsTByCalled() method") {

        Table test = queryPkb.getCallsTCallerByCalled("procz");
        REQUIRE(test.size() == 2);
        REQUIRE(TableUtils::isPresent(test, {{"proc1"}, {"procx"}}));

    }

    SECTION("Test getCallsTTable() method") {

        // Retrieve callsTable and verify its contents
        Table callsTTable = queryPkb.getCallsTTable();
        REQUIRE(callsTTable.size() == 4);
        REQUIRE(TableUtils::isPresent(callsTTable, {{"proc1", "procx"}, {"proc1", "procy"}, {"procx", "procz"},
                                                    {"proc1", "procz"}}));

    }
}


TEST_CASE("Test QueryPkb getNext methods") {

    std::shared_ptr<PkbStorage> pkb = std::make_shared<PkbStorage>();
    QueryPkb queryPkb(pkb);

    // Add records to nextTable
    pkb->nextTable->add(1, 2);
    pkb->nextTable->add(2, 3);
    pkb->nextTable->add(3, 4);

    SECTION("Test getNextByBefore() method") {

        Table test = queryPkb.getNextAfterByBefore(1);
        REQUIRE(test.size() == 1);
        REQUIRE(TableUtils::isPresent(test, {{"2"}}));

    }

    SECTION("Test getNextByAfter() method") {

        Table test = queryPkb.getNextBeforeByAfter(4);
        REQUIRE(test.size() == 1);
        REQUIRE(TableUtils::isPresent(test, {{"3"}}));

    }

    SECTION("Test getNextTable() method") {

        // Retrieve nextTable and verify its contents
        Table nextTable = queryPkb.getNextTable();
        REQUIRE(nextTable.size() == 3);
        REQUIRE(TableUtils::isPresent(nextTable, {{"1", "2"}, {"2", "3"}, {"3", "4"}}));

    }
}
