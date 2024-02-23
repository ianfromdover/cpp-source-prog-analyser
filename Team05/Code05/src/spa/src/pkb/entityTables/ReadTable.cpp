#include "ReadTable.h"

#include <utility>

ReadTable::ReadTable() = default;

bool ReadTable::addRead(StmtNo sNum, VarName name) {
    if (hasRead(sNum, name)) {
        return false;
    }
    return twoSideMapOM.insert(name, sNum);
}
bool ReadTable::hasRead(StmtNo sNum, VarName name) {
    if (!twoSideMapOM.containsKey(name)
        || !twoSideMapOM.containsValue(sNum)) {
        return false;
    }
    return twoSideMapOM.getKey(sNum).value() == name;
}
bool ReadTable::hasVar(VarName name) {
    return twoSideMapOM.containsKey(std::move(name));
}
bool ReadTable::hasStmt(StmtNo sNum) {
    return twoSideMapOM.containsValue(sNum);
}
vector<StmtNo> ReadTable::getReadStmts(VarName name) {
    return twoSideMapOM.getValues(std::move(name));
}
VarName ReadTable::getReadVar(StmtNo sNum) {
    auto k = twoSideMapOM.getKey(sNum);
    return (k.has_value()) ? k.value() : "";
}
int ReadTable::getSize() const {
    return twoSideMapOM.size();
}
