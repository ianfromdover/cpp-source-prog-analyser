#pragma once
#define SPA_PRINTTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the print statements and the variables that are printed in the program.
 * Note that the keys are variable names, and the values are statement numbers.
 */
class PrintTable {
private:
    TwoSideMap<VarName, StmtNo> twoSideMapOM;
public:
    PrintTable();
    bool addPrint(StmtNo sNum, VarName name);
    vector<StmtNo> getPrintStmts(VarName name);
    // Returns the printed variable by the statement number, if the variable is not found, returns an empty string.
    vector<VarName> getPrintVar(StmtNo sNum);
    [[nodiscard]] int getSize() const;
};
