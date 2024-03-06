#include "PatternAssignTable.h"

PatternAssignTable::PatternAssignTable() = default;

// ai-gen start (copilot, 2, e)
// prompt: used copilot
// -------- For StmtNo | VarName LHS table

// Adds
bool PatternAssignTable::addStmtLhs(StmtNo stmtNo, VarName varName) {
    return stmtLhsMap.insert(stmtNo, varName);
}
std::vector<StmtNo> PatternAssignTable::getStmtsFromLhs(VarName varName) {
    return stmtLhsMap.getKeys(varName);
}
// Gets values
std::vector<VarName> PatternAssignTable::getLhsVarsFromStmt(StmtNo stmtNo) {
    return stmtLhsMap.getValues(stmtNo);
}
vector<vector<Str>> PatternAssignTable::getAllStmtLhs() {
    return {};
    // return stmtLhsMap.getAll();
}

// -------- For StmtNo | VarName RHS table

bool PatternAssignTable::addStmtRhs(StmtNo stmtNo, VarName varName) {
    return stmtRhsMap.insert(stmtNo, varName);
}
std::vector<StmtNo> PatternAssignTable::getStmtsFromRhs(VarName varName) {
    return stmtRhsMap.getKeys(varName);
}
std::vector<VarName> PatternAssignTable::getRhsVarsFromStmt(StmtNo stmtNo) {
    return stmtRhsMap.getValues(stmtNo);
}
vector<vector<Str>> PatternAssignTable::getAllStmtRhs() {
    return {};
    // return stmtRhsMap.getAll();
}

// -------- For VarName LHS | VarName RHS table
bool PatternAssignTable::addLhsRhs(VarName lhs, VarName rhs) {
    return lhsRhsMap.insert(lhs, rhs);
}
std::vector<VarName> PatternAssignTable::getLhsFromRhs(VarName rhs) {
    return lhsRhsMap.getKeys(rhs);
}
std::vector<VarName> PatternAssignTable::getRhsFromLhs(VarName lhs) {
    return lhsRhsMap.getValues(lhs);
}
// ai-gen end
vector<vector<Str>> PatternAssignTable::getAllLhsRhs() {
    return {};
    // return lhsRhsMap.getAll();
}
