#include "CallTable.h"

CallTable::CallTable() = default;

bool CallTable::addCall(StmtNo sNum, ProcName name) {
    return map.insert(sNum, std::move(name));
}
vector<StmtNo> CallTable::getStmts(ProcName name) {
    return map.getKeys(std::move(name));
}
vector<ProcName> CallTable::getProc(StmtNo sNum) {
    return map.getValues(sNum);
}
Table CallTable::getAllAsStrings() {
    return map.getAllForAStr();
}
