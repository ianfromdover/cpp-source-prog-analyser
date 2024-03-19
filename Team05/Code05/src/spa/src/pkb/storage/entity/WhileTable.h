#pragma once
#define SPA_WHILETABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the while statements and the variables in their predicates in the program.
 */
class WhileTable {
private:
    TwoSideMap<StmtNo, VarName> map;
public:
    WhileTable();
    // Adds a while statement to the table, returns false if it already exists
    bool addWhile(StmtNo sNum, VarName ctrlVarNames);
    // Returns the statement numbers of the while-statements that have the control variable
    vector<StmtNo> getWhileStmts(VarName ctrlVarNames);
    // Returns the control variables in this while-statement, if not found, returns empty vector
    vector<VarName> getWhileVars(StmtNo sNum);
    // Returns all the while statements and ctrl vars as strings in 2 columns: StmtNo | VarName
    Table getAllAsStrings();
};
