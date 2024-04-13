//
// Created by yewme on 21/3/2024.
//

#include "catch.hpp"
#include "pkb/apis/QueryPkb.h"
#include "../../qps/query_evaluator/stub/QueryPkbStub.h"
#include "common/TableUtils.h"
QueryPkbStub stub;

TEST_CASE("Test QueryPkb getCall methods using stub using stub") {

    // Add records to callTable stub
    stub.setCallStmt({{"1", "proc1"}, {"2", "proc2"}, {"3", "proc3"}, {"4", "proc3"}});

    SECTION("Test getCallTable() method") {

        // Retrieve callTable stub and verify its contents
        Table callTable = stub.getCallTable();
        REQUIRE(callTable.size() == 4);
        REQUIRE(TableUtils::isPresent(callTable, {{"1", "proc1"}, {"2", "proc2"}, {"3", "proc3"}, {"4", "proc3"}}));

    }
}


TEST_CASE("Test QueryPkb getProc methods using stub using stub") {

    // Add records to procTable stub
    stub.setProcedure({{"proc1"}, {"proc2"}, {"proc3"}});

    SECTION("Test getProcTable() method") {

        // Retrieve procTable stub and verify its contents
        Table procTable = stub.getProcTable();
        REQUIRE(procTable.size() == 3);
        REQUIRE(TableUtils::isPresent(procTable, {{"proc1"}, {"proc2"}, {"proc3"}}));

    }
}


