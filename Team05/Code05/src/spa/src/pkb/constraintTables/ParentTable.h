#pragma once
#define SPA_PARENT_TABLE

#include "utilSpa/spaTypes.h"
#include "utilSpa/TwoSideFwdVecMap.h"

using namespace std;

class ParentTable {
    // TODO: Create Parent* table class using TwoSideDblVecMap
private:
    TwoSideFwdVecMap<StmtNo, StmtNo> twoSideMap;
public:
    ParentTable() = default;
    bool addParent(StmtNo parent, StmtNo child);
    bool hasParent(StmtNo child);
    bool hasChild(StmtNo parent);
    bool isParent(StmtNo parent, StmtNo child);
    StmtNo getParent(StmtNo child);
    vector<StmtNo> const& getChildren(StmtNo parent);
    vector<StmtNo> const& getSiblings(StmtNo child);
    int getSize() const;
};
