//
// Created by yewme on 21/2/2024.
//

#ifndef SPA_FOLLOWSTTABLE_H
#define SPA_FOLLOWSTTABLE_H

#pragma once
#define SPA_FOLLOWSTABLE_H

#include "utilSpa/SpaTypes.h"
#include "utilSpa/TwoSideMapManyMany.hpp"


class FollowsTTable {
private:
    TwoSideMapManyMany<StmtNo, StmtNo> twoSideMapMM;
public:
    FollowsTTable();
    // Adds a follows relationship to the follows table, returns true if the relationship is added
    bool addFollowsT(StmtNo before, StmtNo after);
    // Returns true if the before statement follows the after statement
    bool isFollowsT(StmtNo before, StmtNo after);
    // Returns true if there is a statement that is followed by this statement
    bool hasStmtBefore(StmtNo after);
    // Returns true if the statement has a follower
    bool hasFollowersT(StmtNo before);
    // Returns the statements that are followedT by this statement
    std::vector<StmtNo> getStmtsBefore(StmtNo after);
    // Returns the followersT of this statement. Returns -1 if there is no follower
    std::vector<StmtNo> getFollowersT(StmtNo before);
    // Returns the number of follows relationships
    [[nodiscard]] int getSize() const;
};


#endif //SPA_FOLLOWSTTABLE_H
