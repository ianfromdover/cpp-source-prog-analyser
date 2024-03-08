#pragma once
#define SPA_NEXTTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"


class AffectsTable {
private:
    TwoSideMap<StmtNo, StmtNo> map;
public:
    AffectsTable();
    // Adds an affects relationship, returns true if the relationship is added
    bool addAffects(StmtNo affector, StmtNo affected);
    // Returns a list of statements that affect this statement, unsorted. Returns an empty list if it does not exist
    std::vector<StmtNo> getAffector(StmtNo affected);
    // Returns a list of statements this one affects, unsorted. Returns an empty list if it does not exist
    std::vector<StmtNo> getAffected(StmtNo affector);
    // Gets a table with 2 columns, Affector | Affected
    std::vector<std::vector<Str>> getAllAsStrings();
};
