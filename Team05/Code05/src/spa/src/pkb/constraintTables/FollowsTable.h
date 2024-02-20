//
// Created by yewme on 20/2/2024.
//

#ifndef SPA_FOLLOWSTABLE_H
#define SPA_FOLLOWSTABLE_H

#include "utilSpa/SpaTypes.h"
#include "utilSpa/TwoSideFwdVecMap.h"

class FollowsTable {
    // TODO: Create Follows* table class using TwoSideDblVecMap
private:
    TwoSideFwdVecMap<StmtNo, StmtNo> twoSideMap;
public:
    FollowsTable();
    bool addFollows(StmtNo before, StmtNo after);
    bool isFollows(StmtNo before, StmtNo after);
    // Returns true if the statement has a followed
    bool hasFollowed(StmtNo after);
    // Returns true if the statement has a follower
    bool hasFollower(StmtNo before);
    StmtNo getFollowed(StmtNo after);
    // Returns a list of children of the parent, unsorted // TODO: QPS ppl, do you want it to be sorted?
    vector<StmtNo> getFollowers(StmtNo before);
    int getSize() const;
};


#endif //SPA_FOLLOWSTABLE_H
