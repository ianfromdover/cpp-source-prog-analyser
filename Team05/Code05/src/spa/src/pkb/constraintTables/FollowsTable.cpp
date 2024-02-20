//
// Created by yewme on 20/2/2024.
//

#include "FollowsTable.h"

FollowsTable::FollowsTable() {}
bool FollowsTable::addFollows(StmtNo before, StmtNo after) {
    if (isFollows(before, after)) {
        return false;
    }
    twoSideMap.insert(before, after);
    return true;
}

bool FollowsTable::isFollows(StmtNo before, StmtNo after) {
    if (twoSideMap.getKey(after) == std::nullopt) {
        return false;
    }
    return twoSideMap.getKey(after).value() == before;
}

bool FollowsTable::hasFollowed(StmtNo after) {
    return twoSideMap.getKey(after) != std::nullopt;
}

bool FollowsTable::hasFollower(StmtNo before) {
    return twoSideMap.containsKey(before);
}

StmtNo FollowsTable::getFollowed(StmtNo after) {
    if (twoSideMap.getKey(after) == std::nullopt) {
        return -1;
    }
    return twoSideMap.getKey(after).value();
}

vector<StmtNo> FollowsTable::getFollowers(StmtNo before) {
    return twoSideMap.getValues(before);
}

int FollowsTable::getSize() const {
    return twoSideMap.size();
}
