#include "ParentTable.h"
bool ParentTable::addParent(StmtNo parent, StmtNo child) {
    twoSideMap.insert(parent, child);
    return true; // TODO: return false if parent child pair already exists
}
bool ParentTable::hasParent(StmtNo child) {
    return twoSideMap.containsKey(child);
}
bool ParentTable::hasChild(StmtNo parent) {
    return twoSideMap.containsValue(parent);
}
bool ParentTable::isParent(StmtNo parent, StmtNo child) {
    return twoSideMap.getKey(child) == parent;
}
StmtNo ParentTable::getParent(StmtNo child) {
    return twoSideMap.getKey(child);
}
vector<StmtNo> const& ParentTable::getChildren(StmtNo parent) {
    return twoSideMap.getValues(parent);
}
vector<StmtNo> const& ParentTable::getSiblings(StmtNo child) {
    // if child is a value in twoSideMap,
    // return the vector of values associated with the key of child
    return twoSideMap.getValues(twoSideMap.getKey(child));
}
int ParentTable::getSize() const {
    return twoSideMap.size();
}
