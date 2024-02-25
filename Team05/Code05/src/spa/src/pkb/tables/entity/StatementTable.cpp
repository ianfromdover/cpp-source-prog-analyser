//
// Created by sjh_9 on 25/2/2024.
//

#include "StatementTable.h"

bool StatementTable::addStatement(int stmtNo, int stmtNoCopy) {
    table.first.addInt(stmtNo);
    table.second.addInt(stmtNoCopy);
    return true;
}

std::pair<IntColumn, IntColumn> StatementTable::getStatement() {
    return table;
}
