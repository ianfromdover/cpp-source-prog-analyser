#pragma once
#define SPA_PARENT_TABLE

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class ParentTable {
private:
    TwoSideMap<StmtNo, StmtNo> map;
public:
    ParentTable();
    bool addParent(StmtNo parent, StmtNo child);
    vector<StmtNo> getParent(StmtNo child);
    // Returns a list of children of the parent, unsorted
    vector<StmtNo> getChildren(StmtNo parent);
};
