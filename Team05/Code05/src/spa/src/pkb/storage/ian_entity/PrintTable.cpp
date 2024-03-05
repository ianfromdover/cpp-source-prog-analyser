#include "PrintTable.h"

#include <utility>

PrintTable::PrintTable() = default;

bool PrintTable::addPrint(StmtNo sNum, VarName name) {
    if (hasPrint(sNum, name)) {
        return false;
    }
    return twoSideMapOM.insert(name, sNum);
}
bool PrintTable::hasPrint(StmtNo sNum, VarName name) {
    if (!twoSideMapOM.containsKey(name)
        || !twoSideMapOM.containsValue(sNum)) {
        return false;
    }
    return twoSideMapOM.getKey(sNum).value() == name;
}
bool PrintTable::hasVar(VarName name) {
    return twoSideMapOM.containsKey(std::move(name));
}
bool PrintTable::hasStmt(StmtNo sNum) {
    return twoSideMapOM.containsValue(sNum);
}
vector<StmtNo> PrintTable::getPrintStmts(VarName name) {
    return twoSideMapOM.getValues(std::move(name));
}
VarName PrintTable::getPrintVar(StmtNo sNum) {
    auto k = twoSideMapOM.getKey(sNum);
    return (k.has_value()) ? k.value() : "";
}
int PrintTable::getSize() const {
    return twoSideMapOM.size();
}
