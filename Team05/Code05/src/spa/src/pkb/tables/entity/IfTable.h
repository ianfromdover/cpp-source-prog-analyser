//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_IFTABLE_H
#define SPA_IFTABLE_H


#include "utilSpa/IntColumn.h"
#include "utilSpa/StringColumn.h"

class IfTable {
private:
    std::pair<IntColumn, StringColumn> table;
public:
    IfTable() = default;

    bool addIf(int stmtNo, const std::string& name);

    std::pair<IntColumn, StringColumn> getIf();
};


#endif //SPA_IFTABLE_H
