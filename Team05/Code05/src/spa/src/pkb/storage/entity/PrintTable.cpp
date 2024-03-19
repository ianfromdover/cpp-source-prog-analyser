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

Table PrintTable::getAllAsStrings() {
    return map.getAllForAStr();
}
