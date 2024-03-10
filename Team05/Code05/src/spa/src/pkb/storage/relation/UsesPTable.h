#pragma once
#define SPA_USESPTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class UsesPTable {
private:
    TwoSideMap<ProcName, VarName> map; // note the Key is a ProcName
public:
    UsesPTable() = default;

    bool addUsesP(ProcName proc, VarName name);
    vector<VarName> getVarFromProc(ProcName proc);
    vector<ProcName> getProcFromVar(VarName name);
    // Gets a table with 2 columns, ProcName | VarName
    std::vector<std::vector<Str>> getAllProc();
};
