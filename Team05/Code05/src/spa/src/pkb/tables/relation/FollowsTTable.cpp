//
// Created by sjh_9 on 25/2/2024.
//

#include <iostream>
#include "FollowsTTable.h"

bool FollowsTTable::addFollowsT(int followed, int follower) {
    table.first.addInt(followed);
    table.second.addInt(follower);
    return true;
}

std::pair<IntColumn, IntColumn> FollowsTTable::getFollowsT() {
    return table;
}
