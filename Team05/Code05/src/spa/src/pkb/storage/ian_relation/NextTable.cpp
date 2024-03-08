#include "NextTable.h"

NextTable::NextTable() = default;
bool NextTable::addNext(StmtNo before, StmtNo after) {
    return map.insert(before, after);
}

std::vector<StmtNo> NextTable::getBefore(StmtNo after) {
    return map.getKeys(after);
}

std::vector<StmtNo> NextTable::getAfter(StmtNo before) {
    return map.getValues(before);
}

vector<vector<Str>> NextTable::getAllAsStrings() {
    return map.getAllForAB();
}
