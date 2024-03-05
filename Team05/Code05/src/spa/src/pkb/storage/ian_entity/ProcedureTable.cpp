#include "ProcedureTable.h"

#include <utility>

ProcedureTable::ProcedureTable() = default;

bool ProcedureTable::addProc(ProcName name) {
    if (hasProc(name)) {
        return false;
    }
    procList.push_back(name);
    return true;
}
bool ProcedureTable::hasProc(ProcName name) {
    return std::find(procList.begin(), procList.end(), name) != procList.end();
}
vector<ProcName> ProcedureTable::getAllProcs() {
    vector<ProcName> copy = procList;
    return copy;
}
int ProcedureTable::getSize() const {
    return procList.size();
}
