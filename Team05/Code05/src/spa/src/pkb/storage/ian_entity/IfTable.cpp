#include "IfTable.h"

IfTable::IfTable() = default;

bool IfTable::addIf(StmtNo sNum, VarName var) {
    return twoSideMapMM.insert(sNum, var);
}
vector<StmtNo> IfTable::getIfStmts(VarName var) {
    return twoSideMapMM.getKeys(var);
}
vector<VarName> IfTable::getIfVars(StmtNo sNum) {
    return twoSideMapMM.getValues(sNum);
}

vector<vector<Str>> IfTable::getAllAsStrings() {
    return {};
    // return map.getAll(); // type not compatible?
}
