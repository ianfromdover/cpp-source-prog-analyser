#pragma once
#define SPA_USESTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMapOneMany.hpp"
#include "pkb/storage/base/TwoSideMapManyMany.hpp"

class UsesTable {
private:
    TwoSideMapOneMany<VarName, StmtNo> printMap; // note the One-Many r/ship and VarName as the key instead
    TwoSideMapManyMany<ProcName, VarName> procNameMap; // note the Key is a ProcName
    TwoSideMapManyMany<StmtNo, VarName> asgnMap;
    TwoSideMapManyMany<StmtNo, VarName> callMap;
    TwoSideMapManyMany<StmtNo, VarName> ifWhileContainerMap;
public:
    UsesTable() = default;

    /*
    // TODO: adapt to UsesPrint. one block for each map
    bool addFollows(StmtNo before, StmtNo after);
    bool isFollows(StmtNo before, StmtNo after);
    bool hasStmtBefore(StmtNo after);
    bool hasFollower(StmtNo before);
    StmtNo getStmtBefore(StmtNo after);
    StmtNo getFollower(StmtNo before);
    [[nodiscard]] int getSize() const;
     */

};
