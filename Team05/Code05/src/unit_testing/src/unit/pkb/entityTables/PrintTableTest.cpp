#include "pkb/entityTables/PrintTable.h"
#include "catch.hpp"
using namespace std;

TEST_CASE("[PKB PrintTable] addPrint") {
    PrintTable table;
    SECTION("Adding new records, insertions successful") {
        REQUIRE(table.addPrint(1, "var1"));
        REQUIRE(table.addPrint(2, "var2"));
    }
    SECTION("Adding existing record, insertion unsuccessful") {
        table.addPrint(1, "var1");
        REQUIRE_FALSE(table.addPrint(1, "var1"));
    }
}

TEST_CASE("[PKB PrintTable] addPrint Stress Test") {
    PrintTable table;
    SECTION("Mass insertions, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.addPrint(i, "var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB PrintTable] hasPrint") {
    PrintTable table;
    table.addPrint(1, "var1");
    SECTION("Existing record return true") {
        REQUIRE(table.hasPrint(1, "var1"));
    }
    SECTION("Non-existing record return false") {
        REQUIRE_FALSE(table.hasPrint(2, "var2"));
    }
}

TEST_CASE("[PKB PrintTable] hasPrint Stress Test") {
    PrintTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addPrint(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.hasPrint(i, "var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB PrintTable] hasVar") {
    PrintTable table;
    table.addPrint(1, "var1");
    SECTION("Existing var return true") {
        REQUIRE(table.hasVar("var1"));
    }
    SECTION("Non-existing var return false") {
        REQUIRE_FALSE(table.hasVar("var2"));
    }
}

TEST_CASE("[PKB PrintTable] hasVar Stress Test") {
    PrintTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addPrint(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.hasVar("var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB PrintTable] hasStmt") {
    PrintTable table;
    table.addPrint(1, "var1");
    SECTION("Existing stmt return true") {
        REQUIRE(table.hasStmt(1));
    }
    SECTION("Non-existing stmt return false") {
        REQUIRE_FALSE(table.hasStmt(2));
    }
}

TEST_CASE("[PKB PrintTable] hasStmt Stress Test") {
    PrintTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addPrint(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.hasStmt(i));
        }
    }
}

TEST_CASE("[PKB PrintTable] getPrintStmts") {
    PrintTable table;
    table.addPrint(1, "var1");
    table.addPrint(2, "var1");
    SECTION("Existing var return stmts") {
        vector<StmtNo> expected = {1, 2};
        REQUIRE(table.getPrintStmts("var1") == expected);
    }
    SECTION("Non-existing var return empty vector") {
        REQUIRE(table.getPrintStmts("var2").empty());
    }
}

TEST_CASE("[PKB PrintTable] getPrintStmts Stress Test") {
    PrintTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 500; i++) {
            for(int j = 0; j < 200; j++) {
                table.addPrint(i * 200 + j, "var" + std::to_string(i));
            }
        }
        for(int i = 0; i < 500; i++) {
            REQUIRE(table.getPrintStmts("var" + std::to_string(i)).size() == 200);
        }
    }
}

TEST_CASE("[PKB PrintTable] getPrintVar") {
    PrintTable table;
    table.addPrint(1, "var1");
    SECTION("Existing stmt return var") {
        REQUIRE(table.getPrintVar(1) == "var1");
    }
    SECTION("Non-existing stmt return empty string") {
        REQUIRE(table.getPrintVar(2) == "");
    }
}

TEST_CASE("[PKB PrintTable] getPrintVar Stress Test") {
    PrintTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addPrint(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.getPrintVar(i) == ("var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB PrintTable] getSize") {
    PrintTable table;
    SECTION("New table size is 0") {
        REQUIRE(table.getSize() == 0);
    }
    SECTION("After addPrint size is increased") {
        table.addPrint(1, "var1");
        REQUIRE(table.getSize() == 1);
    }
}

TEST_CASE("[PKB PrintTable] getSize Stress Test") {
    PrintTable table;
    SECTION("After mass insertions, size is expected") {
        for(int i = 0; i < 100000; i++) {
            table.addPrint(i, "var" + std::to_string(i));
        }
        REQUIRE(table.getSize() == 100000);
    }
}
// ai-gen end

// ai-gen start (gpt, 1, e)
// prompt: https://platform.openai.com/playground/p/mV5h6xJgGSD4fS0wuvhDDuhB?model=gpt-4-turbo-preview&mode=chat

TEST_CASE("[PKB PrintTable] addPrint 2") {
    PrintTable readTable;

    SECTION("Add read statement successfully") {
        REQUIRE(readTable.addPrint(1, "x"));
    }

    SECTION("Add multiple read statements for different variables") {
        REQUIRE(readTable.addPrint(1, "x"));
        REQUIRE(readTable.addPrint(2, "y"));
    }

    SECTION("Add multiple read statements for the same variable, different statement numbers") {
        REQUIRE(readTable.addPrint(1, "x"));
        REQUIRE(readTable.addPrint(3, "x"));
    }

    SECTION("Adding read statement with the same statement number should fail") {
        REQUIRE(readTable.addPrint(1, "x"));
        REQUIRE_FALSE(readTable.addPrint(1, "y"));
    }
}

TEST_CASE("[PKB PrintTable] hasPrint 2") {
    PrintTable readTable;
    readTable.addPrint(1, "x");
    readTable.addPrint(2, "y");

    SECTION("Variable is read in the given statement number") {
        REQUIRE(readTable.hasPrint(1, "x"));
    }

    SECTION("Variable is not read in the given statement number") {
        REQUIRE_FALSE(readTable.hasPrint(2, "x"));
    }

    SECTION("Statement number without any read does not exist") {
        REQUIRE_FALSE(readTable.hasPrint(3, "z"));
    }
}

TEST_CASE("[PKB PrintTable] getPrintStmts 2") {
    PrintTable readTable;
    readTable.addPrint(1, "x");
    readTable.addPrint(3, "x");

    SECTION("Get statement numbers for a variable with multiple reads") {
        auto stmts = readTable.getPrintStmts("x");
        std::sort(stmts.begin(), stmts.end());
        vector<StmtNo> expectedStmts = {1, 3};
        REQUIRE(stmts == expectedStmts);
    }

    SECTION("Get statement numbers for a variable with no reads") {
        auto stmts = readTable.getPrintStmts("y");
        vector<StmtNo> expectedStmts = {};
        REQUIRE(stmts == expectedStmts);
    }
}

TEST_CASE("[PKB PrintTable] getPrintVar 2") {
    PrintTable readTable;
    readTable.addPrint(1, "x");
    readTable.addPrint(2, "y");

    SECTION("Get variable for a given read statement number") {
        REQUIRE(readTable.getPrintVar(1) == "x");
    }

    SECTION("Get variable for a statement number with no reads returns empty") {
        REQUIRE(readTable.getPrintVar(3).empty());
    }
}
