#include "CallTable.h"

#include <utility>

CallTable::CallTable() = default;

bool CallTable::addCall(StmtNo sNum, VarName name) {
    if (hasCall(sNum, name)) {
        return false;
    }
    return twoSideMapOM.insert(name, sNum);
}
bool CallTable::hasCall(StmtNo sNum, VarName name) {
    if (!twoSideMapOM.containsKey(name)
        || !twoSideMapOM.containsValue(sNum)) {
        return false;
    }
    return twoSideMapOM.getKey(sNum).value() == name;
}
bool CallTable::hasVar(VarName name) {
    return twoSideMapOM.containsKey(std::move(name));
}
bool CallTable::hasStmt(StmtNo sNum) {
    return twoSideMapOM.containsValue(sNum);
}
vector<StmtNo> CallTable::getCallStmts(VarName name) {
    return twoSideMapOM.getValues(std::move(name));
}
VarName CallTable::getCallVar(StmtNo sNum) {
    auto k = twoSideMapOM.getKey(sNum);
    return (k.has_value()) ? k.value() : "";
}
int CallTable::getSize() const {
    return twoSideMapOM.size();
}
