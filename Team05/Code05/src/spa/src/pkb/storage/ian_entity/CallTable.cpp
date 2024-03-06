#include "CallTable.h"

#include <utility>

CallTable::CallTable() = default;

bool CallTable::addCall(StmtNo sNum, ProcName name) {
    return twoSideMapOM.insert(name, sNum);
}
vector<StmtNo> CallTable::getStmts(ProcName name) {
    return twoSideMapOM.getValues(std::move(name));
}
vector<ProcName> CallTable::getProc(StmtNo sNum) {
    return twoSideMapOM.getKeys(sNum);
}
