#pragma once
#define SPA_FOLLOWSTABLE_H

#include "utilSpa/SpaTypes.h"
#include "utilSpa/TwoSideMapOneOne.hpp"

class FollowsTable {
private:
    TwoSideMapOneOne<StmtNo, StmtNo> twoSideMap;
public:
    FollowsTable();
    // Adds a follows relationship to the follows table, returns true if the relationship is added
    bool addFollows(StmtNo before, StmtNo after);
    // Returns true if the before statement follows the after statement
    bool isFollows(StmtNo before, StmtNo after);
    // Returns true if there is a statement that is followed by this statement
    bool hasStmtBefore(StmtNo after);
    // Returns true if the statement has a follower
    bool hasFollower(StmtNo before);
    // Returns the statement that is followed by this statement
    StmtNo getStmtBefore(StmtNo after);
    // Returns the follower of this statement. Returns -1 if there is no follower
    StmtNo getFollower(StmtNo before);
    // Returns the number of follows relationships
    [[nodiscard]] int getSize() const;
};
