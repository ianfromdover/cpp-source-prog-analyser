#include "ReadTable.h"

#include <utility>

ReadTable::ReadTable() = default;

bool ReadTable::addRead(StmtNo sNum, VarName name) {
    return twoSideMapOM.insert(sNum, name);
}
vector<StmtNo> ReadTable::getReadStmts(VarName name) {
    return twoSideMapOM.getKeys(std::move(name));
}
vector<VarName> ReadTable::getReadVar(StmtNo sNum) {
    return twoSideMapOM.getValues(sNum);
}
