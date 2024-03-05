#include "PatternAssignTable.h"

PatternAssignTable::PatternAssignTable() = default;

// ai-gen start (copilot, 1, e)
// prompt: used copilot
// -------- For StmtNo | VarName LHS table

// Adds
bool PatternAssignTable::addStmtLhs(StmtNo stmtNo, VarName varName) {
    if (isStmtLhs(stmtNo, varName)) {
        return false;
    }
    return twoSideMapMMStmtLhs.insert(stmtNo, varName);
}
// Checks pair
bool PatternAssignTable::isStmtLhs(StmtNo stmtNo, VarName varName) {
    if (!twoSideMapMMStmtLhs.containsKey(stmtNo)
        || !twoSideMapMMStmtLhs.containsValue(varName)) {
        return false;
    }
    auto stmts = twoSideMapMMStmtLhs.getKeys(varName);
    // return true if the stmtNo is found in the list of stmtNo for the varName
    return std::find(stmts.begin(), stmts.end(), stmtNo) != stmts.end();
}
// Checks if key exists
bool PatternAssignTable::hasLhsFromStmt(StmtNo stmtNo) {
    return twoSideMapMMStmtLhs.containsKey(stmtNo);
}
// Checks if value exists
bool PatternAssignTable::hasLhs(VarName varName) {
    return twoSideMapMMStmtLhs.containsValue(varName);
}
// Gets keys
std::vector<StmtNo> PatternAssignTable::getStmtsFromLhs(VarName varName) {
    return twoSideMapMMStmtLhs.getKeys(varName);
}
// Gets values
std::vector<VarName> PatternAssignTable::getLhsVarsFromStmt(StmtNo stmtNo) {
    return twoSideMapMMStmtLhs.getValues(stmtNo);
}
// Gets size
int PatternAssignTable::getSizeStmtLhs() const {
    return twoSideMapMMStmtLhs.size();
}

// -------- For StmtNo | VarName RHS table

bool PatternAssignTable::addStmtRhs(StmtNo stmtNo, VarName varName) {
    if (isStmtRhs(stmtNo, varName)) {
        return false;
    }
    return twoSideMapMMStmtRhs.insert(stmtNo, varName);
}
bool PatternAssignTable::isStmtRhs(StmtNo stmtNo, VarName varName) {
    if (!twoSideMapMMStmtRhs.containsKey(stmtNo)
        || !twoSideMapMMStmtRhs.containsValue(varName)) {
        return false;
    }
    auto stmts = twoSideMapMMStmtRhs.getKeys(varName);
    // return true if the stmtNo is found in the list of stmtNo for the varName
    return std::find(stmts.begin(), stmts.end(), stmtNo) != stmts.end();
}
bool PatternAssignTable::hasRhsFromStmt(StmtNo stmtNo) {
    return twoSideMapMMStmtRhs.containsKey(stmtNo);
}
bool PatternAssignTable::hasRhs(VarName varName) {
    return twoSideMapMMStmtRhs.containsValue(varName);
}
std::vector<StmtNo> PatternAssignTable::getStmtsFromRhs(VarName varName) {
    return twoSideMapMMStmtRhs.getKeys(varName);
}
std::vector<VarName> PatternAssignTable::getRhsVarsFromStmt(StmtNo stmtNo) {
    return twoSideMapMMStmtRhs.getValues(stmtNo);
}
int PatternAssignTable::getSizeStmtRhs() const {
    return twoSideMapMMStmtRhs.size();
}


// -------- For VarName LHS | VarName RHS table
bool PatternAssignTable::addLhsRhs(VarName lhs, VarName rhs) {
    if (isLhsRhs(lhs, rhs)) {
        return false;
    }
    return twoSideMapMMLhsRhs.insert(lhs, rhs);
}
bool PatternAssignTable::isLhsRhs(VarName lhs, VarName rhs) {
    if (!twoSideMapMMLhsRhs.containsKey(lhs)
        || !twoSideMapMMLhsRhs.containsValue(rhs)) {
        return false;
    }
    auto rhss = twoSideMapMMLhsRhs.getValues(lhs);
    // return true if the rhs is found in the list of rhs for the lhs
    return std::find(rhss.begin(), rhss.end(), rhs) != rhss.end();
}
bool PatternAssignTable::hasLhsFromRhs(VarName rhs) {
    return twoSideMapMMLhsRhs.containsKey(rhs);
}
bool PatternAssignTable::hasRhsFromLhs(VarName lhs) {
    return twoSideMapMMLhsRhs.containsValue(lhs);
}
std::vector<VarName> PatternAssignTable::getLhsFromRhs(VarName rhs) {
    return twoSideMapMMLhsRhs.getKeys(rhs);
}
std::vector<VarName> PatternAssignTable::getRhsFromLhs(VarName lhs) {
    return twoSideMapMMLhsRhs.getValues(lhs);
}
int PatternAssignTable::getSizeLhsRhs() const {
    return twoSideMapMMLhsRhs.size();
}
// ai-gen end
