//
// Created by sjh_9 on 25/2/2024.
//

#include "ParentTTable.h"

bool ParentTTable::addParentT(int parent, int child) {
    table.first.addInt(parent);
    table.second.addInt(child);
    return true;
}

std::pair<IntColumn, IntColumn> ParentTTable::getParentT() {
    return table;
}