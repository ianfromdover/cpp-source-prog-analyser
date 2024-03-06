#pragma once
#define SPA_MODIFIESPTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class ModifiesPTable {
private:
    TwoSideMap<ProcName, VarName> procMap;
public:
    ModifiesPTable();

    // Adds a modifies relationship to the procedure table, returns false if it already exists
    bool addModifiesP(ProcName procName, VarName varName);
    // Returns a list of procedures that modifies the variable
    std::vector<ProcName> getModifiersP(VarName varName);
    // Returns a list of modified variables
    vector<VarName> getModifiedP(ProcName procName);
    // Gets a table with 2 columns, ProcName | VarName
    vector<vector<Str>> getAllP();
};
