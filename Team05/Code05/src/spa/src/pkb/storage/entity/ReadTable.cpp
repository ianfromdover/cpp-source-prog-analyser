#include "ReadTable.h"

ReadTable::ReadTable() = default;

bool ReadTable::addRead(StmtNo sNum, VarName name) {
    return map.insert(sNum, name);
}
vector<StmtNo> ReadTable::getReadStmts(VarName name) {
    return map.getKeys(std::move(name));
}
vector<VarName> ReadTable::getReadVar(StmtNo sNum) {
    return map.getValues(sNum);
}

Table ReadTable::getAllAsStrings() {
    return map.getAllForAStr();
}
