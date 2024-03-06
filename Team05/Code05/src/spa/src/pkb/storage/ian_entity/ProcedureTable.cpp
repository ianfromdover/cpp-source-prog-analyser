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
vector<ProcName> ProcedureTable::getAllProcs() {
    vector<ProcName> copy = procList;
    return copy;
}
vector<Str> ProcedureTable::getAllAsStrings() {
    return getAllProcs();
}
