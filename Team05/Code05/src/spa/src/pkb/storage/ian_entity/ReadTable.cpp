#include "ReadTable.h"

#include <utility>

ReadTable::ReadTable() = default;

bool ReadTable::addRead(StmtNo sNum, VarName name) {
    return twoSideMapOM.insert(name, sNum);
}
vector<StmtNo> ReadTable::getReadStmts(VarName name) {
    return twoSideMapOM.getValues(std::move(name));
}
vector<VarName> ReadTable::getReadVar(StmtNo sNum) {
    return twoSideMapOM.getKeys(sNum);
}
