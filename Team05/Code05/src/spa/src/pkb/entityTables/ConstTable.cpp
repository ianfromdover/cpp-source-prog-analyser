#include "ConstTable.h"

#include <utility>

ConstTable::ConstTable() = default;

bool ConstTable::addConst(StmtNo sNum, ConstVal name) {
    if (hasConstAtStmt(sNum, name)) {
        return false;
    }
    return twoSideMapMM.insert(name, sNum);
}
bool ConstTable::hasConstAtStmt(StmtNo sNum, ConstVal name) {
    if (!twoSideMapMM.containsKey(name)
        || !twoSideMapMM.containsValue(sNum)) {
        return false;
    }
    // find name in the vector
    auto names = twoSideMapMM.getKeys(sNum);
    return std::find(names.begin(), names.end(), name) != names.end();
}
bool ConstTable::hasConst(ConstVal name) {
    return twoSideMapMM.containsKey(name);
}
bool ConstTable::hasStmt(StmtNo sNum) {
    return twoSideMapMM.containsValue(sNum);
}
vector<StmtNo> ConstTable::getConstStmts(ConstVal name) {
    return twoSideMapMM.getValues(name);
}
vector<ConstVal> ConstTable::getConsts(StmtNo sNum) {
    return twoSideMapMM.getKeys(sNum);
}
int ConstTable::getSize() const {
    return twoSideMapMM.size();
}
