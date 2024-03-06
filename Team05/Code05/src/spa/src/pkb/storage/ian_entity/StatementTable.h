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
    bool addFinalStatementNo(StmtNo sNum);
    // Returns a vector of statement 1...finalStatementNum
    vector<StmtNo> getAllStmts();
};
