#pragma once
#define SPA_WHILETABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the while statements and the variables in their predicates in the program.
 */
class WhileTable {
private:
    TwoSideMap<StmtNo, VarName> twoSideMapMM;
public:
    WhileTable();
    bool addWhile(StmtNo sNum, VarName ctrlVarNames);
    bool hasWhileAtStmt(StmtNo sNum, VarName ctrlVarNames);
    bool hasWhile(VarName ctrlVarNames);
    bool hasStmt(StmtNo sNum);
    vector<StmtNo> getWhileStmts(VarName ctrlVarNames);
    // Returns the constant values by the statement number, if the constant is not found, returns empty vector
    vector<VarName> getWhiles(StmtNo sNum);
    [[nodiscard]] int getSize() const;
};
