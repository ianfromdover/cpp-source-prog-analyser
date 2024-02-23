//
// Created by yewme on 22/2/2024.
//

#ifndef SPA_MODIFIESTABLE_H
#define SPA_MODIFIESTABLE_H

#include "utilSpa/SpaTypes.h"
#include "utilSpa/TwoSideMapManyMany.hpp"
#include "utilSpa/TwoSideMapOneMany.hpp"

class ModifiesTable {
private:
//    TwoSideMapOneMany<StmtNo, VarName> twoSideMapOMRead;
    TwoSideMapManyMany<StmtNo, VarName> readMap;
    TwoSideMapManyMany<StmtNo, VarName> assignMap;
    TwoSideMapManyMany<StmtNo, VarName> callMap;
    TwoSideMapManyMany<StmtNo, VarName> ifContainerMap;
    TwoSideMapManyMany<StmtNo, VarName> whileContainerMap;
    TwoSideMapManyMany<ProcName, VarName> procNameMap;
public:
    ModifiesTable();

    //TODO: modifiesS has 5 diff tables, but 4 are ManyMany with the same StmtNo, VarName so should take in a param in the args and deal accordingly
    //TODO: example getModifiedS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo stmtNo) etc

    //TODO: Updated: we will use ManyMany for all 5 so it is easier, since the types are the same

//    // For twoSideMapOMRead
//    bool addModifiesRe(StmtNo stmtNo, VarName varName);
//    bool isModifiesRe(StmtNo stmtNo, VarName varName);
//    // Returns true if the var has a modifier
//    bool hasModifiersRe(VarName varName);
//    // Returns true if the var has a modified
//    bool hasModifiedRe(StmtNo stmtNo);
//    std::vector<StmtNo> getModifiersRe(VarName varName);
//    // Returns a list of modified variables
//    std::vector<VarName> getModifiedRe(StmtNo stmtNo);
//    int getSizeRe() const;

    // For twoSideMapMM...
    bool addModifiesS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo stmtNo, VarName varName);
    bool isModifiesS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo stmtNo, VarName varName);
    // Returns true if the var has a modifier
    bool hasModifiersS(TwoSideMapManyMany<StmtNo, VarName> map, VarName varName);
    // Returns true if the var has a modified
    bool hasModifiedS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo stmtNo);
    std::vector<StmtNo> getModifiersS(TwoSideMapManyMany<StmtNo, VarName> map, VarName varName);
    // Returns a list of modified variables
    std::vector<VarName> getModifiedS(TwoSideMapManyMany<StmtNo, VarName> map, StmtNo stmtNo);
    int getSizeS(TwoSideMapManyMany<StmtNo, VarName> map) const;
    TwoSideMapManyMany<StmtNo, VarName> getReadMap();
    TwoSideMapManyMany<StmtNo, VarName> getAssignMap();
    TwoSideMapManyMany<StmtNo, VarName> getCallMap();
    TwoSideMapManyMany<StmtNo, VarName> getIfContainerMap();
    TwoSideMapManyMany<StmtNo, VarName> getWhileContainerMap();

    // For twoSideMapMMProcName
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
    TwoSideMapManyMany<ProcName, VarName> getProcNameMap();
};


#endif //SPA_MODIFIESTABLE_H
