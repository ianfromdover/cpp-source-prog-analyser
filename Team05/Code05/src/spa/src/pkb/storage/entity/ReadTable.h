#pragma once
#define SPA_READTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the read statements and the variables that are read in the program.
 * Note that the keys are variable names, and the values are statement numbers.
 */
class ReadTable {
private:
    TwoSideMap<StmtNo, VarName> map;
public:
    ReadTable();
    // Adds a read statement to the table, returns false if it already exists
    bool addRead(StmtNo sNum, VarName name);
    // Returns the statement numbers of the statements that read a variable
    vector<StmtNo> getReadStmts(VarName name);
    // Returns the variable read by the statement number, if the variable is not found, returns an empty vector.
    vector<VarName> getReadVar(StmtNo sNum);
    // Returns all the read statements and read vars as strings in 2 columns: StmtNo | VarName
    vector<vector<Str>> getAllAsStrings();
};
