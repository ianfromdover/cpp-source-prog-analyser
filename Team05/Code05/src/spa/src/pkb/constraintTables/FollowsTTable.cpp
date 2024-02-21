//
// Created by yewme on 21/2/2024.
//

#include "FollowsTTable.h"

FollowsTTable::FollowsTTable() = default;
bool FollowsTTable::addFollowsT(StmtNo before, StmtNo after) {
    if (isFollowsT(before, after)) {
        return false;
    }
    return twoSideMapMM.insert(before, after);
}

//bool FollowsTTable::isFollowsT(StmtNo before, StmtNo after) {
//    if (!twoSideMapMM.containsKey(before)
//        || !twoSideMapMM.containsValue(after)) {
//        return false;
//    }
//    return twoSideMapMM.getKeys(after).value() == before;
//}

bool FollowsTTable::isFollowsT(StmtNo before, StmtNo after) {
    if (!twoSideMapMM.containsKey(after)) {
        return false;  // The 'after' statement is not present in the map
    }

    // Check if 'before' is in the keys associated with 'after'
    auto keys = twoSideMapMM.getKeys(after);
    if (keys.empty()) {
        return false;  // No keys associated with 'after'
    }

    // Check if 'before' is present in the keys associated with 'after'
    const std::vector<StmtNo>& keyValues = keys;
    return std::find(keyValues.begin(), keyValues.end(), before) != keyValues.end();
}

//bool FollowsTTable::hasStmtBefore(StmtNo after) {
//    return twoSideMapMM.getKeys(after).has_value();
//}

bool FollowsTTable::hasStmtBefore(StmtNo after) {
    auto keys = twoSideMapMM.getKeys(after);
    return !keys.empty();
}

bool FollowsTTable::hasFollowersT(StmtNo before) {
    return twoSideMapMM.containsKey(before);
}

std::vector<StmtNo> FollowsTTable::getStmtsBefore(StmtNo after) {
    auto k = twoSideMapMM.getKeys(after);
    if (k.empty()) {
        return {-1};
    }
    return k;
}

std::vector<StmtNo> FollowsTTable::getFollowersT(StmtNo before) {
    auto v = twoSideMapMM.getValues(before);
    if (v.empty()) {
        return {-1};
    }
    return v;
}

int FollowsTTable::getSize() const {
    return twoSideMapMM.size();
}
