#include "FollowsTable.h"

FollowsTable::FollowsTable() = default;
bool FollowsTable::addFollows(StmtNo before, StmtNo after) {
    return twoSideMap.insert(before, after);
}

vector<StmtNo> FollowsTable::getStmtBefore(StmtNo after) {
    return twoSideMap.getKeys(after);
}

vector<StmtNo> FollowsTable::getFollower(StmtNo before) {
    return twoSideMap.getValues(before);
}

vector<vector<Str>> FollowsTable::getAll() {
    return twoSideMap.getAll();
}
