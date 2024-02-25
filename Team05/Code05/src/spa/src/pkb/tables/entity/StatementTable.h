//
// Created by sjh_9 on 25/2/2024.
//

#ifndef SPA_STATEMENTTABLE_H
#define SPA_STATEMENTTABLE_H


#include "utilSpa/IntColumn.h"

class StatementTable  {
private:
    std::pair<IntColumn, IntColumn> table;
public:
    StatementTable() = default;

    bool addStatement(int stmtNo, int stmtNoCopy);
    std::pair<IntColumn, IntColumn> getStatement();
};


#endif //SPA_STATEMENTTABLE_H
