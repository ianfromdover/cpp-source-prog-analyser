#pragma once
#define SPA_READTABLE_H

#include "utilSpa/SpaTypes.h"
#include "utilSpa/TwoSideMapOneMany.hpp"

/**
 * Stores the read statements and the variables that are read in the program.
 * Note that the keys are variable names, and the values are statement numbers.
 */
class ReadTable {
private:
    TwoSideMapOneMany<VarName, StmtNo> twoSideMapOM;
public:
    ReadTable();
    bool addRead(StmtNo sNum, VarName name);
    bool hasRead(StmtNo sNum, VarName name);
    bool hasVar(VarName name);
    bool hasStmt(StmtNo sNum);
    vector<StmtNo> getReadStmts(VarName name);
    // Returns the variable read by the statement number, if the variable is not found, returns an empty string.
    VarName getReadVar(StmtNo sNum);
    [[nodiscard]] int getSize() const;
};
