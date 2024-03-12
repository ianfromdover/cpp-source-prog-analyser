#pragma once
#define SPA_PARENT_TABLE

#include "common/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"

class ParentTable {
private:
    TwoSideMap<StmtNo, StmtNo> map;
public:
    ParentTable();
    // Adds a parent relationship, returns false if it already exists
    bool addParent(StmtNo parent, StmtNo child);
    // Returns a list of parents of the child, unsorted. If the child has no parent, returns an empty list
    vector<StmtNo> getParent(StmtNo child);
    // Returns a list of children of the parent, unsorted. If the parent has no children, returns an empty list
    vector<StmtNo> getChildren(StmtNo parent);
    // Gets a table with 2 columns, Parent | Child
    vector<vector<Str>> getAllAsStrings();
};
