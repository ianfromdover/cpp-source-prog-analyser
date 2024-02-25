//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_FOLLOWSTABLE_H
#define SPA_FOLLOWSTABLE_H

#include "utilSpa/IntColumn.h"

class FollowsTable  {
private:
    std::pair<IntColumn, IntColumn> table;
public:
    FollowsTable() = default;

    bool addFollows(int followed, int follower);
    std::pair<IntColumn, IntColumn> getFollows();
};



#endif //SPA_FOLLOWSTABLE_H
