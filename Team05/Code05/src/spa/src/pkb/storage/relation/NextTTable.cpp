#include "NextTTable.h"

NextTTable::NextTTable() = default;
bool NextTTable::addNextT(StmtNo before, StmtNo after) {
    return map.insert(before, after);
}

std::vector<StmtNo> NextTTable::getBefore(StmtNo after) {
    return map.getKeys(after);
}

std::vector<StmtNo> NextTTable::getAfter(StmtNo before) {
    return map.getValues(before);
}

Table NextTTable::getAllAsStrings() {
    return map.getAllForAB();
}
