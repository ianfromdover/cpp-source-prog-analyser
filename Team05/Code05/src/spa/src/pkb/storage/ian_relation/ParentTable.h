#pragma once
#define SPA_PARENT_TABLE

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMapOneMany.hpp"

class ParentTable {
private:
    TwoSideMapOneMany<StmtNo, StmtNo> twoSideMapOM;
public:
    ParentTable();
    bool addParent(StmtNo parent, StmtNo child);
    bool isParent(StmtNo parent, StmtNo child);
    // Returns true if the statement has a parent
    bool hasParent(StmtNo child);
    // Returns true if the statement has a child
    bool hasChildren(StmtNo parent);
    StmtNo getParent(StmtNo child);
    // Returns a list of children of the parent, unsorted
    vector<StmtNo> getChildren(StmtNo parent);
    int getSize() const;
};
