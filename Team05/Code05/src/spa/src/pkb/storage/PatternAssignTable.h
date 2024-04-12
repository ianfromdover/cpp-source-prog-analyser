#pragma once
#define SPA_PATTERN_ASGN_TABLE_H

#include "common/SpaTypes.h"
#include "PkbTable.hpp"

/**
 * Stores the pattern relationship for assign statements.
 * Eg. 1. x = 30;
 *     StmtNo = 1
 *     Lhs = x
 *     Rhs = 30
 */
class PatternAssignTable {
private:
    PkbTable<StmtNo, VarName> stmtLhsMap;
    PkbTable<StmtNo, VarName> stmtRhsMap;
    PkbTable<VarName, VarName> lhsRhsMap;
public:
    PatternAssignTable();

    bool isAsgn(StmtNo sNum);
    // -------- For StmtNo | VarName LHS table
    bool addStmtLhs(StmtNo stmtNo, VarName varName); // Adds
    std::vector<StmtNo> getStmtsFromLhs(VarName varName); // Gets keys
    std::vector<VarName> getLhsVarsFromStmt(StmtNo stmtNo); // Gets values
    // Gets a table with 2 columns, StmtNo | VarName
    Table getAllStmtLhs();

    // -------- For StmtNo | VarName RHS table
    bool addStmtRhs(StmtNo stmtNo, VarName varName);
    std::vector<StmtNo> getStmtsFromRhs(VarName varName);
    std::vector<VarName> getRhsVarsFromStmt(StmtNo stmtNo);
    // Gets a table with 2 columns, StmtNo | VarName
    Table getAllStmtRhs();


    // -------- For VarName LHS | VarName RHS table
    bool addLhsRhs(VarName lhs, VarName rhs);
    std::vector<VarName> getLhsFromRhs(VarName rhs);
    std::vector<VarName> getRhsFromLhs(VarName lhs);
    // Gets a table with 2 columns, VarName | VarName
    Table getAllLhsRhs();

    // -------- For StmtNo | VarName LHS | VarName RHS table
    // Gets a table with 3 columns, StmtNo | VarName | VarName
    Table getAllAsStrings();
};

