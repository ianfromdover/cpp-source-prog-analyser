#include "pkb/entityTables/ProcedureTable.h"
#include "catch.hpp"
using namespace std;

// ai-gen start (gpt, 1, e)
// prompt: https://chat.openai.com/share/7339672c-a332-4050-8dd8-b2ae07346d6b

TEST_CASE("[PKB ProcedureTable] addProc") {
    ProcedureTable procedureTable;

    SECTION("Adding a procedure") {
        std::string procName = "procedure1";
        REQUIRE(procedureTable.addProc(procName) == true);
        REQUIRE(procedureTable.hasProc(procName) == true);
    }

    // Add more test cases for boundary testing and edge cases
}

TEST_CASE("[PKB ProcedureTable] hasProc") {
    ProcedureTable procedureTable;

    SECTION("Checking for procedure existence") {
        std::string procName = "procedure1";
        procedureTable.addProc(procName);
        REQUIRE(procedureTable.hasProc(procName) == true);
    }

    // Add more test cases to cover various scenarios
}

TEST_CASE("[PKB ProcedureTable] getAllProcs") {
    ProcedureTable procedureTable;

    SECTION("Getting all procedures") {
        procedureTable.addProc("procedure1");
        procedureTable.addProc("procedure2");
        procedureTable.addProc("procedure3");

        auto procs = procedureTable.getAllProcs();
        REQUIRE(procs.size() == 3);
        // Add more detailed checks if needed
    }

    // Add more test cases to cover edge cases and boundary testing
}

TEST_CASE("[PKB ProcedureTable] getSize") {
    ProcedureTable procedureTable;

    SECTION("Getting size of ProcedureTable") {
        REQUIRE(procedureTable.getSize() == 0);

        procedureTable.addProc("procedure1");
        REQUIRE(procedureTable.getSize() == 1);

        procedureTable.addProc("procedure2");
        REQUIRE(procedureTable.getSize() == 2);

        // Add more detailed checks if needed
    }

    // Add more test cases to cover edge cases and boundary testing
}

// ai-gen end