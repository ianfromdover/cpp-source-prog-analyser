#pragma once
#define SPA_IFTABLE_H

#include <optional>
#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMapManyMany.hpp"

/**
 * Stores the if statements and the variables in their predicates in the program.
 */
class IfTable {
private:
    TwoSideMapManyMany<StmtNo, VarName> twoSideMapMM;
public:
    IfTable();
    bool addIf(StmtNo sNum, VarName ctrlVarNames);
    bool hasIfAtStmt(StmtNo sNum, VarName ctrlVarNames);
    bool hasIf(VarName ctrlVarNames);
    bool hasStmt(StmtNo sNum);
    vector<StmtNo> getIfStmts(VarName ctrlVarNames);
    // Returns the constant values by the statement number, if the constant is not found, returns empty vector
    vector<VarName> getIfs(StmtNo sNum);
    [[nodiscard]] int getSize() const;
};
