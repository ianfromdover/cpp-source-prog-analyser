//
// Created by yewme on 22/2/2024.
//

#ifndef SPA_MODIFIESTABLE_H
#define SPA_MODIFIESTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

/**
 * TODO: Should split this up into 2 tables
 */
class ModifiesTable {
private:
    TwoSideMap<StmtNo, VarName> stmtMap;
    TwoSideMap<ProcName, VarName> procMap;
public:
    ModifiesTable();

    // Adds a modifies relationship to the statement table, returns false if it already exists
    bool addModifiesS(StmtNo stmtNo, VarName varName);
    // Returns a list of statements that modifies the variable
    std::vector<StmtNo> getModifiersS(VarName varName);
    // Returns a list of modified variables
    std::vector<VarName> getModifiedS(StmtNo stmtNo);
    // Gets a table with 2 columns, StmtNo | VarName
    vector<vector<Str>> getAllS();

    // Adds a modifies relationship to the procedure table, returns false if it already exists
    bool addModifiesP(ProcName procName, VarName varName);
    // Returns a list of procedures that modifies the variable
    std::vector<ProcName> getModifiersP(VarName varName);
    // Returns a list of modified variables
    vector<VarName> getModifiedP(ProcName procName);
    // Gets a table with 2 columns, ProcName | VarName
    vector<vector<Str>> getAllP();
};


#endif //SPA_MODIFIESTABLE_H
