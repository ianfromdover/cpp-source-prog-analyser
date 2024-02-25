//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_FOLLOWSTTABLE_H
#define SPA_FOLLOWSTTABLE_H

#include "utilSpa/IntColumn.h"

class FollowsTTable  {
private:
    std::pair<IntColumn, IntColumn> table;
public:
    FollowsTTable() = default;

    bool addFollowsT(int followed, int follower);
    std::pair<IntColumn, IntColumn> getFollowsT();
};



#endif //SPA_FOLLOWSTTABLE_H
