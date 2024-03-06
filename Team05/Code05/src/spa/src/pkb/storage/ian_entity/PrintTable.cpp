#include "PrintTable.h"

PrintTable::PrintTable() = default;

bool PrintTable::addPrint(StmtNo sNum, VarName name) {
    return map.insert(sNum, std::move(name));
}
vector<StmtNo> PrintTable::getPrintStmts(VarName name) {
    return map.getKeys(std::move(name));
}
vector<VarName> PrintTable::getPrintVar(StmtNo sNum) {
    return map.getValues(sNum);
}

vector<vector<Str>> PrintTable::getAllAsStrings() {
    return {};
    // return map.getAll(); // type not compatible?
}
