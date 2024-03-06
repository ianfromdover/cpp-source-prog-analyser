//
// Created by yewme on 21/2/2024.
//


#pragma once
#define SPA_FOLLOWSTTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMapManyMany.hpp"


class FollowsTTable {
private:
    TwoSideMapManyMany<StmtNo, StmtNo> twoSideMapMM;
public:
    FollowsTTable();
    // Adds a follows relationship to the follows table, returns true if the relationship is added
    bool addFollowsT(StmtNo before, StmtNo after);
    // Returns the statements that are followedT by this statement
    std::vector<StmtNo> getStmtsBefore(StmtNo after);
    // Returns the followersT of this statement. Returns -1 if there is no follower
    std::vector<StmtNo> getFollowersT(StmtNo before);
};
