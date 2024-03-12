#pragma once
#define SPA_MODIFIESSTABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class ModifiesSTable {
private:
    TwoSideMap<StmtNo, VarName> stmtMap;
public:
    ModifiesSTable();

    // Adds a modifies relationship to the statement table, returns false if it already exists
    bool addModifiesS(StmtNo stmtNo, VarName varName);

    // Returns a list of statements that modifies the variable
    std::vector<StmtNo> getModifiersS(VarName varName);

    // Returns a list of modified variables
    std::vector<VarName> getModifiedS(StmtNo stmtNo);

    // Gets a table with 2 columns, StmtNo | VarName
    vector<vector<Str>> getAllAsStrings();
};