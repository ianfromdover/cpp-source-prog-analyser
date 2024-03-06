#pragma once
#define SPA_FOLLOWSTABLE_H

#include "utilSpa/SpaTypes.h"
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
    // Returns the follower of this statement. Returns -1 if there is no follower
    vector<StmtNo> getFollower(StmtNo before);
    // Gets a table with 2 columns, Before | After
    vector<vector<Str>> getAll();
};
