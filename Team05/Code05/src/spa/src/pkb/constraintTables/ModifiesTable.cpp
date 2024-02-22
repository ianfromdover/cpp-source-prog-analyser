//
// Created by yewme on 22/2/2024.
//

#include "ModifiesTable.h"

ModifiesTable::ModifiesTable() = default;
bool ModifiesTable::addModifiesS(StmtNo stmtNo, VarName varName) {
    if (isModifiesS(stmtNo, varName)) {
        return false;
    }
    return twoSideMapMMStmtNo.insert(stmtNo, varName);
}

bool ModifiesTable::isModifiesS(StmtNo stmtNo, VarName varName) {
    if (!twoSideMapMMStmtNo.containsKey(stmtNo)) {
        return false;  // The varName is not present in the map
    }

    // Check if 'stmtNo' is in the keys associated with 'varName'
    auto keys = twoSideMapMMStmtNo.getKeys(varName);
    if (keys.empty()) {
        return false;  // No keys associated with 'varName'
    }

    // Check if 'stmtNo' is present in the keys associated with 'varName'
    const std::vector<StmtNo>& keyValues = keys;
    return std::find(keyValues.begin(), keyValues.end(), stmtNo) != keyValues.end();
}

bool ModifiesTable::hasModifiersS(VarName varName) {
    return !twoSideMapMMStmtNo.getKeys(varName).empty();
}

bool ModifiesTable::hasModifiedS(StmtNo stmtNo) {
    return twoSideMapMMStmtNo.containsKey(stmtNo);
}

std::vector<StmtNo> ModifiesTable::getModifiersS(VarName varName) {
    auto k = twoSideMapMMStmtNo.getKeys(varName);
    if (k.empty()) {
        return {};
    }
    return k;
}

std::vector<VarName> ModifiesTable::getModifiedS(StmtNo stmtNo) {
    return twoSideMapMMStmtNo.getValues(stmtNo);
}

int ModifiesTable::getSizeS() const {
    return twoSideMapMMStmtNo.size();
}

// ProcName map

bool ModifiesTable::addModifiesP(ProcName procName, VarName varName) {
    if (isModifiesP(procName, varName)) {
        return false;
    }
    return twoSideMapMMProcName.insert(procName, varName);
}

bool ModifiesTable::isModifiesP(ProcName procName, VarName varName) {
    if (!twoSideMapMMProcName.containsKey(procName)) {
        return false;  // The varName is not present in the map
    }

    // Check if 'stmtNo' is in the keys associated with 'varName'
    auto keys = twoSideMapMMProcName.getKeys(varName);
    if (keys.empty()) {
        return false;  // No keys associated with 'varName'
    }

    // Check if 'stmtNo' is present in the keys associated with 'varName'
    const std::vector<ProcName>& keyValues = keys;
    return std::find(keyValues.begin(), keyValues.end(), procName) != keyValues.end();
}

bool ModifiesTable::hasModifiersP(VarName varName) {
    return !twoSideMapMMProcName.getKeys(varName).empty();
}

bool ModifiesTable::hasModifiedP(ProcName procName) {
    return twoSideMapMMProcName.containsKey(procName);
}

std::vector<ProcName> ModifiesTable::getModifiersP(VarName varName) {
    auto k = twoSideMapMMProcName.getKeys(varName);
    if (k.empty()) {
        return {};
    }
    return k;
}

vector<VarName> ModifiesTable::getModifiedP(ProcName procName) {
    return twoSideMapMMProcName.getValues(procName);
}

int ModifiesTable::getSizeP() const {
    return twoSideMapMMProcName.size();
}
