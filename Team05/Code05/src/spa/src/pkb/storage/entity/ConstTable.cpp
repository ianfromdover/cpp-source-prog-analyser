#include "ConstTable.h"
#include <algorithm>

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

Table ConstTable::getConsts() {
    return map.getSecondColB();
}

Table ConstTable::getAllAsStrings() {
    return map.getAllForAB();
}
