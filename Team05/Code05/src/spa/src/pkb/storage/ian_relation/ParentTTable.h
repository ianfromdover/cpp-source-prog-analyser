//
// Created by yewme on 21/2/2024.
//

#ifndef SPA_PARENTTTABLE_H
#define SPA_PARENTTTABLE_H

#include "utilSpa/SpaTypes.h"
#include "pkb/storage/base/TwoSideMap.hpp"


class ParentTTable {
private:
    TwoSideMap<StmtNo, StmtNo> twoSideMapMM;
public:
    ParentTTable();
    // Adds a follows relationship to the follows table, returns true if the relationship is added
    bool addParentT(StmtNo parent, StmtNo child);
    bool isParentT(StmtNo parent, StmtNo child);
    // Returns true if the statement has a parent
    bool hasParentT(StmtNo child);
    // Returns true if the statement has a child
    bool hasChildrenT(StmtNo parent);
    std::vector<StmtNo> getParentsT(StmtNo child);
    // Returns a list of children of the parent, unsorted
    std::vector<StmtNo> getChildrenT(StmtNo parent);
    int getSize() const;
};


#endif //SPA_PARENTTTABLE_H
