#pragma once
#define SPA_PARENT_TABLE

#include "utilSpa/SpaTypes.h"
#include "utilSpa/TwoSideFwdVecMap.h"
#include "utilSpa/TwoSideFwdVecMap.cpp" // it doesn't work if i don't include this :(

class ParentTable {
    // TODO: Create Parent* table class using TwoSideDblVecMap
private:
    TwoSideFwdVecMap<StmtNo, StmtNo> twoSideMap;
public:
    ParentTable();
    bool addParent(StmtNo parent, StmtNo child);
    bool isParent(StmtNo parent, StmtNo child);
    // Returns true if the statement has a parent
    bool hasParent(StmtNo child);
    // Returns true if the statement has a child
    bool hasChildren(StmtNo parent);
    StmtNo getParent(StmtNo child);
    // Returns a list of children of the parent, unsorted // TODO: QPS ppl, do you want it to be sorted?
    vector<StmtNo> getChildren(StmtNo parent);
    int getSize() const;
};
