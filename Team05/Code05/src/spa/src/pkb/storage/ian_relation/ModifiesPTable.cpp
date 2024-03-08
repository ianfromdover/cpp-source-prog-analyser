#include "ModifiesPTable.h"

ModifiesPTable::ModifiesPTable() = default;

bool ModifiesPTable::addModifiesP(ProcName procName, VarName varName) {
    return procMap.insert(procName, varName);
}

std::vector<ProcName> ModifiesPTable::getModifiersP(VarName varName) {
    return procMap.getKeys(varName);
}

vector<VarName> ModifiesPTable::getModifiedP(ProcName procName) {
    return procMap.getValues(procName);
}

vector<vector<Str>> ModifiesPTable::getAllAsStrings() {
    return procMap.getAllForStrStr();
}
