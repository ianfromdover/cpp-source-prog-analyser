#pragma once
#define SPA_USESSTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class UsesSTable {
private:
    TwoSideMap<StmtNo, VarName> printMap;
    TwoSideMap<ProcName, VarName> procNameMap; // note the Key is a ProcName
    TwoSideMap<StmtNo, VarName> asgnMap;
    TwoSideMap<StmtNo, VarName> callMap;
    TwoSideMap<StmtNo, VarName> ifWhileContainerMap;
public:
    UsesSTable() = default;

    bool addPrint(StmtNo sNum, VarName name);
    vector<VarName> getPrintedVar(StmtNo sNum);
    vector<StmtNo> getPrintStmtNo(VarName name);

    bool addProc(ProcName proc, VarName name);
    vector<VarName> getVarFromProc(ProcName proc);
    vector<ProcName> getProcFromVar(VarName name);

    // ai-gen start (copilot, 0, e)
    // prompt: used copilot
    // Add the groups of the same 3 methods for the other maps
    bool addAsgn(StmtNo sNum, VarName name);
    vector<VarName> getAsgnVar(StmtNo sNum);
    vector<StmtNo> getAsgnStmtNo(VarName name);

    bool addCall(StmtNo sNum, VarName name);
    vector<VarName> getCallVar(StmtNo sNum);
    vector<StmtNo> getCallStmtNo(VarName name);

    bool addIfWhileContainer(StmtNo sNum, VarName name);
    vector<VarName> getIfWhileContainerVar(StmtNo sNum);
    vector<StmtNo> getIfWhileContainerStmtNo(VarName name);
    // ai-gen end
};
