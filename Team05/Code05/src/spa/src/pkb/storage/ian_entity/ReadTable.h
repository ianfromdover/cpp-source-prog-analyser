#pragma once
#define SPA_READTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the read statements and the variables that are read in the program.
 * Note that the keys are variable names, and the values are statement numbers.
 * TODO: reverse VarName StmtNo in tests
 */
class ReadTable {
private:
    TwoSideMap<StmtNo, VarName> twoSideMapOM;
public:
    ReadTable();
    bool addRead(StmtNo sNum, VarName name);
    vector<StmtNo> getReadStmts(VarName name);
    // Returns the variable read by the statement number, if the variable is not found, returns an empty string.
    vector<VarName> getReadVar(StmtNo sNum);
};
