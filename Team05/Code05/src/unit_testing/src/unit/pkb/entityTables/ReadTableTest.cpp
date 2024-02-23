#include "pkb/entityTables/ReadTable.h"
#include "catch.hpp"
using namespace std;

// ai-gen start (gpt, 1, e)
// prompt: https://platform.openai.com/playground/p/O9LSxUqjMwDpnttNKCi9MqEm?model=gpt-4&mode=chat
TEST_CASE("[PKB ReadTable] addRead") {
    ReadTable table;
    SECTION("Adding new records, insertions successful") {
        REQUIRE(table.addRead(1, "var1"));
        REQUIRE(table.addRead(2, "var2"));
    }
    SECTION("Adding existing record, insertion unsuccessful") {
        table.addRead(1, "var1");
        REQUIRE_FALSE(table.addRead(1, "var1"));
    }
}

TEST_CASE("[PKB ReadTable] addRead Stress Test") {
    ReadTable table;
    SECTION("Mass insertions, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.addRead(i, "var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB ReadTable] hasRead") {
    ReadTable table;
    table.addRead(1, "var1");
    SECTION("Existing record return true") {
        REQUIRE(table.hasRead(1, "var1"));
    }
    SECTION("Non-existing record return false") {
        REQUIRE_FALSE(table.hasRead(2, "var2"));
    }
}

TEST_CASE("[PKB ReadTable] hasRead Stress Test") {
    ReadTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addRead(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.hasRead(i, "var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB ReadTable] hasVar") {
    ReadTable table;
    table.addRead(1, "var1");
    SECTION("Existing var return true") {
        REQUIRE(table.hasVar("var1"));
    }
    SECTION("Non-existing var return false") {
        REQUIRE_FALSE(table.hasVar("var2"));
    }
}

TEST_CASE("[PKB ReadTable] hasVar Stress Test") {
    ReadTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addRead(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.hasVar("var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB ReadTable] hasStmt") {
    ReadTable table;
    table.addRead(1, "var1");
    SECTION("Existing stmt return true") {
        REQUIRE(table.hasStmt(1));
    }
    SECTION("Non-existing stmt return false") {
        REQUIRE_FALSE(table.hasStmt(2));
    }
}

TEST_CASE("[PKB ReadTable] hasStmt Stress Test") {
    ReadTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addRead(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.hasStmt(i));
        }
    }
}

TEST_CASE("[PKB ReadTable] getReadStmts") {
    ReadTable table;
    table.addRead(1, "var1");
    table.addRead(2, "var1");
    SECTION("Existing var return stmts") {
        vector<StmtNo> expected = {1, 2};
        REQUIRE(table.getReadStmts("var1") == expected);
    }
    SECTION("Non-existing var return empty vector") {
        REQUIRE(table.getReadStmts("var2").empty());
    }
}

TEST_CASE("[PKB ReadTable] getReadStmts Stress Test") {
    ReadTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 500; i++) {
            for(int j = 0; j < 200; j++) {
                table.addRead(i * 200 + j, "var" + std::to_string(i));
            }
        }
        for(int i = 0; i < 500; i++) {
            REQUIRE(table.getReadStmts("var" + std::to_string(i)).size() == 200);
        }
    }
}

TEST_CASE("[PKB ReadTable] getReadVar") {
    ReadTable table;
    table.addRead(1, "var1");
    SECTION("Existing stmt return var") {
        REQUIRE(table.getReadVar(1) == "var1");
    }
    SECTION("Non-existing stmt return empty string") {
        REQUIRE(table.getReadVar(2) == "");
    }
}

TEST_CASE("[PKB ReadTable] getReadVar Stress Test") {
    ReadTable table;
    SECTION("Mass queries, table does not crash") {
        for(int i = 0; i < 100000; i++) {
            table.addRead(i, "var" + std::to_string(i));
        }
        for(int i = 0; i < 100000; i++) {
            REQUIRE(table.getReadVar(i) == ("var" + std::to_string(i)));
        }
    }
}

TEST_CASE("[PKB ReadTable] getSize") {
    ReadTable table;
    SECTION("New table size is 0") {
        REQUIRE(table.getSize() == 0);
    }
    SECTION("After addRead size is increased") {
        table.addRead(1, "var1");
        REQUIRE(table.getSize() == 1);
    }
}

TEST_CASE("[PKB ReadTable] getSize Stress Test") {
    ReadTable table;
    SECTION("After mass insertions, size is expected") {
        for(int i = 0; i < 100000; i++) {
            table.addRead(i, "var" + std::to_string(i));
        }
        REQUIRE(table.getSize() == 100000);
    }
}
// ai-gen end

// ai-gen start (gpt, 1, e)
// prompt: https://platform.openai.com/playground/p/mV5h6xJgGSD4fS0wuvhDDuhB?model=gpt-4-turbo-preview&mode=chat

TEST_CASE("[PKB ReadTable] addRead 2") {
    ReadTable readTable;

    SECTION("Add read statement successfully") {
        REQUIRE(readTable.addRead(1, "x"));
    }

    SECTION("Add multiple read statements for different variables") {
        REQUIRE(readTable.addRead(1, "x"));
        REQUIRE(readTable.addRead(2, "y"));
    }

    SECTION("Add multiple read statements for the same variable, different statement numbers") {
        REQUIRE(readTable.addRead(1, "x"));
        REQUIRE(readTable.addRead(3, "x"));
    }

    SECTION("Adding read statement with the same statement number should fail") {
        REQUIRE(readTable.addRead(1, "x"));
        REQUIRE_FALSE(readTable.addRead(1, "y"));
    }
}

TEST_CASE("[PKB ReadTable] hasRead 2") {
    ReadTable readTable;
    readTable.addRead(1, "x");
    readTable.addRead(2, "y");

    SECTION("Variable is read in the given statement number") {
        REQUIRE(readTable.hasRead(1, "x"));
    }

    SECTION("Variable is not read in the given statement number") {
        REQUIRE_FALSE(readTable.hasRead(2, "x"));
    }

    SECTION("Statement number without any read does not exist") {
        REQUIRE_FALSE(readTable.hasRead(3, "z"));
    }
}

TEST_CASE("[PKB ReadTable] getReadStmts 2") {
    ReadTable readTable;
    readTable.addRead(1, "x");
    readTable.addRead(3, "x");

    SECTION("Get statement numbers for a variable with multiple reads") {
        auto stmts = readTable.getReadStmts("x");
        std::sort(stmts.begin(), stmts.end());
        vector<StmtNo> expectedStmts = {1, 3};
        REQUIRE(stmts == expectedStmts);
    }

    SECTION("Get statement numbers for a variable with no reads") {
        auto stmts = readTable.getReadStmts("y");
        vector<StmtNo> expectedStmts = {};
        REQUIRE(stmts == expectedStmts);
    }
}

TEST_CASE("[PKB ReadTable] getReadVar 2") {
    ReadTable readTable;
    readTable.addRead(1, "x");
    readTable.addRead(2, "y");

    SECTION("Get variable for a given read statement number") {
        REQUIRE(readTable.getReadVar(1) == "x");
    }

    SECTION("Get variable for a statement number with no reads returns empty") {
        REQUIRE(readTable.getReadVar(3).empty());
    }
}
// ai-gen end
