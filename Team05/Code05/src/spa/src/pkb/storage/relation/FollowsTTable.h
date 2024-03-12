//
// Created by yewme on 21/2/2024.
//


#pragma once
#define SPA_FOLLOWSTTABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"


class FollowsTTable {
private:
    TwoSideMap<StmtNo, StmtNo> map;
public:
    FollowsTTable();
    // Adds a follows relationship to the follows table, returns true if the relationship is added
    bool addFollowsT(StmtNo before, StmtNo after);
    // Returns the statements that are followedT by this statement
    std::vector<StmtNo> getStmtsBefore(StmtNo after);
    // Returns the followersT of this statement. Returns empty vector if there is no follower
    std::vector<StmtNo> getStmtsAfter(StmtNo before);
    // Gets a table with 2 columns, Before* | After*
    vector<vector<Str>> getAllAsStrings();
};
