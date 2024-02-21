//
// Created by yewme on 21/2/2024.
//

#include "ParentTTable.h"

ParentTTable::ParentTTable() = default;
bool ParentTTable::addParentT(StmtNo before, StmtNo after) {
    if (isParentT(before, after)) {
        return false;
    }
    return twoSideMapMM.insert(before, after);
}

//bool ParentTTable::isParentT(StmtNo before, StmtNo after) {
//    if (!twoSideMapMM.containsKey(before)
//        || !twoSideMapMM.containsValue(after)) {
//        return false;
//    }
//    return twoSideMapMM.getKeys(after).value() == before;
//}

bool ParentTTable::isParentT(StmtNo before, StmtNo after) {
    if (!twoSideMapMM.containsKey(after)) {
        return false;  // The 'after' statement is not present in the map
    }

    // Check if 'before' is in the keys associated with 'after'
    auto keys = twoSideMapMM.getKeys(after);
    if (keys.empty()) {
        return false;  // No keys associated with 'after'
    }

    // Check if 'before' is present in the keys associated with 'after'
    const std::vector<StmtNo>& keyValues = keys;
    return std::find(keyValues.begin(), keyValues.end(), before) != keyValues.end();
}

//bool ParentTTable::isParentT(StmtNo parent, StmtNo child) {
//    if (!twoSideMapMM.containsKey(parent)
//        || !twoSideMapMM.containsValue(child)) {
//        return false;
//    }
//    return twoSideMapMM.getKey(child).value() == parent;
//}

bool ParentTTable::hasParentT(StmtNo child) {
    return !twoSideMapMM.getKeys(child).empty();
}

bool ParentTTable::hasChildrenT(StmtNo parent) {
    return twoSideMapMM.containsKey(parent);
}

std::vector<StmtNo> ParentTTable::getParentsT(StmtNo child) {
    auto k = twoSideMapMM.getKeys(child);
    if (k.empty()) {
        return {-1};
    }
    return k;
}

std::vector<StmtNo> ParentTTable::getChildrenT(StmtNo parent) {
    return twoSideMapMM.getValues(parent);
}

int ParentTTable::getSize() const {
    return twoSideMapMM.size();
}
