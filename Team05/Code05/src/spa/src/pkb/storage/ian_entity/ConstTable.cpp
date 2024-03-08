#include "ConstTable.h"

ConstTable::ConstTable() = default;

bool ConstTable::addConst(StmtNo sNum, ConstVal name) {
    return map.insert(name, sNum);
}
vector<StmtNo> ConstTable::getConstStmts(ConstVal name) {
    return map.getValues(name);
}
vector<ConstVal> ConstTable::getConsts(StmtNo sNum) {
    return map.getKeys(sNum);
}

vector<vector<Str>> ConstTable::getAllAsStrings() {
    return map.getAllForAB();
}
