#pragma once
#define SPA_PRINTTABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the print statements and the variables that are printed in the program.
 * Note that the keys are variable names, and the values are statement numbers.
 */
class PrintTable {
private:
    TwoSideMap<StmtNo, VarName> map;
public:
    PrintTable();
    // Adds a print statement to the table, returns false if it already exists
    bool addPrint(StmtNo sNum, VarName name);
    // Returns the statement numbers of the statements that print a variable
    vector<StmtNo> getPrintStmts(VarName name);
    // Returns the printed variable by the statement number, if the variable is not found, returns an empty vector.
    vector<VarName> getPrintVar(StmtNo sNum);
    // Returns all the print statements and printed vars as strings in 2 columns: StmtNo | VarName
    vector<vector<Str>> getAllAsStrings();
};
