#pragma once
#define SPA_CALLTABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the call statements and the ProcNames that are called in the program.
 */
class CallTable {
private:
    TwoSideMap<StmtNo, ProcName> map;
public:
    CallTable();
    // Adds a call statement to the call table, returns false if it already exists
    bool addCall(StmtNo sNum, ProcName name);
    // Returns the statement numbers of the call statements based on what they call
    vector<StmtNo> getStmts(ProcName name);
    // Returns the procedures that are called by this statement number
    vector<ProcName> getProc(StmtNo sNum);
    // Returns all the call statements as strings in 2 columns: ProcName | StmtNo
    vector<vector<Str>> getAllAsStrings();
};
