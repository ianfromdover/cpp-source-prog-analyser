#include "VarTable.h"

VarTable::VarTable() = default;

bool VarTable::addVar(StmtNo sNum, VarName name) {
    return map.insert(sNum, name);
}
vector<StmtNo> VarTable::getVarStmts(VarName name) {
    return map.getKeys(name);
}
vector<VarName> VarTable::getVarNameByStmt(StmtNo sNum) {
    return map.getValues(sNum);
}

Table VarTable::getVars() {
    return map.getSecondColStr();
}

Table VarTable::getAllAsStrings() {
    return map.getAllForAStr();
}
