//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_READTABLE_H
#define SPA_READTABLE_H


#include "utilSpa/IntColumn.h"
#include "utilSpa/StringColumn.h"

class ReadTable {
private:
    std::pair<IntColumn, StringColumn> table;
public:
    ReadTable() = default;

    bool addRead(int stmtNo, const std::string& name);

    std::pair<IntColumn, StringColumn> getRead();
};


#endif //SPA_READTABLE_H
