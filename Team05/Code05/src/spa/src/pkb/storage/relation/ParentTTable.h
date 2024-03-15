#pragma once
#define SPA_PARENTTTABLE_H

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"


class ParentTTable {
private:
    TwoSideMap<StmtNo, StmtNo> map;
public:
    ParentTTable();
    // Adds a follows relationship to the follows table, returns true if the relationship is added
    bool addParentT(StmtNo parent, StmtNo child);
    // Returns a list of parents of the child, unsorted. Returns an empty list if the child does not exist
    std::vector<StmtNo> getParentsT(StmtNo child);
    // Returns a list of children of the parent, unsorted. Returns an empty list if the parent does not exist
    std::vector<StmtNo> getChildrenT(StmtNo parent);
    // Gets a table with 2 columns, Parent* | Child*
    std::vector<std::vector<Str>> getAllAsStrings();
};
