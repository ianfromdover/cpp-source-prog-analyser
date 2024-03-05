#pragma once
#define SPA_CALLTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMapOneMany.hpp"

/**
 * Stores the call statements and the procnames that are called in the program.
 * Note that the keys are variable names, and the values are statement numbers.
 */
class CallTable {
private:
    TwoSideMapOneMany<ProcName, StmtNo> twoSideMapOM;
public:
    CallTable();
    bool addCall(StmtNo sNum, ProcName name);
    bool hasCall(StmtNo sNum, ProcName name);
    bool hasProc(ProcName name);
    bool hasStmt(StmtNo sNum);
    vector<StmtNo> getStmts(ProcName name);
    // Returns the variable called by the statement number, if the variable is not found, returns an empty string.
    ProcName getProc(StmtNo sNum);
    [[nodiscard]] int getSize() const;
};
