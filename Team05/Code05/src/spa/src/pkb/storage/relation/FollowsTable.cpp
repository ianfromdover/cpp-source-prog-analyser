#include "FollowsTable.h"

FollowsTable::FollowsTable() = default;
bool FollowsTable::addFollows(StmtNo before, StmtNo after) {
    return map.insert(before, after);
}

vector<StmtNo> FollowsTable::getStmtBefore(StmtNo after) {
    return map.getKeys(after);
}

vector<StmtNo> FollowsTable::getFollower(StmtNo before) {
    return map.getValues(before);
}

Table FollowsTable::getAllAsStrings() {
    return map.getAllForAB();
}
