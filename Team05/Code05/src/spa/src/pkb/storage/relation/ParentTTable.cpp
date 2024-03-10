//
// Created by yewme on 21/2/2024.
//

#include "ParentTTable.h"

ParentTTable::ParentTTable() = default;
bool ParentTTable::addParentT(StmtNo before, StmtNo after) {
    return map.insert(before, after);
}

std::vector<StmtNo> ParentTTable::getParentsT(StmtNo child) {
    return map.getKeys(child);
}

std::vector<StmtNo> ParentTTable::getChildrenT(StmtNo parent) {
    return map.getValues(parent);
}

vector<vector<Str>> ParentTTable::getAllAsStrings() {
    return map.getAllForAB();
}
