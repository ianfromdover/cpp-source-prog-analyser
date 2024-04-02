#pragma once
#define SPA_STMTTABLE_H

#include "common/SpaTypes.h"

/**
 * Stores statement numbers
 */
class StatementTable {
private:
    StmtNo finalStatementNum;
public:
    StatementTable();
    // Saves the final statement number so the table can generate a list of statements until it
    bool addFinalStatementNo(StmtNo sNum);
    // Returns a vector of statement 1...finalStatementNum
    // Returns all the statements as strings
    Table getAll();
};
