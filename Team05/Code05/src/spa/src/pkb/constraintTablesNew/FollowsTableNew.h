//
// Created by yewme on 25/2/2024.
//

#ifndef FOLLOWS_TABLE_NEW_HPP
#define FOLLOWS_TABLE_NEW_HPP

#include "utilSpa/SpaTypes.h"
#include "utilSpa/Column.h"

class FollowsTableNew {
public:
    // Constructor
    FollowsTableNew() = default;

    std::pair<Column < StmtNo>, Column <StmtNo>> table;

    // Function to add a constant value for a statement number
    bool addFollows(StmtNo followed, StmtNo follower) {
        table.first.addElement(followed);
        table.second.addElement(follower);
        return true;
    }
};

#endif // FOLLOWS_TABLE_NEW_HPP