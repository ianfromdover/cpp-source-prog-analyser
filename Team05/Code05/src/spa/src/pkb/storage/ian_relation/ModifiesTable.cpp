//
// Created by yewme on 22/2/2024.
//

#include "ModifiesTable.h"

ModifiesTable::ModifiesTable() = default;
bool ModifiesTable::addModifiesS(StmtNo stmtNo, VarName varName) {
    return stmtMap.insert(stmtNo, varName);
}

std::vector<StmtNo> ModifiesTable::getModifiersS(VarName varName) {
    return stmtMap.getKeys(varName);
}

std::vector<VarName> ModifiesTable::getModifiedS(StmtNo stmtNo) {
    return stmtMap.getValues(stmtNo);
}

// ProcName map

bool ModifiesTable::addModifiesP(ProcName procName, VarName varName) {
    return procMap.insert(procName, varName);
}

std::vector<ProcName> ModifiesTable::getModifiersP(VarName varName) {
    return procMap.getKeys(varName);
}

vector<VarName> ModifiesTable::getModifiedP(ProcName procName) {
    return procMap.getValues(procName);
}

