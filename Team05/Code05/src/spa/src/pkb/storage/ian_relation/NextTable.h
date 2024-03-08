#pragma once
#define SPA_NEXTTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"


class NextTable {
private:
    TwoSideMap<StmtNo, StmtNo> map;
public:
    NextTable();
    // Adds a next relationship, returns true if the relationship is added
    bool addNext(StmtNo before, StmtNo after);
    // Returns a list of statements that come before, unsorted. Returns an empty list if it does not exist
    std::vector<StmtNo> getBefore(StmtNo after);
    // Returns a list of statements that come after, unsorted. Returns an empty list if it does not exist
    std::vector<StmtNo> getAfter(StmtNo before);
    // Gets a table with 2 columns, Before | After
    std::vector<std::vector<Str>> getAllAsStrings();
};
