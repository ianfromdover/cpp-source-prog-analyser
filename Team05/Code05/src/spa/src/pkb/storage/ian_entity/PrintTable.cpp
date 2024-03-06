#include "PrintTable.h"

#include <utility>

PrintTable::PrintTable() = default;

bool PrintTable::addPrint(StmtNo sNum, VarName name) {
    return twoSideMapOM.insert(name, sNum);
}
vector<StmtNo> PrintTable::getPrintStmts(VarName name) {
    return twoSideMapOM.getValues(std::move(name));
}
vector<VarName> PrintTable::getPrintVar(StmtNo sNum) {
    return twoSideMapOM.getKeys(sNum);
}
