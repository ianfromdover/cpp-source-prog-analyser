#pragma once
#define SPA_PRINTTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMapOneMany.hpp"

/**
 * Stores the print statements and the variables that are printed in the program.
 * Note that the keys are variable names, and the values are statement numbers.
 */
class PrintTable {
private:
    TwoSideMapOneMany<VarName, StmtNo> twoSideMapOM;
public:
    PrintTable();
    bool addPrint(StmtNo sNum, VarName name);
    bool hasPrint(StmtNo sNum, VarName name);
    bool hasVar(VarName name);
    bool hasStmt(StmtNo sNum);
    vector<StmtNo> getPrintStmts(VarName name);
    // Returns the printed variable by the statement number, if the variable is not found, returns an empty string.
    VarName getPrintVar(StmtNo sNum);
    [[nodiscard]] int getSize() const;
};
