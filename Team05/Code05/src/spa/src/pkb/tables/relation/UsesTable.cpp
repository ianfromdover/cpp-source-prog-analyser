//
// Created by sjh_9 on 25/2/2024.
//

#include "UsesTable.h"

bool UsesTable::addUses(int stmtNo, const std::string& name) {
    table.first.addInt(stmtNo);
    table.second.addString(name);
    return true;
}

std::pair<IntColumn, StringColumn> UsesTable::getUses() {
    return table;
}