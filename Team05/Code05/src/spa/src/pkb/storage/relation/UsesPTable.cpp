#include "UsesPTable.h"

bool UsesPTable::addUsesP(ProcName proc, VarName name) {
    return map.insert(proc, name);
}

vector<VarName> UsesPTable::getVarFromProc(ProcName proc) {
    return map.getValues(proc);
}

vector<ProcName> UsesPTable::getProcFromVar(VarName name) {
    return map.getKeys(name);
}

Table UsesPTable::getAllProc() {
    return map.getAllForStrStr();
}
