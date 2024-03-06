//
// Created by yewme on 21/2/2024.
//

#include "FollowsTTable.h"

FollowsTTable::FollowsTTable() = default;
bool FollowsTTable::addFollowsT(StmtNo before, StmtNo after) {
    return twoSideMapMM.insert(before, after);
}

std::vector<StmtNo> FollowsTTable::getStmtsBefore(StmtNo after) {
    return twoSideMapMM.getKeys(after);
}

std::vector<StmtNo> FollowsTTable::getFollowersT(StmtNo before) {
    return twoSideMapMM.getValues(before);
}

