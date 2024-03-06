#include "IfTable.h"

IfTable::IfTable() = default;

bool IfTable::addIf(StmtNo sNum, VarName var) {
    return map.insert(sNum, std::move(var));
}
vector<StmtNo> IfTable::getIfStmts(VarName var) {
    return map.getKeys(std::move(var));
}
vector<VarName> IfTable::getIfVars(StmtNo sNum) {
    return map.getValues(sNum);
}

vector<vector<Str>> IfTable::getAllAsStrings() {
    return {};
    // return map.getAll(); // type not compatible?
}
