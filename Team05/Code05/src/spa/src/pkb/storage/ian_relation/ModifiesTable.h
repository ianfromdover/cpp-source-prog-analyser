//
// Created by yewme on 22/2/2024.
//

#ifndef SPA_MODIFIESTABLE_H
#define SPA_MODIFIESTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMapManyMany.hpp"

class ModifiesTable {
private:
    TwoSideMapManyMany<StmtNo, VarName> twoSideMapMMStmtNo;
    //
    TwoSideMapManyMany<ProcName, VarName> twoSideMapMMProcName;
public:
    ModifiesTable();

    // For twoSideMapOMStmtNo
    bool addModifiesS(StmtNo stmtNo, VarName varName);
    bool isModifiesS(StmtNo stmtNo, VarName varName);
    // Returns true if the var has a modifier
    bool hasModifiersS(VarName varName);
    // Returns true if the var has a modified
    bool hasModifiedS(StmtNo stmtNo);
    std::vector<StmtNo> getModifiersS(VarName varName);
    // Returns a list of modified variables
    std::vector<VarName> getModifiedS(StmtNo stmtNo);
    int getSizeS() const;

    // For twoSideMapOMProcName
    bool addModifiesP(ProcName procName, VarName varName);
    bool isModifiesP(ProcName procName, VarName varName);
    // Returns true if the var has a modifier
    bool hasModifiersP(VarName varName);
    // Returns true if the var has a modified
    bool hasModifiedP(ProcName procName);
    std::vector<ProcName> getModifiersP(VarName varName);
    // Returns a list of modified variables
    vector<VarName> getModifiedP(ProcName procName);
    int getSizeP() const;
};


#endif //SPA_MODIFIESTABLE_H
