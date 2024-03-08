#include "AffectsTable.h"

AffectsTable::AffectsTable() = default;
bool AffectsTable::addAffects(StmtNo affector, StmtNo affected) {
    return map.insert(affector, affected);
}

std::vector<StmtNo> AffectsTable::getAffector(StmtNo affected) {
    return map.getKeys(affected);
}

std::vector<StmtNo> AffectsTable::getAffected(StmtNo affector) {
    return map.getValues(affector);
}

vector<vector<Str>> AffectsTable::getAllAsStrings() {
    return map.getAllForAB();
}
