#include "PatternAssignTable.h"

PatternAssignTable::PatternAssignTable() = default;

// TODO:
// do C++ substring match from QPS' string to stored SP string, chatGPT it

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
Table PatternAssignTable::getAllStmtLhs() {
    return stmtLhsMap.getAllForAStr();
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
Table PatternAssignTable::getAllStmtRhs() {
    return stmtRhsMap.getAllForAStr();
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
Table PatternAssignTable::getAllLhsRhs() {
    return lhsRhsMap.getAllForStrStr();
}

// -------- For StmtNo | VarName LHS | VarName RHS table
Table PatternAssignTable::getAllAsStrings() {
    Table result = stmtLhsMap.getAllForAStr();
    for (auto& stmtLhsPair : result) {
        int stmtNo = std::stoi(stmtLhsPair[0]);
        string lhs = stmtLhsPair[1];
        // getting the only item in the returned vector<string> so [0] // TODO: temporary method for MS2
        string rhs = (stmtRhsMap.getValues(stmtNo)[0]);
        stmtLhsPair[1] = lhs + "=" + rhs;
    }
    return result;

    // after-MS2 version: makes 3 columns
    /*
    Table result = stmtLhsMap.getAllForAStr();
    for (auto& stmtLhsPair : result) {
        int stmtNo = std::stoi(stmtLhsPair[0]);
        string rhs = (stmtRhsMap.getValues(stmtNo)[0]); // in stmtRhsMap, a stmtNo only has 1 RHS, so i can use [0]
        stmtLhsPair.push_back(std::move(rhs));
    }
    return result;
     */
}
