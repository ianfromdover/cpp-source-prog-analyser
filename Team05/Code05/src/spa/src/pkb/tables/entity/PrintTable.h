//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_PRINTTABLE_H
#define SPA_PRINTTABLE_H

#include "utilSpa/IntColumn.h"
#include "utilSpa/StringColumn.h"

class PrintTable {
private:
    std::pair<IntColumn, StringColumn> table;
public:
    PrintTable() = default;

    bool addPrint(int stmtNo, const std::string& name);

    std::pair<IntColumn, StringColumn> getPrint();
};

#endif //SPA_PRINTTABLE_H