TEST_CASE("Test QueryPkb getRead methods using stub using stub") {

    // Add records to readTable stub
    stub.setRead({{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}});

    SECTION("Test getReadTable() method") {

        // Retrieve readTable stub and verify its contents
        Table readTable = stub.getReadTable();
        REQUIRE(readTable.size() == 4);
        REQUIRE(TableUtils::isPresent(readTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPkb getIf methods using stub") {

    // Add records to patternIfTable stub
    stub.setPatternIf({{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}});

    SECTION("Test getIfTable() method") {

        // Retrieve patternIfTable and verify its contents
        Table patternIfTable = stub.getPatternIfTable();
        REQUIRE(patternIfTable.size() == 4);
        REQUIRE(TableUtils::isPresent(patternIfTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPkb getWhile methods using stub") {

    // Add records to patternWhileTable stub
    stub.setPatternWhile({{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}});

    SECTION("Test getPatternWhileTable() method") {

        // Retrieve whileTable and verify its contents
        Table patternWhileTable = stub.getPatternWhileTable();
        REQUIRE(patternWhileTable.size() == 4);
        REQUIRE(TableUtils::isPresent(patternWhileTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPkb getPrint methods using stub") {

    // Add records to printTable stub
    stub.setPrint({{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"4", "z"}});
    
    SECTION("Test getPrintTable() method") {

        // Retrieve printTable and verify its contents
        Table printTable = stub.getPrintTable();
        REQUIRE(printTable.size() == 5);
        REQUIRE(TableUtils::isPresent(printTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"4", "z"}}));

    }
}


TEST_CASE("Test QueryPkb getStmt methods using stub") {

    // Add records to stmtTable stub
    stub.setStatement({{"1"}, {"2"}, {"3"}});

    SECTION("Test getStmtTable() method") {

        // Retrieve stmtTable and verify its contents
        Table stmtTable = stub.getStmtTable();
        REQUIRE(stmtTable.size() == 3);
        REQUIRE(TableUtils::isPresent(stmtTable, {{"1"}, {"2"}, {"3"}}));

    }
}


TEST_CASE("Test QueryPkb getVar methods using stub") {

    // Add records to varTable stub
    stub.setVar({{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"5", "z"}});

    SECTION("Test getVarTable() method") {

        // Retrieve procTable and verify its contents
        Table varTable = stub.getVarTable();
        REQUIRE(varTable.size() == 5);
        REQUIRE(TableUtils::isPresent(varTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"5", "z"}}));

    }
}


TEST_CASE("Test QueryPkb getConst methods using stub") {

    // Add records to constTable stub
    stub.setConst({{"1", "4"}, {"2", "2"}, {"3", "0"}});

    SECTION("Test getConstTable() method") {

        // Retrieve constTable and verify its contents
        Table constTable = stub.getConstTable();
        REQUIRE(constTable.size() == 3);
        REQUIRE(TableUtils::isPresent(constTable, {{"1", "4"}, {"2", "2"}, {"3", "0"}}));

    }
}


TEST_CASE("Test QueryPkb getFollows methods using stub") {

    // Add records to followsTable stub
    stub.setFollows({{"1", "2"}, {"2", "3"}, {"3", "4"}});

    SECTION("Test getFollowsTable() method") {

        // Retrieve followsTable and verify its contents
        Table followsTable = stub.getFollowsTable();
        REQUIRE(followsTable.size() == 3);
        REQUIRE(TableUtils::isPresent(followsTable, {{"1", "2"}, {"2", "3"}, {"3", "4"}}));

    }
}


TEST_CASE("Test QueryPkb getFollowsT methods using stub") {

    // Add records to followsTTable stub
    stub.setFollowsT({{"1", "2"}, {"2", "3"}, {"1", "3"}, {"3", "4"}, {"2", "4"}, {"1", "4"}});

    SECTION("Test getFollowsTable() method") {

        // Retrieve followsTTable and verify its contents
        Table followsTTable = stub.getFollowsTTable();
        REQUIRE(followsTTable.size() == 6);
        REQUIRE(TableUtils::isPresent(followsTTable, {{"1", "2"}, {"2", "3"}, {"1", "3"}, {"3", "4"}, {"2", "4"}, {"1", "4"}}));

    }
}


TEST_CASE("Test QueryPkb getParent methods using stub") {

    // Add records to parentTable stub
    stub.setParent({{"1", "2"}, {"1", "3"}, {"1", "4"}});

    SECTION("Test getParentTable() method") {

        // Retrieve parentTable and verify its contents
        Table parentTable = stub.getParentTable();
        REQUIRE(parentTable.size() == 3);
        REQUIRE(TableUtils::isPresent(parentTable, {{"1", "2"}, {"1", "3"}, {"1", "4"}}));

    }
}


TEST_CASE("Test QueryPkb getParentT methods using stub") {

    // Add records to parentTTable stub
    stub.setParentT({{"1", "2"}, {"1", "3"}, {"3", "4"}, {"1", "4"}});

    SECTION("Test getParentTTable() method") {

        // Retrieve parentTTable and verify its contents
        Table parentTTable = stub.getParentTTable();
        REQUIRE(parentTTable.size() == 4);
        REQUIRE(TableUtils::isPresent(parentTTable, {{"1", "2"}, {"1", "3"}, {"3", "4"}, {"1", "4"}}));

    }
}


TEST_CASE("Test QueryPkb getUsesS methods using stub") {

    // Add records to usesSTable stub
    stub.setUses({{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"4", "z"}});

    SECTION("Test getUsesSTable() method") {

        // Retrieve usesSTable and verify its contents
        Table usesSTable = stub.getUsesSTable();
        REQUIRE(usesSTable.size() == 5);
        REQUIRE(TableUtils::isPresent(usesSTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}, {"4", "z"}}));

    }
}


TEST_CASE("Test QueryPkb getUsesP methods using stub") {

    // Add records to usesSTable stub
    stub.setUsesP({{"proc1", "x"}, {"proc1", "y"}, {"proc1", "z"}, {"proc2", "y"}, {"proc2", "z"}});

    SECTION("Test getUsesPTable() method") {

        // Retrieve usesPTable and verify its contents
        Table usesPTable = stub.getUsesPTable();
        REQUIRE(usesPTable.size() == 5);
        REQUIRE(TableUtils::isPresent(usesPTable, {{"proc1", "x"}, {"proc1", "y"}, {"proc1", "z"},
                                                   {"proc2", "y"}, {"proc2", "z"}}));

    }
}


TEST_CASE("Test QueryPkb getModifiesS methods using stub") {

    // Add records to modifiesSTable stub
    stub.setModifies({{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}});

    SECTION("Test getModifiesSTable() method") {

        // Retrieve modifiesSTable and verify its contents
        Table modifiesSTable = stub.getModifiesSTable();
        REQUIRE(modifiesSTable.size() == 4);
        REQUIRE(TableUtils::isPresent(modifiesSTable, {{"1", "x"}, {"2", "y"}, {"3", "z"}, {"4", "y"}}));

    }
}


TEST_CASE("Test QueryPkb getModifiesP methods using stub") {

    // Add records to modifiesPTable stub
    stub.setModifiesP({{"proc1", "x"}, {"proc1", "y"}, {"proc1", "z"}, {"proc2", "y"}, {"proc2", "z"}});

    SECTION("Test getModifiesPTable() method") {

        // Retrieve modifiesPTable and verify its contents
        Table modifiesPTable = stub.getModifiesPTable();
        REQUIRE(modifiesPTable.size() == 5);
        REQUIRE(TableUtils::isPresent(modifiesPTable, {{"proc1", "x"}, {"proc1", "y"}, {"proc1", "z"},
                                                       {"proc2", "y"}, {"proc2", "z"}}));

    }
}


TEST_CASE("Test QueryPkb getPatternAsgn methods using stub") {

    // Add records to patternAssign stub
    stub.setPatternAsgn({{"1", "x=3"}, {"2", "y=5"}});

    // Retrieve patternAsgnTable and verify its contents
    Table patternAsgnTable = stub.getPatternAsgnTable();
    REQUIRE(patternAsgnTable.size() == 2);
    REQUIRE(TableUtils::isPresent(patternAsgnTable, {{"1", "x=3"}, {"2", "y=5"}}));

}

TEST_CASE("Test QueryPkb getCalls methods using stub") {

    // Add records to callsTable stub
    stub.setCalls({{"proc1", "procx"}, {"proc1", "procy"}, {"proc1", "procz"}, {"proc2", "procy"}, {"proc2", "procz"}});

    SECTION("Test getCallsTable() method") {

        // Retrieve callsTable and verify its contents
        Table callsTable = stub.getCallsTable();
        REQUIRE(callsTable.size() == 5);
        REQUIRE(TableUtils::isPresent(callsTable, {{"proc1", "procx"}, {"proc1", "procy"}, {"proc1", "procz"},
                                                   {"proc2", "procy"}, {"proc2", "procz"}}));

    }
}


TEST_CASE("Test QueryPkb getCallsT methods using stub") {

    // Add records to callsTTable stub
    stub.setCallsT({{"proc1", "procx"}, {"proc1", "procy"}, {"procx", "procz"}, {"proc1", "procz"}});

    SECTION("Test getCallsTTable() method") {

        // Retrieve callsTable and verify its contents
        Table callsTTable = stub.getCallsTTable();
        REQUIRE(callsTTable.size() == 4);
        REQUIRE(TableUtils::isPresent(callsTTable, {{"proc1", "procx"}, {"proc1", "procy"}, {"procx", "procz"},
                                                    {"proc1", "procz"}}));

    }
}