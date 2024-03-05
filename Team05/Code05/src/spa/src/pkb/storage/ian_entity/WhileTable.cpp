#include "WhileTable.h"

#include <utility>

WhileTable::WhileTable() = default;

bool WhileTable::addWhile(StmtNo sNum, VarName var) {
    if (hasWhileAtStmt(sNum, var)) {
        return false;
    }
    return twoSideMapMM.insert(sNum, var);
}
bool WhileTable::hasWhileAtStmt(StmtNo sNum, VarName var) {
    if (!twoSideMapMM.containsKey(sNum)
        || !twoSideMapMM.containsKey(sNum)) {
        return false;
    }
    // find var in the vector
    auto vars = twoSideMapMM.getValues(sNum);
    return std::find(vars.begin(), vars.end(), var) != vars.end();
}
bool WhileTable::hasWhile(VarName var) {
    return twoSideMapMM.containsValue(var);
}
bool WhileTable::hasStmt(StmtNo sNum) {
    return twoSideMapMM.containsKey(sNum);
}
vector<StmtNo> WhileTable::getWhileStmts(VarName var) {
    return twoSideMapMM.getKeys(var);
}
vector<VarName> WhileTable::getWhiles(StmtNo sNum) {
    return twoSideMapMM.getValues(sNum);
}
int WhileTable::getSize() const {
    return twoSideMapMM.size();
}
