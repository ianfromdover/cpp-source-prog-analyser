#pragma once
#define SPA_FOLLOWSTABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class FollowsTable {
private:
    TwoSideMap<StmtNo, StmtNo> map;
public:
    FollowsTable();
    // Adds a follows relationship to the follows table, returns true if the relationship is added
    bool addFollows(StmtNo before, StmtNo after);
    // Returns the statement that is followed by this statement
    vector<StmtNo> getStmtBefore(StmtNo after);
    // Returns the follower of this statement. Returns an empty list if there is no follower
    vector<StmtNo> getFollower(StmtNo before);
    // Gets a table with 2 columns, Before | After
    Table getAllAsStrings();
};
