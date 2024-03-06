#pragma once
#define SPA_CONSTTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the const values statements and the corresponding stmtNos that are in the program.
 */
class ConstTable {
private:
    TwoSideMap<StmtNo, ConstVal> twoSideMapMM;
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
