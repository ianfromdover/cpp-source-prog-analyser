#include "UsesPTable.h"

bool UsesSTable::addProc(ProcName proc, VarName name) {
    return map.insert(proc, name);
}

vector<VarName> UsesSTable::getVarFromProc(ProcName proc) {
    return map.getValues(proc);
}

vector<ProcName> UsesSTable::getProcFromVar(VarName name) {
    return map.getKeys(name);
}

std::vector<std::vector<Str>> UsesSTable::getAllProc() {
    return map.getAllForStrStr();
}
