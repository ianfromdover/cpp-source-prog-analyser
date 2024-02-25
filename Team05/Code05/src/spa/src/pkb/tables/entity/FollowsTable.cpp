//
// Created by sjh_9 on 25/2/2024.
//

#include <iostream>
#include "FollowsTable.h"

bool FollowsTable::addFollows(int followed, int follower) {
    table.first.addInt(followed);
    table.second.addInt(follower);
    return true;
}

std::pair<IntColumn, IntColumn> FollowsTable::getFollows() {
    return table;
}
