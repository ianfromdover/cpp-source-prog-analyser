#pragma once
#define SPA_STMTTABLE_H

#include "utilSpa/SpaTypes.h"

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
    vector<StmtNo> getAllStmts();
    // Returns all the statements as strings
    vector<vector<Str>> getAllAsStrings();
};
