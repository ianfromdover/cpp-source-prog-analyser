//
// Created by yewme on 23/2/2024.
//


#pragma once
#define SPA_USESTABLE_H

#include "utilSpa/SpaTypes.h"
#include "utilSpa/TwoSideMapOneMany.hpp"
#include "utilSpa/TwoSideMapManyMany.hpp"

class UsesTable {
private:
    TwoSideMapOneMany<VarName, StmtNo> printMap; // note the One-Many r/ship and VarName as the key instead
    TwoSideMapManyMany<ProcName, VarName> procNameMap; // note the Key is a ProcName
    TwoSideMapManyMany<StmtNo, VarName> assignMap;
    TwoSideMapManyMany<StmtNo, VarName> callMap;
    TwoSideMapManyMany<StmtNo, VarName> ifContainerMap;
    TwoSideMapManyMany<StmtNo, VarName> whileContainerMap;

public:
    UsesTable() = default;

    // For OM<VarName, StmtNo> printMap
    bool addUsesPrint(VarName used, StmtNo user);
    bool isUsesPrint(VarName used, StmtNo user);
    // Returns true if the statement has a parent
    bool hasUsedPrint(StmtNo user);
    // Returns true if the statement has a child
    bool hasUserPrint(VarName used);
    VarName getUsedPrint(StmtNo user);
    // Returns a list of children of the parent, unsorted
    vector<StmtNo> getUserPrint(VarName used);
    int getSizePrint() const;

    // For twoSideMapMM<StmtNo, VarName>
    bool addUsesS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user, VarName used);
    bool isUsesS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user, VarName used);
    // Returns true if the var has a modifier
    bool hasUsersS(TwoSideMapManyMany<StmtNo, VarName> map, VarName used);
    // Returns true if the var has a modified
    bool hasUsedS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user);
    std::vector<StmtNo> getUsersS(TwoSideMapManyMany<StmtNo, VarName> map, VarName used);
    // Returns a list of modified variables
    std::vector<VarName> getUsedS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user);
    int getSizeS(TwoSideMapManyMany<StmtNo, VarName> map) const;

    // For twoSideMapMM<ProcName, VarName>
    bool addUsesP(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user, VarName used);
    bool isUsesP(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user, VarName used);
    // Returns true if the var has a modifier
    bool hasUsersP(TwoSideMapManyMany<StmtNo, VarName> map, VarName used);
    // Returns true if the var has a modified
    bool hasUsedP(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user);
    std::vector<StmtNo> getUsersP(TwoSideMapManyMany<StmtNo, VarName> map, VarName used);
    // Returns a list of modified variables
    std::vector<VarName> getUsedP(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo user);
    int getSizeP(TwoSideMapManyMany<StmtNo, VarName> map) const;

};
