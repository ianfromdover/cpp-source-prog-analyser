#include "ParentTable.h"
ParentTable::ParentTable() = default;
bool ParentTable::addParent(StmtNo parent, StmtNo child) {
    return map.insert(parent, child);
}

vector<StmtNo> ParentTable::getParent(StmtNo child) {
    return map.getKeys(child);
}

vector<StmtNo> ParentTable::getChildren(StmtNo parent) {
    return map.getValues(parent);
}

Table ParentTable::getAllAsStrings() {
    return map.getAllForAB();
}
