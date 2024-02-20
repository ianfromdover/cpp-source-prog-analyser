#include "ParentTable.h"
ParentTable::ParentTable() {}
bool ParentTable::addParent(StmtNo parent, StmtNo child) {
    if (isParent(parent, child)) {
        return false;
    }
    return twoSideMap.insert(parent, child);
}

bool ParentTable::isParent(StmtNo parent, StmtNo child) {
    if (twoSideMap.getKey(child) == std::nullopt) {
        return false;
    }
    return twoSideMap.getKey(child).value() == parent;
}

bool ParentTable::hasParent(StmtNo child) {
    return twoSideMap.getKey(child) != std::nullopt;
}

bool ParentTable::hasChildren(StmtNo parent) {
    return twoSideMap.containsKey(parent);
}

StmtNo ParentTable::getParent(StmtNo child) {
    if (twoSideMap.getKey(child) == std::nullopt) {
        return -1;
    }
    return twoSideMap.getKey(child).value();
}

vector<StmtNo> ParentTable::getChildren(StmtNo parent) {
    return twoSideMap.getValues(parent);
}

int ParentTable::getSize() const {
    return twoSideMap.size();
}
