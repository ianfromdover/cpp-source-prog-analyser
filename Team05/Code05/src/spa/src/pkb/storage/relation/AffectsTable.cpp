#include "AffectsTable.h"

AffectsTable::AffectsTable() = default;
bool AffectsTable::addAffects(StmtNo before, StmtNo after) {
    return map.insert(before, after);
}

std::vector<StmtNo> AffectsTable::getAffector(StmtNo after) {
    return map.getKeys(after);
}

std::vector<StmtNo> AffectsTable::getAffected(StmtNo before) {
    return map.getValues(before);
}

Table AffectsTable::getAllAsStrings() {
    return map.getAllForAB();
}
