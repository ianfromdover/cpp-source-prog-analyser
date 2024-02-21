#include "ParentTable.h"
ParentTable::ParentTable() = default;
bool ParentTable::addParent(StmtNo parent, StmtNo child) {
    if (isParent(parent, child)) {
        return false;
    }
    return twoSideMap.insert(parent, child);
}

bool ParentTable::isParent(StmtNo parent, StmtNo child) {
    if (!twoSideMap.containsKey(parent)
        || !twoSideMap.containsValue(child)) {
        return false;
    }
    return twoSideMap.getKey(child).value() == parent;
}

bool ParentTable::hasParent(StmtNo child) {
    return twoSideMap.getKey(child).has_value();
}

bool ParentTable::hasChildren(StmtNo parent) {
    return twoSideMap.containsKey(parent);
}

StmtNo ParentTable::getParent(StmtNo child) {
    auto k = twoSideMap.getKey(child);
    if (!k.has_value()) {
        return -1;
    }
    return k.value();
}

vector<StmtNo> ParentTable::getChildren(StmtNo parent) {
    return twoSideMap.getValues(parent);
}

int ParentTable::getSize() const {
    return twoSideMap.size();
}
