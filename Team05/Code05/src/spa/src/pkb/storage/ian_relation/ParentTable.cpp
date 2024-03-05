#include "ParentTable.h"
ParentTable::ParentTable() = default;
bool ParentTable::addParent(StmtNo parent, StmtNo child) {
    if (isParent(parent, child)) {
        return false;
    }
    return twoSideMapOM.insert(parent, child);
}

bool ParentTable::isParent(StmtNo parent, StmtNo child) {
    if (!twoSideMapOM.containsKey(parent)
        || !twoSideMapOM.containsValue(child)) {
        return false;
    }
    return twoSideMapOM.getKey(child).value() == parent;
}

bool ParentTable::hasParent(StmtNo child) {
    return twoSideMapOM.getKey(child).has_value();
}

bool ParentTable::hasChildren(StmtNo parent) {
    return twoSideMapOM.containsKey(parent);
}

StmtNo ParentTable::getParent(StmtNo child) {
    auto k = twoSideMapOM.getKey(child);
    if (!k.has_value()) {
        return -1;
    }
    return k.value();
}

vector<StmtNo> ParentTable::getChildren(StmtNo parent) {
    return twoSideMapOM.getValues(parent);
}

int ParentTable::getSize() const {
    return twoSideMapOM.size();
}
