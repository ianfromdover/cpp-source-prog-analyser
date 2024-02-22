#pragma once
#define SPA_CONSTTABLE_H

#include <optional>
#include "utilSpa/SpaTypes.h"
#include "utilSpa/TwoSideMapManyMany.hpp"

/**
 * Stores the read statements and the variables that are read in the program.
 * Note that the keys are variable names, and the values are statement numbers.
 */
class ConstTable {
private:
    TwoSideMapManyMany<StmtNo, ConstVal> twoSideMapMM;
public:
    ConstTable();
    bool addConst(StmtNo sNum, ConstVal val);
    bool hasConstAtStmt(StmtNo sNum, ConstVal val);
    bool hasConst(ConstVal val);
    bool hasStmt(StmtNo sNum);
    vector<StmtNo> getConstStmts(ConstVal val);
    // Returns the constant values by the statement number, if the constant is not found, returns empty vector
    vector<ConstVal> getConsts(StmtNo sNum);
    [[nodiscard]] int getSize() const;
};
