#include "PrintTable.h"

#include <utility>

PrintTable::PrintTable() = default;

bool PrintTable::addPrint(StmtNo sNum, VarName name) {
    return twoSideMapOM.insert(sNum, name);
}
vector<StmtNo> PrintTable::getPrintStmts(VarName name) {
    return twoSideMapOM.getKeys(std::move(name));
}
vector<VarName> PrintTable::getPrintVar(StmtNo sNum) {
    return twoSideMapOM.getValues(sNum);
}
