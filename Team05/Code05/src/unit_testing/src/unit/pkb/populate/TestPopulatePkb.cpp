#include "catch.hpp"
#include "pkb/apis/PopulatePkb.h"

// ai-gen start (copilot, 2, e)
// prompt: used copilot
bool isAdded(Table table, std::string key, std::string value) {
    for (const auto& pair : table) {
        if (pair.size() == 1 && pair[0] == key) {
            return true;
        }
        else if (pair.size() == 2 && pair[0] == key && pair[1] == value) {
            return true;
        }
    }
    return false;
}

TEST_CASE("[PopulatePkb] Normal input, no exceptions, no false") {
    auto pkb_storage = std::make_shared<PkbStorage>();
    PopulatePkb populator(pkb_storage);

    SECTION("Entity Addition") {
        REQUIRE(populator.addCallStmt(1, "call"));
        REQUIRE(populator.addConst(2, 20));
        REQUIRE(populator.addPrint(3, "print"));
        REQUIRE(populator.addProcedure("procedure"));
        REQUIRE(populator.addRead(4, "read"));
        REQUIRE(populator.addFinalStatementNo(5));
        REQUIRE(populator.addVar(6, "var"));

        // check for correctness
        Table t = pkb_storage->callTable->getAll();
        REQUIRE(isAdded(t, "1", "call"));
        t = pkb_storage->constTable->getAll();
        REQUIRE(isAdded(t, "2", "20"));
        t = pkb_storage->printTable->getAll();
        REQUIRE(isAdded(t, "3", "print"));
        t = pkb_storage->procedureTable->getAll();
        REQUIRE(isAdded(t, "procedure", ""));
        t = pkb_storage->readTable->getAll();
        REQUIRE(isAdded(t, "4", "read"));
        t = pkb_storage->statementTable->getAll();
        REQUIRE(isAdded(t, "5", ""));
        t = pkb_storage->varTable->getAll();
        REQUIRE(isAdded(t, "6", "var"));
    }

    SECTION("Relation Addition") {
        REQUIRE(populator.addCalls("Caller", "Called"));
        REQUIRE(populator.addCallsT("Caller", "Called"));
        REQUIRE(populator.addFollows(7, 8));
        REQUIRE(populator.addFollowsT(9, 10));
        REQUIRE(populator.addModifiesS(11, "modifyS"));
        REQUIRE(populator.addModifiesP("ProcedureName", "modifyP"));
        REQUIRE(populator.addNext(12, 13));
        REQUIRE(populator.addParent(14, 15));
        REQUIRE(populator.addParentT(16, 17));
        REQUIRE(populator.addUsesS(18, "useS"));
        REQUIRE(populator.addUsesP("ProcedureName", "useP"));

        // check for correctness
        Table t = pkb_storage->callsTable->getAll();
        REQUIRE(isAdded(t, "Caller", "Called"));
        t = pkb_storage->callsTTable->getAll();
        REQUIRE(isAdded(t, "Caller", "Called"));
        t = pkb_storage->followsTable->getAll();
        REQUIRE(isAdded(t, "7", "8"));
        t = pkb_storage->followsTTable->getAll();
        REQUIRE(isAdded(t, "9", "10"));
        t = pkb_storage->modifiesSTable->getAll();
        REQUIRE(isAdded(t, "11", "modifyS"));
        t = pkb_storage->modifiesPTable->getAll();
        REQUIRE(isAdded(t, "ProcedureName", "modifyP"));
        t = pkb_storage->nextTable->getAll();
        REQUIRE(isAdded(t, "12", "13"));
        t = pkb_storage->parentTable->getAll();
        REQUIRE(isAdded(t, "14", "15"));
        t = pkb_storage->parentTTable->getAll();
        REQUIRE(isAdded(t, "16", "17"));
        t = pkb_storage->usesSTable->getAll();
        REQUIRE(isAdded(t, "18", "useS"));
        t = pkb_storage->usesPTable->getAll();
        REQUIRE(isAdded(t, "ProcedureName", "useP"));
    }

    SECTION("Pattern Addition") {
        REQUIRE(populator.addPatternAsgn(19, "lhs", "rhs"));
        REQUIRE(populator.addPatternIf(20, "if"));
        REQUIRE(populator.addPatternWhile(21, "while"));

        // check for correctness
        Table t = pkb_storage->patternAssignTable->getAllAsStrings();
        REQUIRE(isAdded(t, "19", "lhs=rhs"));
        t = pkb_storage->patternIfTable->getAll();
        REQUIRE(isAdded(t, "20", "if"));
        t = pkb_storage->patternWhileTable->getAll();
        REQUIRE(isAdded(t, "21", "while"));
    }
}
// ai-gen end