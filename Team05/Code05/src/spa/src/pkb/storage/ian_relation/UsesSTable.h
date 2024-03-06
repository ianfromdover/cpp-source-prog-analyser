#pragma once
#define SPA_USESSTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class UsesSTable {
private:
    TwoSideMap<VarName, StmtNo> printMap; // note the VarName as the key instead
    TwoSideMap<ProcName, VarName> procNameMap; // note the Key is a ProcName
    TwoSideMap<StmtNo, VarName> asgnMap;
    TwoSideMap<StmtNo, VarName> callMap;
    TwoSideMap<StmtNo, VarName> ifWhileContainerMap;
public:
    UsesSTable() = default;

    /*
    // TODO: adapt to UsesPrint. one block for each map
    bool addFollows(StmtNo before, StmtNo after);
    StmtNo getStmtBefore(StmtNo after);
    StmtNo getFollower(StmtNo before);
     */

};
