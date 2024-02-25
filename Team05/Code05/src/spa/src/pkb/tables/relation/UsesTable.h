//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_USESTABLE_H
#define SPA_USESTABLE_H

#include "utilSpa/IntColumn.h"
#include "utilSpa/StringColumn.h"

class UsesTable {
private:
    std::pair<IntColumn, StringColumn> table;
public:
    UsesTable() = default;

    bool addUses(int stmtNo, const std::string& name);

    std::pair<IntColumn, StringColumn> getUses();
};


#endif //SPA_USESTABLE_H
