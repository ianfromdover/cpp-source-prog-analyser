#pragma once
#define SPA_USESSTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class UsesSTable {
private:
    TwoSideMap<ProcName, VarName> procNameMap; // note the Key is a ProcName
    TwoSideMap<StmtNo, VarName> printMap;
    TwoSideMap<StmtNo, VarName> asgnMap;
    TwoSideMap<StmtNo, VarName> callMap;
    TwoSideMap<StmtNo, VarName> ifWhileContainerMap;
public:
    UsesSTable() = default;

    bool addProc(ProcName proc, VarName name);
    vector<VarName> getVarFromProc(ProcName proc);
    vector<ProcName> getProcFromVar(VarName name);
    // Gets a table with 2 columns, ProcName | VarName
    std::vector<std::vector<Str>> getAllProc();

    bool addPrint(StmtNo sNum, VarName name);
    vector<VarName> getPrintedVar(StmtNo sNum);
    vector<StmtNo> getPrintStmtNo(VarName name);
    // Gets a table with 2 columns, StmtNo | VarName
    std::vector<std::vector<Str>> getAllPrint();

    // ai-gen start (copilot, 1, e)
    // prompt: used copilot
    // Add the groups of the same 3 methods for the other maps
    bool addAsgn(StmtNo sNum, VarName name);
    vector<VarName> getAsgnVar(StmtNo sNum);
    vector<StmtNo> getAsgnStmtNo(VarName name);
    // Gets a table with 2 columns, StmtNo | VarName
    std::vector<std::vector<Str>> getAllAsgn();

    bool addCall(StmtNo sNum, VarName name);
    vector<VarName> getCallVar(StmtNo sNum);
    vector<StmtNo> getCallStmtNo(VarName name);
    // Gets a table with 2 columns, StmtNo | VarName
    std::vector<std::vector<Str>> getAllCall();

    bool addIfWhileContainer(StmtNo sNum, VarName name);
    vector<VarName> getIfWhileContainerVar(StmtNo sNum);
    vector<StmtNo> getIfWhileContainerStmtNo(VarName name);
    // Gets a table with 2 columns, StmtNo | VarName
    std::vector<std::vector<Str>> getAllWhiles();
    // ai-gen end
};
