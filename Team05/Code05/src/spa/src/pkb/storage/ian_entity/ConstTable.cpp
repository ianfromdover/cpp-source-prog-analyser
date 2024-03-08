#include "ConstTable.h"

ConstTable::ConstTable() = default;

bool ConstTable::addConst(StmtNo sNum, ConstVal value) {
    return map.insert(sNum, value);
}
vector<StmtNo> ConstTable::getConstStmts(ConstVal value) {
    return map.getKeys(value);
}
vector<ConstVal> ConstTable::getConsts(StmtNo sNum) {
    return map.getValues(sNum);
}

vector<vector<Str>> ConstTable::getAllAsStrings() {
    return map.getAllForAB();
}
