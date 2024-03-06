#include "CallTable.h"

CallTable::CallTable() = default;

bool CallTable::addCall(StmtNo sNum, ProcName name) {
    return map.insert(std::move(name), sNum);
}
vector<StmtNo> CallTable::getStmts(ProcName name) {
    return map.getValues(std::move(name));
}
vector<ProcName> CallTable::getProc(StmtNo sNum) {
    return map.getKeys(sNum);
}
vector<vector<Str>> CallTable::getAllAsStrings() {
    return {};
    // return map.getAll(); // isit no ProcName to string?
}
