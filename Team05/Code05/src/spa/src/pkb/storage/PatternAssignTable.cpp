#include "PatternAssignTable.h"

PatternAssignTable::PatternAssignTable() = default;

// TODO:
// do C++ substring match from QPS' string to stored SP string, chatGPT it

// ai-gen start (copilot, 2, e)
// prompt: used copilot
// -------- For StmtNo | VarName LHS table

bool PatternAssignTable::isAsgn(StmtNo sNum) {
    return stmtLhsMap.containsKey(sNum);
}

// Adds
bool PatternAssignTable::addStmtLhs(StmtNo stmtNo, VarName varName) {
    return stmtLhsMap.add(stmtNo, varName);
}
std::vector<StmtNo> PatternAssignTable::getStmtsFromLhs(VarName varName) {
    return stmtLhsMap.getRelatedKeys(varName);
}
// Gets values
std::vector<VarName> PatternAssignTable::getLhsVarsFromStmt(StmtNo stmtNo) {
    return stmtLhsMap.getRelatedValues(stmtNo);
}
Table PatternAssignTable::getAllStmtLhs() {
    return stmtLhsMap.getAll();
}

// -------- For StmtNo | VarName RHS table

bool PatternAssignTable::addStmtRhs(StmtNo stmtNo, VarName varName) {
    return stmtRhsMap.add(stmtNo, varName);
}
std::vector<StmtNo> PatternAssignTable::getStmtsFromRhs(VarName varName) {
    return stmtRhsMap.getRelatedKeys(varName);
}
std::vector<VarName> PatternAssignTable::getRhsVarsFromStmt(StmtNo stmtNo) {
    return stmtRhsMap.getRelatedValues(stmtNo);
}
Table PatternAssignTable::getAllStmtRhs() {
    return stmtRhsMap.getAll();
}

// -------- For VarName LHS | VarName RHS table
bool PatternAssignTable::addLhsRhs(VarName lhs, VarName rhs) {
    return lhsRhsMap.add(lhs, rhs);
}
std::vector<VarName> PatternAssignTable::getLhsFromRhs(VarName rhs) {
    return lhsRhsMap.getRelatedKeys(rhs);
}
std::vector<VarName> PatternAssignTable::getRhsFromLhs(VarName lhs) {
    return lhsRhsMap.getRelatedValues(lhs);
}
// ai-gen end
Table PatternAssignTable::getAllLhsRhs() {
    return lhsRhsMap.getAll();
}

// -------- For StmtNo | VarName LHS | VarName RHS table
Table PatternAssignTable::getAllAsStrings() {
    Table result = stmtLhsMap.getAll();
    for (auto& stmtLhsPair : result) {
        int stmtNo = std::stoi(stmtLhsPair[0]);
        string lhs = stmtLhsPair[1];
        // getting the only item in the returned vector<string> so [0] // TODO: temporary method for MS2
        string rhs = (stmtRhsMap.getRelatedValues(stmtNo)[0]);
        stmtLhsPair[1] = lhs + "=" + rhs;
    }
    return result;
}
