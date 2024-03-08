#include <string>
#include "ProcedureTable.h"

ProcedureTable::ProcedureTable() = default;

bool ProcedureTable::contains(ProcName name) {
    return std::find(procList.begin(), procList.end(), name) != procList.end();
}

bool ProcedureTable::addProc(ProcName name) {
    if (contains(name)) {
        return false;
    }
    procList.push_back(name);
    return true;
}

vector<Str> ProcedureTable::getProcByName(ProcName name) {
    return contains(name) ? vector<Str>{} : vector<Str>{name};
}

vector<vector<Str>> ProcedureTable::getAllAsStrings() {
    vector<vector<Str>> stmts;
    for (auto name : procList) {
        stmts.push_back({name});
    }
    return stmts;
}
