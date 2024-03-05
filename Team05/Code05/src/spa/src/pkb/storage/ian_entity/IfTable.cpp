#include "IfTable.h"

#include <utility>

IfTable::IfTable() = default;

bool IfTable::addIf(StmtNo sNum, VarName var) {
    if (hasIfAtStmt(sNum, var)) {
        return false;
    }
    return twoSideMapMM.insert(sNum, var);
}
bool IfTable::hasIfAtStmt(StmtNo sNum, VarName var) {
    if (!twoSideMapMM.containsKey(sNum)
        || !twoSideMapMM.containsKey(sNum)) {
        return false;
    }
    // find var in the vector
    auto vars = twoSideMapMM.getValues(sNum);
    return std::find(vars.begin(), vars.end(), var) != vars.end();
}
bool IfTable::hasIf(VarName var) {
    return twoSideMapMM.containsValue(var);
}
bool IfTable::hasStmt(StmtNo sNum) {
    return twoSideMapMM.containsKey(sNum);
}
vector<StmtNo> IfTable::getIfStmts(VarName var) {
    return twoSideMapMM.getKeys(var);
}
vector<VarName> IfTable::getIfs(StmtNo sNum) {
    return twoSideMapMM.getValues(sNum);
}
int IfTable::getSize() const {
    return twoSideMapMM.size();
}
