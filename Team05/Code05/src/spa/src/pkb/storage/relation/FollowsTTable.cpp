//
// Created by yewme on 21/2/2024.
//

#include "FollowsTTable.h"

FollowsTTable::FollowsTTable() = default;
bool FollowsTTable::addFollowsT(StmtNo before, StmtNo after) {
    return map.insert(before, after);
}

std::vector<StmtNo> FollowsTTable::getStmtsBefore(StmtNo after) {
    return map.getKeys(after);
}

std::vector<StmtNo> FollowsTTable::getStmtsAfter(StmtNo before) {
    return map.getValues(before);
}

Table FollowsTTable::getAllAsStrings() {
    return map.getAllForAB();
}
