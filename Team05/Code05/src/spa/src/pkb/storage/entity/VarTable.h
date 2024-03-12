#pragma once
#define SPA_VARTABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the variable names and the corresponding stmtNos that are in the program.
 */
class VarTable {
private:
    TwoSideMap<StmtNo, VarName> map;
public:
    VarTable();
    // Adds a variable name to the table, returns false if it already exists
    bool addVar(StmtNo sNum, VarName val);
    // Returns the variable name if it exists, if not found, returns empty vector
    vector<VarName> getVarByName(VarName val);
    // Returns the statement numbers that the variable is on
    vector<StmtNo> getVarStmts(VarName val);
    // Returns the variable name by the statement number, if not found, returns empty vector
    vector<VarName> getVarNameByStmt(StmtNo sNum);
    // Returns all the variable names as strings in 2 columns: StmtNo | VarName
    vector<vector<Str>> getAllAsStrings();
};
