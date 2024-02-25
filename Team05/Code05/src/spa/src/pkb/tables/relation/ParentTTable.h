//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_PARENTTTABLE_H
#define SPA_PARENTTTABLE_H


#include "utilSpa/IntColumn.h"

class ParentTTable {
private:
    std::pair<IntColumn, IntColumn> table;
public:
    ParentTTable() = default;

    bool addParentT(int parent, int child);
    std::pair<IntColumn, IntColumn> getParentT();
};


#endif //SPA_PARENTTTABLE_H
