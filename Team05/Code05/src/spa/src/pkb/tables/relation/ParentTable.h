//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_PARENTTABLE_H
#define SPA_PARENTTABLE_H

#include "utilSpa/IntColumn.h"

class ParentTable  {
private:
    std::pair<IntColumn, IntColumn> table;
public:
    ParentTable() = default;

    bool addParent(int parent, int child);
    std::pair<IntColumn, IntColumn> getParent();
};



#endif //SPA_PARENTTABLE_H
