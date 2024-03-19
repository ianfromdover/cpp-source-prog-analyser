#include "WhileTable.h"

WhileTable::WhileTable() = default;

bool WhileTable::addWhile(StmtNo sNum, VarName var) {
    return map.insert(sNum, var);
}
vector<StmtNo> WhileTable::getWhileStmts(VarName var) {
    return map.getKeys(var);
}
vector<VarName> WhileTable::getWhileVars(StmtNo sNum) {
    return map.getValues(sNum);
}

Table WhileTable::getAllAsStrings() {
    return map.getAllForAStr();
}
