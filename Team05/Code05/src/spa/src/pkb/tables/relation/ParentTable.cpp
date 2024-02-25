//
// Created by sjh_9 on 25/2/2024.
//

#include "ParentTable.h"

bool ParentTable::addParent(int parent, int child) {
    table.first.addInt(parent);
    table.second.addInt(child);
    return true;
}

std::pair<IntColumn, IntColumn> ParentTable::getParent() {
    return table;
}