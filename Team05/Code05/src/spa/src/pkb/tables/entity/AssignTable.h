//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_ASSIGNTABLE_H
#define SPA_ASSIGNTABLE_H


#include "utilSpa/IntColumn.h"
#include "utilSpa/StringColumn.h"

class AssignTable {
private:
    std::pair<IntColumn, StringColumn> table;
public:
    AssignTable() = default;

    bool addAssign(int stmtNo, const std::string &expr);

    std::pair<IntColumn, StringColumn> getAssign();
};



#endif //SPA_ASSIGNTABLE_H
