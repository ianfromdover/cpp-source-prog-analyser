#include "VarTable.h"

VarTable::VarTable() = default;

bool VarTable::addVar(StmtNo sNum, VarName name) {
    return map.insert(sNum, name);
}
vector<VarName> VarTable::getVarByName(VarName name) {
    // find the name of the variable in the vector
    // TODO: implement in TwoSideMap after verifying with QPS that they need this functionality
    return {};
}
vector<StmtNo> VarTable::getVarStmts(VarName name) {
    return map.getKeys(name);
}
vector<VarName> VarTable::getVarNameByStmt(StmtNo sNum) {
    return map.getValues(sNum);
}

vector<vector<Str>> VarTable::getAllAsStrings() {
    return map.getAllForAStr();
}
