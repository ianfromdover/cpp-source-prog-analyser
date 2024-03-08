#include <string>
#include "ProcedureTable.h"

ProcedureTable::ProcedureTable() = default;

bool ProcedureTable::addProc(ProcName name) {
    if (std::find(procList.begin(), procList.end(), name) != procList.end()) {
        return false;
    }
    procList.push_back(name);
    return true;
}
vector<vector<Str>> ProcedureTable::getAllAsStrings() {
    vector<vector<Str>> stmts;
    for (auto name : procList) {
        stmts.push_back({name});
    }
    return stmts;
}
