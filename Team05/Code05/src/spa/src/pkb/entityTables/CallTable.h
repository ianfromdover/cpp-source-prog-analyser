#pragma once
#define SPA_CALLTABLE_H

#include "utilSpa/SpaTypes.h"
#include "utilSpa/TwoSideMapOneMany.hpp"

/**
 * Stores the read statements and the variables that are read in the program.
 * Note that the keys are variable names, and the values are statement numbers.
 */
class CallTable {
private:
    TwoSideMapOneMany<VarName, StmtNo> twoSideMapOM;
public:
    CallTable();
    bool addCall(StmtNo sNum, VarName name);
    bool hasCall(StmtNo sNum, VarName name);
    bool hasVar(VarName name);
    bool hasStmt(StmtNo sNum);
    vector<StmtNo> getCallStmts(VarName name);
    // Returns the variable called by the statement number, if the variable is not found, returns an empty string.
    VarName getCallVar(StmtNo sNum);
    [[nodiscard]] int getSize() const;
};
