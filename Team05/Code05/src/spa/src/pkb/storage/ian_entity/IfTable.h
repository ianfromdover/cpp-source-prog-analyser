#pragma once
#define SPA_IFTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the if statements and the variables in their predicates in the program.
 */
class IfTable {
private:
    TwoSideMap<StmtNo, VarName> map;
public:
    IfTable();
    // Adds an if statement to the table, returns false if it already exists
    bool addIf(StmtNo sNum, VarName ctrlVarName);
    // Returns the statement numbers of the if-statements that have the control variable
    vector<StmtNo> getIfStmts(VarName ctrlVarName);
    // Returns the control variables in this if-statement, if not found, returns empty vector
    vector<VarName> getIfVars(StmtNo sNum);
    // Returns all the if statements and ctrl vars as strings in 2 columns: StmtNo | VarName
    vector<vector<Str>> getAllAsStrings();
};
