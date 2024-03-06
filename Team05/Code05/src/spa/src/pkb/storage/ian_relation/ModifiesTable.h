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

    bool addModifiesS(StmtNo stmtNo, VarName varName);
    std::vector<StmtNo> getModifiersS(VarName varName);
    // Returns a list of modified variables
    std::vector<VarName> getModifiedS(StmtNo stmtNo);

    bool addModifiesP(ProcName procName, VarName varName);
    std::vector<ProcName> getModifiersP(VarName varName);
    // Returns a list of modified variables
    vector<VarName> getModifiedP(ProcName procName);
};


#endif //SPA_MODIFIESTABLE_H
