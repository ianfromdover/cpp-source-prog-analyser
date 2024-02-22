#include "pkb/entityTables/CallTable.h"
#include "catch.hpp"
using namespace std;

TEST_CASE("[PKB CallTable] addCall") {
    CallTable table;
    SECTION("Adding new records, insertions successful") {
        REQUIRE(table.addCall(1, "var1"));
        REQUIRE(table.addCall(2, "var2"));
    }
    SECTION("Adding existing record, insertion unsuccessful") {
        table.addCall(1, "var1");
        REQUIRE_FALSE(table.addCall(1, "var1"));
    }
}

TEST_CASE("[PKB CallTable] addCall Stress Test") {
    CallTable table;
    SECTION("Mass insertions, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.addCall(i, "var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB CallTable] hasCall") {
    CallTable table;
    table.addCall(1, "var1");
    SECTION("Existing record return true") {
        REQUIRE(table.hasCall(1, "var1"));
    }
    SECTION("Non-existing record return false") {
        REQUIRE_FALSE(table.hasCall(2, "var2"));
    }
}

TEST_CASE("[PKB CallTable] hasCall Stress Test") {
    CallTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addCall(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.hasCall(i, "var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB CallTable] hasVar") {
    CallTable table;
    table.addCall(1, "var1");
    SECTION("Existing var return true") {
        REQUIRE(table.hasVar("var1"));
    }
    SECTION("Non-existing var return false") {
        REQUIRE_FALSE(table.hasVar("var2"));
    }
}

TEST_CASE("[PKB CallTable] hasVar Stress Test") {
    CallTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addCall(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.hasVar("var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB CallTable] hasStmt") {
    CallTable table;
    table.addCall(1, "var1");
    SECTION("Existing stmt return true") {
        REQUIRE(table.hasStmt(1));
    }
    SECTION("Non-existing stmt return false") {
        REQUIRE_FALSE(table.hasStmt(2));
    }
}

TEST_CASE("[PKB CallTable] hasStmt Stress Test") {
    CallTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addCall(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.hasStmt(i));
        }
    }
}

TEST_CASE("[PKB CallTable] getCallStmts") {
    CallTable table;
    table.addCall(1, "var1");
    table.addCall(2, "var1");
    SECTION("Existing var return stmts") {
        vector<StmtNo> expected = {1, 2};
        REQUIRE(table.getCallStmts("var1") == expected);
    }
    SECTION("Non-existing var return empty vector") {
        REQUIRE(table.getCallStmts("var2").empty());
    }
}

TEST_CASE("[PKB CallTable] getCallStmts Stress Test") {
    CallTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 500; i++) {
            for(int j = 0; j < 200; j++) {
                table.addCall(i * 200 + j, "var" + std::to_string(i));
            }
        }
        for(int i = 0; i < 500; i++) {
            REQUIRE(table.getCallStmts("var" + std::to_string(i)).size() == 200);
        }
    }
}

TEST_CASE("[PKB CallTable] getCallVar") {
    CallTable table;
    table.addCall(1, "var1");
    SECTION("Existing stmt return var") {
        REQUIRE(table.getCallVar(1) == "var1");
    }
    SECTION("Non-existing stmt return empty string") {
        REQUIRE(table.getCallVar(2) == "");
    }
}

TEST_CASE("[PKB CallTable] getCallVar Stress Test") {
    CallTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addCall(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.getCallVar(i) == ("var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB CallTable] getSize") {
    CallTable table;
    SECTION("New table size is 0") {
        REQUIRE(table.getSize() == 0);
    }
    SECTION("After addCall size is increased") {
        table.addCall(1, "var1");
        REQUIRE(table.getSize() == 1);
    }
}

TEST_CASE("[PKB CallTable] getSize Stress Test") {
    CallTable table;
    SECTION("After mass insertions, size is expected") {
        for(int i = 0; i < 100000; i++) {
            table.addCall(i, "var" + std::to_string(i));
        }
        REQUIRE(table.getSize() == 100000);
    }
}
// ai-gen end

// ai-gen start (gpt, 1, e)
// prompt: https://platform.openai.com/playground/p/mV5h6xJgGSD4fS0wuvhDDuhB?model=gpt-4-turbo-preview&mode=chat

TEST_CASE("[PKB CallTable] addCall 2") {
    CallTable readTable;

    SECTION("Add read statement successfully") {
        REQUIRE(readTable.addCall(1, "x"));
    }

    SECTION("Add multiple read statements for different variables") {
        REQUIRE(readTable.addCall(1, "x"));
        REQUIRE(readTable.addCall(2, "y"));
    }

    SECTION("Add multiple read statements for the same variable, different statement numbers") {
        REQUIRE(readTable.addCall(1, "x"));
        REQUIRE(readTable.addCall(3, "x"));
    }

    SECTION("Adding read statement with the same statement number should fail") {
        REQUIRE(readTable.addCall(1, "x"));
        REQUIRE_FALSE(readTable.addCall(1, "y"));
    }
}

TEST_CASE("[PKB CallTable] hasCall 2") {
    CallTable readTable;
    readTable.addCall(1, "x");
    readTable.addCall(2, "y");

    SECTION("Variable is read in the given statement number") {
        REQUIRE(readTable.hasCall(1, "x"));
    }

    SECTION("Variable is not read in the given statement number") {
        REQUIRE_FALSE(readTable.hasCall(2, "x"));
    }

    SECTION("Statement number without any read does not exist") {
        REQUIRE_FALSE(readTable.hasCall(3, "z"));
    }
}

TEST_CASE("[PKB CallTable] getCallStmts 2") {
    CallTable readTable;
    readTable.addCall(1, "x");
    readTable.addCall(3, "x");

    SECTION("Get statement numbers for a variable with multiple reads") {
        auto stmts = readTable.getCallStmts("x");
        std::sort(stmts.begin(), stmts.end());
        vector<StmtNo> expectedStmts = {1, 3};
        REQUIRE(stmts == expectedStmts);
    }

    SECTION("Get statement numbers for a variable with no reads") {
        auto stmts = readTable.getCallStmts("y");
        vector<StmtNo> expectedStmts = {};
        REQUIRE(stmts == expectedStmts);
    }
}

TEST_CASE("[PKB CallTable] getCallVar 2") {
    CallTable readTable;
    readTable.addCall(1, "x");
    readTable.addCall(2, "y");

    SECTION("Get variable for a given read statement number") {
        REQUIRE(readTable.getCallVar(1) == "x");
    }

    SECTION("Get variable for a statement number with no reads returns empty") {
        REQUIRE(readTable.getCallVar(3).empty());
    }
}
