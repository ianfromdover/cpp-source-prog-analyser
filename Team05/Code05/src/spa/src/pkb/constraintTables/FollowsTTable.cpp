//
// Created by yewme on 21/2/2024.
//

#include "FollowsTTable.h"

FollowsTable::FollowsTable() = default;
bool FollowsTable::addFollows(StmtNo before, StmtNo after) {
    if (isFollows(before, after)) {
        return false;
    }
    return twoSideMap.insert(before, after);
}

bool FollowsTable::isFollows(StmtNo before, StmtNo after) {
    if (!twoSideMap.containsKey(before)
        || !twoSideMap.containsValue(after)) {
        return false;
    }
    return twoSideMap.getKey(after).value() == before;
}

bool FollowsTable::hasStmtBefore(StmtNo after) {
    return twoSideMap.getKey(after).has_value();
}

bool FollowsTable::hasFollower(StmtNo before) {
    return twoSideMap.containsKey(before);
}

StmtNo FollowsTable::getStmtBefore(StmtNo after) {
    auto k = twoSideMap.getKey(after);
    if (!k.has_value()) {
        return -1;
    }
    return k.value();
}

StmtNo FollowsTable::getFollower(StmtNo before) {
    auto v = twoSideMap.getValue(before);
    if (!v.has_value()) {
        return -1;
    }
    return v.value();
}

int FollowsTable::getSize() const {
    return twoSideMap.size();
}
