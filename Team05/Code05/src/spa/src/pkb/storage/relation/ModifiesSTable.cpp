//
// Created by yewme on 22/2/2024.
//

#include "ModifiesSTable.h"

ModifiesSTable::ModifiesSTable() = default;
bool ModifiesSTable::addModifiesS(StmtNo stmtNo, VarName varName) {
    return stmtMap.insert(stmtNo, varName);
}

std::vector<StmtNo> ModifiesSTable::getModifiersS(VarName varName) {
    return stmtMap.getKeys(varName);
}

std::vector<VarName> ModifiesSTable::getModifiedS(StmtNo stmtNo) {
    return stmtMap.getValues(stmtNo);
}

Table ModifiesSTable::getAllAsStrings() {
    return stmtMap.getAllForAStr();
}
