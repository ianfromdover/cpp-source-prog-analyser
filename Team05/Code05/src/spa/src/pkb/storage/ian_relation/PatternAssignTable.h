#pragma once
#define SPA_PATTERN_ASGN_TABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * Stores the pattern relationship for assign statements.
 * Eg. 1. x = 30;
 *     StmtNo = 1
 *     Lhs = x
 *     Rhs = 30
 */
class PatternAssignTable {
private:
    TwoSideMap<StmtNo, VarName> twoSideMapMMStmtLhs; // name is key then value
    TwoSideMap<StmtNo, VarName> twoSideMapMMStmtRhs;
    TwoSideMap<VarName, VarName> twoSideMapMMLhsRhs;
public:
    PatternAssignTable();

    // -------- For StmtNo | VarName LHS table
    bool addStmtLhs(StmtNo stmtNo, VarName varName); // Adds
    bool isStmtLhs(StmtNo stmtNo, VarName varName); // Checks pair
    bool hasLhsFromStmt(StmtNo stmtNo); // Checks if key exists
    bool hasLhs(VarName varName); // Checks if value exists
    std::vector<StmtNo> getStmtsFromLhs(VarName varName); // Gets keys
    std::vector<VarName> getLhsVarsFromStmt(StmtNo stmtNo); // Gets values
    int getSizeStmtLhs() const; // Gets size

    // -------- For StmtNo | VarName RHS table
    bool addStmtRhs(StmtNo stmtNo, VarName varName);
    bool isStmtRhs(StmtNo stmtNo, VarName varName);
    bool hasRhsFromStmt(StmtNo stmtNo);
    bool hasRhs(VarName varName);
    std::vector<StmtNo> getStmtsFromRhs(VarName varName);
    std::vector<VarName> getRhsVarsFromStmt(StmtNo stmtNo);
    int getSizeStmtRhs() const;


    // -------- For VarName LHS | VarName RHS table
    bool addLhsRhs(VarName lhs, VarName rhs);
    bool isLhsRhs(VarName lhs, VarName rhs);
    bool hasLhsFromRhs(VarName rhs);
    bool hasRhsFromLhs(VarName lhs);
    std::vector<VarName> getLhsFromRhs(VarName rhs);
    std::vector<VarName> getRhsFromLhs(VarName lhs);
    int getSizeLhsRhs() const;
};

